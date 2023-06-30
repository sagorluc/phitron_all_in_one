#include<stdio.h>
void add_tow_nums();

int g = 7; //this is global variable.it can use any of function.

int main()
{

    add_tow_nums();
    printf("Printing in main function %d\n",g);//global variable.

    return 0;
}

void add_tow_nums()
{
    //this variables will not work out of this function.
    int a,b; //this is local variable scoope.
    int sum;//local variable.


    scanf("%d%d",&a,&b);
    sum = a+b;
    printf("%d\n",sum);
    printf("Printing in add_tow_nums function %d\n",g*2);//global variable.

    g = g*2;
}
