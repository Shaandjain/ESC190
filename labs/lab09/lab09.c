#include "c_img.c"
#include <stdio.h>


void change_brightness(struct rgb_img *im, struct rgb_img **dest, int factor){
    create_img(dest, im->height, im->width);

    for(int i = 0; i < im->height; i++){
        for(int j = 0; j < im->width; j++){


            
            int r = get_pixel(im, i, j, 0);
            int g = get_pixel(im, i, j, 1);
            int b = get_pixel(im, i, j, 2);

            r *= factor;
            g *= factor; 
            b *= factor;

            //if the red/green/blue pixels are over 255, 
            //set them down to 255
            if (r > 255){
                r = 255;
            }
            if (g > 255){
                g = 255;
            }
            if (b > 255){
                b = 255;
            }

            set_pixel(*dest, i, j, (uint8_t)r, (uint8_t)g, (uint8_t)b );
        }
    }
}


int main (){
    struct rgb_img *im; 
    struct rgb_img *cur_img; 

    // Read the image from file and store it in im
    read_in_img(&im, "cannon.bin"); 
    
    // Loop to change brightness and write modified images to files
    for (int i = 0; i < 5; i++){
        // Change the brightness of the image im and store the modified image in cur_img
        change_brightness(im, &cur_img, i); 
        
        char filename[200];
        // Create a filename for the modified image based on the iteration number
        sprintf(filename, "img%d.bin", i); 
        write_img(cur_img, filename); 

        // Free the memory allocated for the modified image
        destroy_image(cur_img); 
    }
    // Free the memory allocated for the original image
    destroy_image(im); 
    
    return 0;
}
