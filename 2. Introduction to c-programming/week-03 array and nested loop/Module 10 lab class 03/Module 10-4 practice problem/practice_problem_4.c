#include<stdio.h>

int main()
{
  int n,k,i;
  scanf("%d %d",&n,&k);//input neoya hoyece.

  int scor[55];
  for(i=1; i<=n; i++)//sober input neoya hoyece array er maddhome.
  {
     scanf("%d",&scor[i]);
  }
  int ans=0;
  for(i=1; i<=n; i++)//
  {
    if (scor[i]>=scor[k] && scor[i]>0)

        ans++;
  }
    printf("%d",ans);


    return 0;
}
