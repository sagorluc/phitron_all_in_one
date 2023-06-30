#include<stdio.h>

struct student{
    double weight;//this is for memory optimization.double deta type int er cheye big ei jonno.
    int roll;
//    char name[50];
//    int age;


};


int main()
{

    struct student s[10];
    //printf("%d \n%d\n%d",sizeof(int),sizeof(double),sizeof(char));

//    s[0].roll = 11;
//    s[0].weight = 75.25;
//
//    s[1].roll = 16;
//    s[1].weight = 79.69;
//
//    s[2].roll = 19;
//    s[2].weight = 85.55;
    int i;
    for(i=0; i<10; i++)
    {
        s[i].roll = 11 + i;
        s[i].weight = 75.25 + i * 3;

    }
    for(i=0; i<10; i++)
    {
        printf("%d %lf\n",s[i].roll,s[i].weight );


    }




    return 0;
}
