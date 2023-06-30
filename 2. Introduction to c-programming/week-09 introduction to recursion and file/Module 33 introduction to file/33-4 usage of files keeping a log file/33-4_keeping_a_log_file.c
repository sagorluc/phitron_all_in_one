#include<stdio.h>
int main()
{
    FILE *inputfile;
    FILE *logFile;
    inputfile = fopen("input.txt","r");
    logFile = fopen("log.txt","a");//mood a for keeping history.

    if(inputfile == NULL)
    {
        fprintf(logFile,"input file not founed at 3:31 PM \n");
    }

    return 0;
}
