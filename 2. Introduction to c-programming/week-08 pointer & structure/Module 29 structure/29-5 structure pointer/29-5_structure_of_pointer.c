#include<stdio.h>

struct student{
    double weight;//this is for memory optimization.double deta type int er cheye big ei jonno.
    int roll;
//    char name[50];
    int age;


};

int main()
{
    struct student s = {.roll = 12, .weight = 58.2, .age = 24};
    //struct student s2 = {.roll = 15, .weight = 85.22, .age = 26};
    struct student* sp;

    sp = &s;
//    printf("%d\n",sizeof(struct student));
//    printf("%p\n%p\n",sp,&s2);

    printf("%d\n%lf\n%d",sp->roll, sp->weight, sp->age);//this is print of structure pointer formula.

    return 0;
}
