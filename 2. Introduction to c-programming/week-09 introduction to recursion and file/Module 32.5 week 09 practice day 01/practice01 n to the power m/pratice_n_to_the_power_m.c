#include<stdio.h>
#include<math.h>
int power(int x, int y)
{
    if(y==0)
        return 1;
    if(y > 0)
        return x*pow(x,y-1);

}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    int ans = power(n,m);
    printf("N to the power M = %d\n",ans);

    return 0;
}
