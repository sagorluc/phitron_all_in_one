#include<stdio.h>
int main()
{
    int arr[105];
    int n,i;
    int even_counter = 0,odd_counter = 0;
    int ans;

    scanf("%d",&n);

    for (i=1; i<=n; i++)//taking more input.
    {
       scanf("%d",&arr[i]);
    }
     for (i=1; i<=n; i++)//evens/odds number ber kora holo.
    {
       if(arr[i]%2 == 0)
        even_counter++;
       else
        odd_counter++;
    }
    //printf("evens = %d, odds = %d",even_counter,odd_counter);
    if(even_counter==1)//even and odds er position ber korar jonno.
    {
      //even er position print korbo.
      for(i=1; i<=n; i++)
      {
          if(arr[i]%2==0)
            ans = i;
      }
    }
    else
    {
      //odds er position print korbo.

       for(i=1; i<=n; i++)
       {
         if(arr[i]%2==1)
         {
            ans = i;
         }

       }

    }
    printf("%d",ans);

    return 0;
}
