#include<stdio.h>
int main()
{
    int n,i,a,b,c;
    scanf("%d",&n);
    int solved =0 ;
    for(i=0;i<n;i++)
    {
     scanf("%d %d %d",&a,&b,&c);
     if (a+b+c>=2)
          solved++;

    }
    printf("%d\n",solved);


    return 0;
}
