#include<stdio.h>
int main()
{
    unsigned int a=17; //declaration.unsigned for big memory.
    int b=7; //initialization.
    float c=3.3;
    double d=8.6566578;
    char e='a';
    int octal=1765452;
    int hex=167345;
    double f=8.99231;
    double g=8.97238;

    int n=10;
    double x=75.50;

    printf("this is unsigned int->%u\n",a);
    printf("this is decimal int->%d\n",b);
    printf("this is float->%f\n",c);
    printf("this is double->%lf\n",d);
    printf("this is charater->%c\n",e);
    printf("this is octal->%o\n",octal);
    printf("this is hexadecimal->%x\n",hex);
    printf("this is double->%0.8lf\n",f);//double can print highest 0.6 digit.
    printf("this is double->%0.5lf\n",g);
    printf("this is double->%0.4lf\n",g);
    printf("this is double->%0.3lf\n",g);
    printf("this is double->%0.2lf\n",g);
    printf("this is double->%0.1lf\n",g);
    printf("this is double-> onek kotha %lf\n",g);

    printf("sagor bought %d mangos %0.2lf tk. ",n,x);


    return 0;
}
