#include<stdio.h>
#include<string.h>

struct student{         //structure define for deferent deferent deta types.

    int roll;
    char name[50];
    int age;
    float weight;

};

int main()
{

    struct student s3;
    struct student s1 = {12,"sagor ahmed", 24, 75.5};//same things as below.d
    struct student s2 = {15,"jakir uzzaman", 25, 71.5};//same things as below.

//    s.roll = 12;
      strcpy(s2.name,"saiful islam");//declaration of string array.
      s3 = s2;
//    s.age = 24;
//    s.weight = 75.5;
    printf("student 1 info\n");
    printf("roll = %d\nneme = %s\nage = %d\nweight = %f\n\n",s1.roll,s1.name,s1.age,s1.weight);
    printf("student 2 info\n");
    printf("roll = %d\nneme = %s\nage = %d\nweight = %f\n",s2.roll,s2.name,s2.age,s2.weight);

    return 0;
}
