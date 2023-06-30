#include<stdio.h>
int is_leap_year(int x);
int is_distinct(int x);

int main()
{
    int n;
    scanf("%d",&n);

//    int leap,distinct;
//
//    leap = is_leap_year(n);
//    is_distinct(23125);
//
//    if(leap==1)
//        printf("leap year \n");
//    else
//        printf("not leap year \n");

      if(is_leap_year(n)==1 && is_distinct(n)==1)
          printf("Leap Year/Beautiful \n");
      else
        printf("Not Leap Year/Ugly\n");



    return 0;
}

//leap year problem.2020, 2024, 2028,...,(2100 not leap year), 2104, 2108, 2112, 2116,..., (2200 not)
//2204, 2208, 2212,..., (2300 not), 2304, 2308, 2312,...,(2400 leap year), 2404, 2408....
//distinct digits means. protteke alada alada digits.

int is_leap_year(int x)//leap year function.
{
    if( (x%400 ==0) || (x%4 ==0 && x%100 !=0)  )
        return 1;
    else
        return 0;
}


int is_distinct(int x)//distinct function.
{
    int count_digit[10] = {0,0,0,0,0,0,0,0,0,0};
    int last_digit;

    while (x>0)
    {
        last_digit = x%10;
        count_digit[last_digit]++;
        x /= 10;
    }
    int i;
    for(i=0; i<10; i++)
    {
//        printf("%d-->%d\n",i,count_digit[i]);

        if(count_digit[i]>1)
            return 0;

    }
    return 1;
}
