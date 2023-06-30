#include<stdio.h>
#include<string.h>
int main()
{
    char name[]="sagor";
    char name2[]=" sagor ahmed";
    //puts(name);
    //printf(name);
    printf("%d\n",strlen(name));//string length.

    //printf("%d\n",strlen(name));
    //printf("%d\n",strcmp(name2,name,5));
    strcat(name,name2);//string concatinet
    puts(name);
    printf("%d\n",strlen(name));

    strcpy(name,name2);//string copy.
    printf(name);




    return 0;
}
