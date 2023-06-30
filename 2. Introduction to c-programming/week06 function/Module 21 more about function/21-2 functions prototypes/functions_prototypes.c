#include<stdio.h>
float max_of_three(float x,float y,float z);//this is prototypes.

int main()
{
    float a,b,c,m,i;

    for(i=0; i<5; i++)
    {
        scanf("%f %f %f",&a,&b,&c);
        m = max_of_three(a,b,c);

        printf("The maximum value is %f\n",m);

    }
    return 0;
}

float max_of_three(float x,float y,float z)
{
    if(x>y && x<y)
        return x;
    else if(y>z && y<z)
        return y;
    else
        return z;
}
