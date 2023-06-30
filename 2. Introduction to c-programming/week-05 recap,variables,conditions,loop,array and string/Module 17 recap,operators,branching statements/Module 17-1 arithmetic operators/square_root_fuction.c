#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,s;
    printf("Enter the three side of a triangle ");
    scanf("%f %f %f",&a,&b,&c);

    s = (a+b+c)/2.0;
    printf("half perimeter ->%f\n",s);

    double area,farea;

    area=sqrt(s*(s-a)*(s-b)*(s-c));

    farea = sqrt(area);
    printf("area -> %f",farea);



    return 0;
}
