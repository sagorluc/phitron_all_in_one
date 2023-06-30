#include<stdio.h>
int main()
{
    FILE *inputfile;
    inputfile = fopen("input.txt","r");//connect with file.
    if(inputfile == NULL)
    {
       printf("NO FILE FOUND\n");
       return 0;
    }



    FILE *outputfile;
    outputfile = fopen("output.txt","w");//connect with output file and show output and write.

//    char ch = fgetc(inputfile);//read character by inputfile .
//    printf("%c",ch);

//    char ch2 = fgetc(inputfile);//read character by inputfile .
//    printf("%c",ch2);
//
//    char ch3 = fgetc(inputfile);//read character by inputfile .
//    printf("%c",ch3);
//
//    char ch4 = fgetc(inputfile);//read character by inputfile .
//    printf("%c",ch4);

      while(1)
      {
       char ch = fgetc(inputfile);//read character by inputfile .
       if(ch == EOF)//break the infinit loop by EOF(END OF FILE)
        break;

       printf("%c",ch);

       fputc(ch,outputfile);//write character by output.

      }
    return 0;
}
