#include<stdio.h>
void func(int x, int y, int* p, int* q);
int main()
{
    int a=15, b=12;
    int large,small;

    func(a,b,&large,&small);
    printf("%d %d\n",large,small);


    return 0;
}

void func(int x, int y, int* p, int* q)
{//
//    if(x>y)
//    {
//        *p = x;
//        *q = y;
//    }
//    else
//    {
//      *p = y;
//      *q = x;
//    }

    //this is more smart way to work.this is short of if-else.

    *p = x>y?x:y;
    *q = x<y?x:y;
}
