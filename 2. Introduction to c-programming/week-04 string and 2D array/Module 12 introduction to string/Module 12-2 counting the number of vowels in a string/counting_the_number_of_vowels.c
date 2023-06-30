#include<stdio.h>

int main()
{
    char arr[1000];

    //scanf("%s",arr); it will not work for #char data typs.

    //gets(arr);//we have to use #gets or fgets

    fgets(arr,sizeof(arr),stdin);//this is standard for programmer.

    int i=0,counter =0;
    while(arr[i]!='\0')
    {
       if(arr[i]=='a')
       {
          counter++;;
       }
       else if(arr[i]=='e')
       {
          counter++;
       }else if(arr[i]=='i')
       {
          counter++;
       }else if(arr[i]=='o')
       {
          counter++;
       }else if(arr[i]=='u')
       {
          counter++;
       }

       i++;
    }
    printf("no. of vowels = %d",counter);



    return 0;
}
