#include<stdio.h>

//complex number formula.
//x + iy

//complex number multiply formula.
//(x+yi)(u+vi) = (xu-yu)+(xv+yu)i


struct comp{

    double real;
    double img;
};

void print_comp(struct comp c)
{
    printf("%0.3lf + %0.3lfi",c.real,c.img);
}

struct comp add_comp(struct comp a, struct comp b)
{
    struct comp ans;
    ans.real = a.real + b.real;
    ans.img = a.img + b.img;

    return ans;
}

struct comp comp_multiply(struct comp a, struct comp b)
{
    struct comp ans;
    ans.real = a.real*b.real - a.img*b.img;
    ans.img = a.real*b.img + b.real*a.img;

    return ans;
}

int main()
{
    struct comp c1 = {5.9, 3.1};
    struct comp c2 = {-2.5, 3.7};

    print_comp(add_comp(c1,c2));
    printf("\n\n");
    print_comp(comp_multiply(c1,c2));


    return 0;
}

