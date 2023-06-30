//5 types of error in c.
there are many types of error and
it depends on what mistake we made while writing our program.


1.syntax error.
syntax errors are mistakes in using the language.
examples of syntax errors are missing a comma or a quotation mark, or misspelling a word.
#include<stdio.h>
int main()
{
  char name;
  name = "bangladesh;
  return 0;
}

2.runtime error.
common exam of runtime error.
trying to open file that doesn't exist.and
trying to divide by a variable that contains a value of zero.
#include<stdio.h>
int main()
{
int a = 5,b;
b = a/0;
return 0;
}


3.complier error.
#include<stdio.h>
struct err{
    char name[];
};

int main()
{
    struct err e ={"hello world"};
    return 0;
}

4.logicla error.
logical error will show when,
adding when you we shoule be subtracting.
multiplying when we should be dividing.
#include<stdio.h>
int main()
{//logical error
int a=5,b=10;
int c = a-b;
printf("%d",a+b);
    return 0;
}

5.linker error.
this types of error is generated when a different object file is unable to link with the main object file.
we can run into a linked error that we have imported an incorrect header file in the code,
we have a wrong function declaration, etc.
#include<stdio.h>
void Main()
{
    int p = 10;
    printf("%d",p);
}



