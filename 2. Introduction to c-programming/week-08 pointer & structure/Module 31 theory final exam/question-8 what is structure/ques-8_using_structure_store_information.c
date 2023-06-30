#include<stdio.h>
struct student{

    double marks;
    char name[50];
    int number;

};
int main()
{
    struct student s;
    printf("Enter Information:\nEnter name: ");
    scanf("%s",&s.name);

    printf("Enter roll number: ");
    scanf("\n%d",&s.number);

    printf("Enter marks: ");
    scanf("\n%lf",&s.marks);


    printf("\nDisplaying Information: \nName: %s \nRoll number: %d \nMarks: %0.3lf\n",s.name,s.number,s.marks);

    return 0;
}

//what is structure.
//
//structure creates a data type that can be used to group items of possibly different types into a single type is taht called structure.
//it's keywod struct.and the syntax is struct example{detatypes m1; detatypes m2;...};
//
//How many ways to access structure members? Explain with example.
//



