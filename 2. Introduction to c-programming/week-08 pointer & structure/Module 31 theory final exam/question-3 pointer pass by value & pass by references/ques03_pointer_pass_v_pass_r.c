#include<stdio.h>
void pass_value(int v1, int v2);
void pass_ref(int* p, int* q);
int main()
{
    int a=5,b=10;

    pass_value(a,b);
    printf("pass by value : a = %d, b = %d\n",a,b);

    pass_ref(&a,&b);
    printf("pass by ref : a = %d, b = %d\n",a,b);

    return 0;
}

void pass_value(int v1, int v2)
{
    int val;

    val = v1;
    v1 = v2;
    v2 = val;
}

void pass_ref(int* p, int* q)
{
    int ref;

    ref = *p;
    *p = *q;
    *q = ref;
}

