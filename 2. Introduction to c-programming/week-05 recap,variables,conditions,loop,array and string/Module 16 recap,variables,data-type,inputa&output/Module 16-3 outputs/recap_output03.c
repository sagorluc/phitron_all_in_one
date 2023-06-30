#include<stdio.h>
int main()
{
    //printf();
    //putchar();
    //puts();
    //fprintf();

    int i = 7;
    float j = 2.5325;


    printf("%d\n%f\n",i,j);//\n moves the cursor to new line
    printf("%d\t%f\n",i,j);//\t insert horizontal tab (5 characters space)
    printf("%d\v%f\n",i,j);//insert vertical tab (5 line spaces)
    //printf("%d\a%f\n",i,j);//beep sound
    printf("%dbackspace\bbackspace%f\n",i,j);//backspace (removes the previous character from its current position)
    printf("%d\\\%f\n",i,j);//insert backward slash symbol
    printf("%d\?%f\n",i,j);//inserts question mark symbol
    printf("%d\'%f\n",i,j);//insert single quotation mark symblo
    printf("%d\"%f\n\n",i,j);//insert double quotation mark symbol


    double v=(22/3.00);
    printf("%0.5lf  \n",v);

    char a = 'u';
    char name[450];
    puts("write something about you ");
    //printf("write something about you ");
    gets(name);
    puts(name);

    //putchar(a);//printf(); jamela lagle putchar use kora better.






    return 0;
}
