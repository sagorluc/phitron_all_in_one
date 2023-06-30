#include<stdio.h>
int main()
{
    FILE *inputfile;
    FILE *outputfile;
    FILE *logfile;

    inputfile = fopen("input.txt","r");//read mood
    outputfile = fopen("output.txt","w");//write mood
    logfile = fopen("log.txt","a");//log mood

    if(inputfile==NULL)
    {
        fprintf(inputfile,"input file not founed \n");
        return 0;
    }


    int n;
    fscanf(inputfile,"%d",&n);

    fprintf(inputfile,"%d\n",n);

    fprintf(outputfile,"%d\n",n);

    fprintf(logfile,"%d at 2.58 pm\n",n);

    fclose(inputfile);
    fclose(outputfile);
    fclose(logfile);

    return 0;
}
