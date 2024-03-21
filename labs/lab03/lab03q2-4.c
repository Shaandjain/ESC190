#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab3.h"

//Q2

void print_s1(student1 s) {
    printf("Name: %s\n", s.name);
    printf("Student Number: %s\n", s.student_number);
    printf("Year: %d\n", s.year);
}

//Q3
void set_default_name(student1 *p_s)
{
    strcpy(p_s->name, "Default Name");
    p_s -> year = 0;
}

void set_default_name_wrong(student1 s)
{
    strcpy(s.name, "Default Name");
}

//will not work, since it is a copy of the struct
//and not the actual struct


//Q4
void create_block1 (student1 **p_p_s, int n_students)
{
    *p_p_s = malloc(n_students * sizeof(student1));
}

//Q5
void set_name(student1 *p_s, const char *name) {
    if (strlen(name) > 199) {
        strncpy(p_s->name, name, 199);
        p_s->name[199] = '\0';
    } else {
        strcpy(p_s->name, name);
    }
}

//Q6
void destroy_block1(student1 *p_s) {
    free(p_s);
}


//Q7
typedef struct student2{
    char *name;
    char *student_number;
    int year;
} student2;


void create_block2(student2 **p_p_s, int num_students) {
    *p_p_s = malloc(num_students * sizeof(student2));
    for (int i = 0; i < num_students; i++) {
        (*p_p_s)[i].name = NULL;
        (*p_p_s)[i].student_number = NULL;
        (*p_p_s)[i].year = 0;
    }
}

//Q8
void set_name2(student2 *p_s, const char *name) {
    p_s->name = malloc(strlen(name) + 1);
    strcpy(p_s->name, name);
}

//Q9
void destroy_block2(student2 *p_s, int num_students) {
    for (int i = 0; i < num_students; i++) {
        free(p_s[i].name);
        free(p_s[i].student_number);
    }
    free(p_s);
}

//Q10
// aliases created which doesn't affect the original structure at that memory address

//Q11

//Q13

//Q14
void get_ints_from_file()



int main() {
    student1 s1 = {"Chase Graci", "000001", 6};
    print_s1(s1);

    set_default_name_wrong(s1);
    print_s1(s1);

    set_default_name(&s1);
    print_s1(s1);

    student1 *p_s;
    int n_students = 5;
    create_block1(&p_s, n_students);

    set_name(&p_s[0], "John Doe");
    printf("Name: %s\n", p_s[0].name);

    destroy_block1(p_s);

    char line[200];
    FILE *fp = fopen("random.txt", "r");
    while ((fgets(line, sizeof(line), fp)) != NULL)
    {
        printf("%s", line) ;//read in at most sizeof(line) characters
    }
    fclose(fp);

    return 0;


}



