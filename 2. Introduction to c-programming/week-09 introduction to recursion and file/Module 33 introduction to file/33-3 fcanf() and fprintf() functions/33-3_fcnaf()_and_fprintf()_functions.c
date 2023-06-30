#include<stdio.h>
int main()
{
    FILE *inputfile;
    FILE *outputfile;

    inputfile = fopen("input2.txt","r");//connect with my input file and read.
    outputfile = fopen("output.txt","w");//connect with my output file and write.

    if(inputfile==NULL)
    {
        fprintf(outputfile,"FILE NOT FOUND \n");//file address wrong hole ei massage dibe.
        return 0;
    }
    int n;
    fscanf(inputfile,"%d",&n);

    int sum = 0;
    for(int i=0; i<n; i++)
    {
        int a;
        fscanf(inputfile,"%d",&a);
        sum += a;

    }
    fprintf(outputfile,"sum-> %d",sum);


    return 0;
}
