#include<stdio.h>

struct student{

    int roll;
    char name[50];
    double marks;


};
void print_student(int n, struct student s)
{
    printf("\n\nInfornation of student %d",n);
    printf("\nRoll-->%d\nName-->%s\nMarks-->%lf\n",s.roll,s.name,s.marks);


}

int main()
{
    struct student cls[5];

    int i;
    for(i=0; i<5; i++)
    {

       scanf("%d",&cls[i].roll);
       scanf("%s",cls[i].name);
       scanf("%lf",&cls[i].marks);
    }
    for(i=0; i<5; i++)
    {
//       printf("\n\nInfornation of student %d",i);
//       printf("\nRoll-->%d\nName-->%s\nMarks-->%lf\n",cls[i].roll,cls[i].name,cls[i].marks);

        double summ = 0;


        if(cls[i].roll % 2 == 0)//jader marks even tather number er summ kora hocce.
        {
            summ += cls[i].marks;//
         // print_student(i,cls[i]);
        }

        printf("total marks %lf\n",summ);
    }

}

/*
12
sagor

45
saiful
25.66

75
ismail
56.54

36
jakir
45.66

85
parvez
85.66
*/
