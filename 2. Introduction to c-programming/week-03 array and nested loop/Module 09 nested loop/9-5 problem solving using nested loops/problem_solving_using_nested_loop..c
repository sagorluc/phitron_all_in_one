#include<stdio.h>

int main()
{
   int i,j;
   float x,sum,ava;

   for (i=1; i<=10; i++) //for each students
   {
     printf("Enter the marks of %d-th students : ",i);

     sum =0.0; //initial all the marks is 00.
     for (j=1; j<=3; j++) // for each subjects
     {
       scanf("%f",&x); //input for subject.
       sum += x; //jog all the subjuct number.


     }
     ava = sum/3; // after jog all the subject marks then divided by 3.
     printf("avarage of each subject %f\n",ava); //result all the average marks.
   }



    return 0;
}
