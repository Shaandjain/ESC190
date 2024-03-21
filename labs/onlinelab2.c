#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Solution for Q1
int a = 42;

//Solution for Q2
int *p_a = &a;

//Solution for Q3
*p_a = 43;

//Solution for Q4
int b = 44;
p_a = &b;

//Solution for Q5
void change_a(int *p_int) {
    *p_int = 45;
}


//Solution for Q8
int **p_p_a;

//Solution for Q9

p_p_a = &p_a;

//Solution for Q10

void change_int_2(int **p_p_int) {
    **p_p_int = 46;
}

//Solution for Q11

void change_int_ptr(int **p_p_int) {
    *p_p_int = malloc(sizeof(int));
}

//Solution for Q15

int arr[3] = {5, 6, 7}; 

//Solution for Q16

void change_arr(int *p_arr) {
    p_arr[2] = 8;
}


//Solution for Q21

typedef struct student{
    char name[1000];
    int age;
}student;




//Solution for Q27
void change_name(student *p_s) {
    strcpy(p_s->name, "Jenny");
}

//Solution for Q28
void change_age(student *p_s) {
    p_s->age = 20;
}

//Solution for Q31
student arr_s[5];




int main() {
    //Solution for Q6
    change_int(&a);

    //Solution for Q7
    change_int(p_a);

    //Solution for Q12

    change_int2(&p_a); change_int2(p_p_a);

    //Solution for Q13

    change_int_ptr(&p_a); change_int_2(p_p_a);

    //Solution for Q14
    change_int_ptr(p_p_a);

    //Solution for Q17
    change_arr(arr);

    //Solution for Q18
    int *p_block = malloc(3 * sizeof(int)); 
    change_arr(p_block);

    //Solution for Q19
    change_int(p_block);

    //Solution for Q20
    change_int_ptr(&p_block);

    //Solution for Q21 extended

    student s = {"Shaan", 20};

    //Solution for Q22
    strcpy(s.name, "Jennifer");

    //Solution for Q23
    s.age = 21;

    //Solution for Q24
    student *p_s = &s;

    //Solution for Q25
    strcpy(p_s->name, "Jenny");  

    //Solution for Q26
    p_s->age = 20;


    //Solution for Q29
    change_name(p_s);

    //Solution for Q30
    change_age(&s);


    //Solution for Q32
    change_name(&arr_s[2]);
    change_age(&arr_s[2]);

    return 0;
}


int a = 42;

int *p_a = &a;

*p_a = 43;

int b = 44;
p_a = &b;

