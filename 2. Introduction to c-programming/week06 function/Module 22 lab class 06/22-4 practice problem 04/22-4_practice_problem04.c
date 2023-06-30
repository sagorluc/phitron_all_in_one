#include<stdio.h>
int add_them(int x,int y);//this is function prototypes.

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);

    int sum = add_them(a,b);

    printf("%d",sum);


    return 0;
}

int add_them(int x,int y)
{
    return x+y;
}
