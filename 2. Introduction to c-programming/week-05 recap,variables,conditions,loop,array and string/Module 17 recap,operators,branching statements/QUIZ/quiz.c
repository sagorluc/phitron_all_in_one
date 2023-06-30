#include<stdio.h>
int main()
{
  int a[2][3] = {{10,20,30},{40,50,60}}, i=1,j=0;

  a[i][j] = a[j][i];
  printf("%d %d",a[i][j],a[j+1][i+1]);

    return 0;
}
