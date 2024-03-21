#include "seamcarving.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "c_img.c"

//compute dual gradient energy of an image
void calc_energy(struct rgb_img *im, struct rgb_img **grad){
    
    //create a new image to store the gradient energy
    int height = im->height;
    int width = im->width;
    create_img(grad, height, width);

    for (int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){

            int j1 = (j + 1) % width;
            int j2 = (j - 1 + width) % width;
            int i1 = (i + 1) % height;
            int i2 = (i - 1 + height) % height;

            //red green blue values for the pixel and its neighbors
            int Rx = get_pixel(im, i, j1, 0) - get_pixel(im, i, j2, 0);
            int Gx = get_pixel(im, i, j1, 1) - get_pixel(im, i, j2, 1);
            int Bx = get_pixel(im, i, j1, 2) - get_pixel(im, i, j2, 2);
            int Ry = get_pixel(im, i1, j, 0) - get_pixel(im, i2, j, 0);
            int Gy = get_pixel(im, i1, j, 1) - get_pixel(im, i2, j, 1);
            int By = get_pixel(im, i1, j, 2) - get_pixel(im, i2, j, 2);
            
            //calculate the energy of the pixel
            int delta_x_squared = Rx * Rx + Gx * Gx + Bx * Bx;
            int delta_y_squared = Ry * Ry + Gy * Gy + By * By;
            int energy = sqrt(delta_x_squared + delta_y_squared);

            set_pixel(*grad, i, j, energy/10, energy/10, energy/10);
        }
    }
}
void dynamic_seam(struct rgb_img *grad, double **best_arr){
    *best_arr = (double *)malloc(grad->width *grad->height * sizeof(double));

    int height = grad->height;
    int width = grad->width;

    //initialize the first row of the best_arr
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                if (i == 0){
                    // If first row, set the value to the energy of the pixel
                    (*best_arr)[i * width + j] = get_pixel(grad, i, j, 0);
                }
                else if (j == 0){
                    // If first column, set the value to the energy of the pixel plus the min from prev adjacent pixel
                    (*best_arr)[i * width + j] = get_pixel(grad, i, j, 0) + fmin((*best_arr)[(i - 1) * width + j], (*best_arr)[(i - 1) * width + (j + 1)]);
                }
                else if (j == (width - 1)){
                    // If last column, set the value to the energy of the pixel plus the min from prev adjacent pixel
                    (*best_arr)[i * width + j] = get_pixel(grad, i, j, 0) + fmin((*best_arr)[(i - 1) * width + j], (*best_arr)[(i - 1) * width + (j - 1)]);
                }
                else{
                    // For any other pixel, set the value to the energy of the pixel + min value from the prev row's adjacent pixels
                    (*best_arr)[i * width + j] = get_pixel(grad, i, j, 0) + fmin((*best_arr)[(i - 1) * width + j], fmin((*best_arr)[(i - 1) * width + (j - 1)], (*best_arr)[(i - 1) * width + (j + 1)]));
                }
            }
        }
}
void print_best_arr(double *best_arr, int height, int width){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            printf("%f ", best_arr[i * width + j]);
        }
        printf("\n");
    }
}
void print_calc_energy(struct rgb_img *grad){
    for (int i = 0; i < grad->height; i++){
        for (int j = 0; j < grad->width; j++){
            printf("%d ", get_pixel(grad, i, j, 0));
        }
        printf("\n");
    }
}
void recover_path(double *best, int height, int width, int **path){
    //initialize the path array
    *path = (int *)malloc(height * sizeof(int));

    //find the minimum value in the last row of best_arr
    double min = best[(height - 1) * width];
    int min_index = 0;
    for (int i = 1; i < width; i++){
        if (best[(height - 1) * width + i] < min){
            min = best[(height - 1) * width + i];
            min_index = i;
        }
    }
    (*path)[height - 1] = min_index;

    //backtrack to find the path
    for (int i = (height - 2); i >= 0; i--){
        if (min_index == 0){
            if (best[i * width + min_index] < best[i * width + (min_index + 1)]){
                min_index = min_index;
            }
            else{
                min_index = min_index + 1;
            }
        }
        else if (min_index == (width - 1)){
            if (best[i * width + min_index] < best[i * width + (min_index - 1)]){
                min_index = min_index;
            }
            else{
                min_index = min_index - 1;
            }
        }
        else{
            if (best[i * width + min_index] < best[i * width + (min_index - 1)] && best[i * width + min_index] < best[i * width + (min_index + 1)]){
                min_index = min_index;
            }
            else if (best[i * width + (min_index - 1)] < best[i * width + min_index] && best[i * width + (min_index - 1)] < best[i * width + (min_index + 1)]){
                min_index = min_index - 1;
            }
            else{
                min_index = min_index + 1;
            }
        }
        (*path)[i] = min_index;
    }
}
void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path) {
    int height = src->height;
    int width = src->width -1;
    create_img(dest, height, width);

    for (int i = 0; i < height; i++){
        int k = 0;
        for (int j = 0; j < width; j++){
            if (j != path[i]){
                set_pixel(*dest, i, k, get_pixel(src, i, j, 0), get_pixel(src, i, j, 1), get_pixel(src, i, j, 2));
                k++;
            }
        }
    }
}

int main() {
    struct rgb_img *im;
    struct rgb_img *cur_im;
    struct rgb_img *grad;
    double *best;
    int *path;

    read_in_img(&im, "HJoceanSmall.bin");
    
    for(int i = 0; i < 450; i++){
        printf("i = %d\n", i);
        calc_energy(im,  &grad);
        dynamic_seam(grad, &best);
        // print_best_arr(best, grad->height, grad->width);
        // print_calc_energy(grad);
        recover_path(best, grad->height, grad->width, &path);
        remove_seam(im, &cur_im, path);

        char filename[200];
        sprintf(filename, "img%d.bin", i);
        write_img(cur_im, filename);


        destroy_image(im);
        destroy_image(grad);
        free(best);
        free(path);
        im = cur_im;
    }
    
    destroy_image(im);
}