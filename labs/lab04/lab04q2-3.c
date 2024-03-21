#include <stdlib.h>
#include <stdio.h>


double my_atof(const char *str)
{
    int i = 0;
    
    // Find the position of the '=' character
    while(str[i] != '='){
        i++;
    }
    i++;    
    double result = 0;
    int sign = 1;
    
    // Check if there is a negative sign
    if(str[i] == '-'){
        sign = -1;
        i++;
    }   
    
    // Convert the integer part of the number
    while(str[i] != '.'){
        result = result * 10 + (str[i] - '0');
        i++;
    }
    i++; 
    double pow10 = 0.1;
    
    // Convert the fractional part of the number
    while(str[i] != '\n'){
        result += (str[i] - '0') * pow10;
        pow10 *= 0.1;
        i++;
    }
    return result * sign;
}

double parse_consts(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error: file not found");
        return 0;
    }
    char line[100];
    double sum = 0;
    while(fgets(line, sizeof(line), fp) ){
        printf("%s\n", line);
        double value = my_atof(line);
        sum += value;
    }
    fclose(fp);
    return sum;
}

//q3

typedef struct student2 {
    char *name;
    int age;
} student2;

void change_name(student2 *p_s, char *new_name)
{
    p_s->name = new_name;
}

int main()
{
    double sum = parse_consts("text.txt");
    printf("Sum of constants: %.10f\n", sum);

    student2 s;
    s.name = "Shaan";
    s.age = 20;
    change_name(&s, "Yiyi");
    printf("%s\n", s.name);
    return 0;
}
