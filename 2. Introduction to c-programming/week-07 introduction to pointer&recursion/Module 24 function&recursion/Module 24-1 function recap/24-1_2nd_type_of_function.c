#include<stdio.h>
//function er kace kicu pathbo nah but function theke kicu recived korbo.

int take_redius();


int main()
{
    int r;
    r = take_redius();


    calculate_area(r);

    return 0;
}

int take_redius()
{
    int r;
    printf("pleace enter the redius of a circle:\n ");
    scanf("%d",&r);
    return r;
}

calculate_area(int redius)
{
     int r;
     float area = 3.14159*r*r;
     printf("Area of the circle is %f\n",area);
}
