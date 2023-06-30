#include<stdio.h>
int sum_of_digits(int x);
int is_prime(int x);

int main()
{
    int n;
    scanf("%d",&n);

//    int sod;
//    sod = sum_of_digits(n);

    if(is_prime(sum_of_digits(n))==1)
        printf("This is my number's");
    else
        printf("NO\n");


    return 0;
}

//sum of digits
//123-> 1+2+3 = 6; not prime
//
//sum of digits is prime
//1231-> 1+2+3+1 = 7; prime

int sum_of_digits(int x)
{

    int summ = 0;
    while(x>0)
    {
        summ += (x%10);
        x /=10;

    }
    return summ;
}

int is_prime(int x)
{
  int i;
  for(i=2; i<x; i++)
  {
      if(x%i==0)
        return 0;
  }
  return 1;
}

