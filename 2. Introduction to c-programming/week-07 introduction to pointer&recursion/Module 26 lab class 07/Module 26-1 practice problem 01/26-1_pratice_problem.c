#include<stdio.h>
void print_hash(int x);

int main()
{
    int i,n=10;
    for(i=0; i<n; i++)//colum
        print_hash(i);//row


//    print_hash(2);
//    print_hash(3);
//    print_hash(4);
//    print_hash(5);

    return 0;
}

//we will print hash using function.
//#
//##
//###
//####
//#####

void print_hash(int x)
{
  int i;
  for(i=0; i<x; i++)//row
  {
    printf("#");

  }
  printf("\n");
}
