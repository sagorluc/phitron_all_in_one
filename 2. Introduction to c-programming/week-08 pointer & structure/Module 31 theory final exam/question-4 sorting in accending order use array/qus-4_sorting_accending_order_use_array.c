#include<stdio.h>
#include<string.h>
int main()
{
    char fqr[50],ch;
    fgets(fqr,sizeof(fqr),stdin);

    int fqr_len = strlen(fqr);
    for(int i=1; i<fqr_len; i++)
        for(int j=0; j<fqr_len-i; j++)
            if(fqr[j]>fqr[j+1])
            {
                ch=fqr[j];
                fqr[j] = fqr[j+1]; //swaping
                fqr[j+1]=ch;//swaping
            }
    printf("after sort string in ascending order %s",fqr);
    return 0;
}
