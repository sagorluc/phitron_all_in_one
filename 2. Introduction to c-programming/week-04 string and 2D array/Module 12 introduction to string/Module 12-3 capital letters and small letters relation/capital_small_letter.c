#include<stdio.h>
#include<string.h>
int main()
{
    char name[100];
    fgets(name,sizeof(name),stdin);

    char nul = '\0';

    for(int i=0; name[i] != nul; i++)
    {
        if(name[i] >= 'a' && name[i] <= 'z')
                name[i] = name[i] - 32;

        else if(name[i] >= 'A' && name[i] <= 'Z')
                name[i] = name[i] + 32;
    }
    puts(name);

    return 0;
}
