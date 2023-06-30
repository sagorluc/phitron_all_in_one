
#include<stdio.h>

int main()
{
    //Consider an algorithm that takes as input a positive integer n. If n is even, the algorithm divides it by two, and if n is odd,
    //the algorithm multiplies it by three and adds one. The algorithm repeats this, until n is one. For example, the sequence for n=3 is as follows:
    //3→10→5→16→8→4→2→1

    int n,dev,dev1;
    scanf("%d",&n);

    if (n % 2 == 0)
    {
      dev = n / 2;
      printf("%d",dev);
    }else
    {
        dev1 = n * 3 + 1 ;
        printf("%d",dev1);

    }



    return 0;
}
