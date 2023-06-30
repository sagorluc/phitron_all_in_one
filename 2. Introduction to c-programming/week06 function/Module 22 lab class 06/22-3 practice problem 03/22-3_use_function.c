#include<stdio.h>
char is_vowel(char x);

int main()
{
    char ch;
    ch = getchar();//this getchar(); for taking input.
    getchar();//this getchar(); for Enter.must use when take character variable.

    if(is_vowel(ch))
        printf("the character is vowel \n");
    else
        printf("the characte is consonnet \n");

    return 0;
}

char is_vowel(char x)
{
    if(x=='a' || x=='e'|| x=='i' || x=='o' || x=='u')
        return 1;
    else
        return 0;
}
