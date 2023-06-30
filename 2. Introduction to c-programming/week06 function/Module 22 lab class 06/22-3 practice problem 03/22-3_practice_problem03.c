#include<stdio.h>
int main()
{
    char ch;
    ch = getchar();//this getchar(); for taking input.
    getchar();//this getchar(); for Enter.must use when take character variable.

    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
    {
        printf("this is vowel \n");
    }
    else
    {
        printf("this is consonnet \n");
    }

    return 0;
}
