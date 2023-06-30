
#include<stdio.h>

int main()
{
  int n;
  int ara[100];
  int i;

  scanf("%d",&n);

  for (i=0; i<n; i++)
  {
    scanf("%d",&ara[i]);

  }
  int e_c = 0;
  int o_c = 0;

  for(i=0; i<n; i++)
  {

  if(ara[i] % 2 == 1)
  {

      o_c++;
  }else
  {


      e_c++;
  }
  }
  printf("total number of even %d\n",e_c);
  printf("total number of odds %d",o_c);




    return 0;
}
