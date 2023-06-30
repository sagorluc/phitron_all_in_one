#include<stdio.h>
#include<math.h>
int seven_present(int x);//this is function prototypes.
int digit_sum(int y);//this is function prototypes.nested functions.
int last_digit_prime(int z);//this is function prototypes.nested function.

int main()
{
    int n;
    scanf("%d",&n);
    int my_number;
    if(seven_present(n)==1 && digit_sum(n) >10 && last_digit_prime(n))
    {
       printf("YES! This is My number's",my_number);
    }
    else
        printf("NO\n");


    return 0;
}

//start function here.

int seven_present(int x)//seven_present function.
{
    while(x>0)
    {
      if(x%10 == 7)
      return 1;

      x /= 10;
    }
    return 0;

}

int digit_sum(int y)//digit_sum functon.
{
  int sum=0;
  while(y>0)
  {
    sum += (y%10);
    y /= 10;

  }
  return sum;
}

int last_digit_prime(int z)//last_digit_prime function.
{
    int ld = z%10;

    if(ld==2 || ld==3 || ld==5 || ld==7)
        return 1;
    else
        return 0;
}
