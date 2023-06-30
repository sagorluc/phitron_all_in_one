//what is function?
//
//as we know the function is a relationship between inputs where each
//input is related to exactly one output.
//
//types of user-defined function.
//there are four types of user-defined function as below with example.
//
//1. Function with no arguments and no return value
//2. Function with no arguments and a return value
//3. Function with arguments and no return value
//4. Function with arguments and with return value

//What are the benefits of using user-defined functions?
//as i know the main benefits of user-defined function that we can make it whatever we need for our work/projects as user-defined function.
//and user-defined function could be a library function to someone else.we can creat a function which called user-defined
//function for help someone's project.
//this  function makes program esey to understand , maintain  and debbg.
//and it decompose a large program in to small segments.
//
//probably that is the benefits of user-deefined function.
//3. Function with arguments and no return value.

#include<stdio.h>

void argum_no_retu(int x, int y);
void no_argum_no_retu();
int no_argum_retu_valu();
int with_argum_retu_valu(int x, int y);

int main()
{
    //function with arguments and no return value.
    int a=5,b=4;
    argum_no_retu(a,b);
    printf("\n");

    //function with no arguments and no return value.
    no_argum_no_retu();
    printf("\n");

    //function with no arguments and return value.
    int res;
    res = no_argum_retu_valu();
    printf("no arguments but return value, sum is = %d\n",res);


    //function with arguments and with return value.
    int a1=6,b1=8,res2;
    res2 = with_argum_retu_valu(a1,b1);
    printf("with arguments with return value, multiply is = %d\n",res2);



  return 0;
}

void argum_no_retu(int x, int y)
{
   printf("with arguments but no return value, sum is = %d ",x + y);

}

void no_argum_no_retu()
{
   printf("function with no arguments and no return value\n");

}

int no_argum_retu_valu()
{
   int a=11,b=15;

   int ans;
   ans = a + b;

   return ans;

}

int with_argum_retu_valu(int x1, int y1)
{
    return x1 * y1;

}


