#include<stdio.h>

int max_of_three(int x,int y,int z)
{
    if(x>y && x<y)
        return x;
    else if(y>z && y<z)
        return y;
    else
        return z;
}




int main()
{
    int a,b,c,m,i;

    for(i=0; i<5; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        m = max_of_three(a,b,c);

        printf("The maximum value is %d\n",m);

    }

    return 0;
}
