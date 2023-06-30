#include<stdio.h>
void find_maxx_minn(int x, int nums[], int* p,int* q);

int main()
{
     int ara[]={12, 6, 9, 3, 4, 21, 66};
     //printf("%d",sizeof(ara)/sizeof(int) );//length of the array.
     int n =7;
     int maxx,minn;
     find_maxx_minn(n,ara,&maxx,&minn);//we want to find maxx and min in one function.
     printf("%d %d",maxx,minn);

//     maxx = find_maxx(n,ara);//if we have tow function then we can use this system.
//     minn = find_minn(n,ara);//if we have tow function then we can use this system.


    return 0;
}

void find_maxx_minn(int x, int nums[], int* p,int* q)
{
    *p = nums[0];
    *q = nums[0];

    int i;
    for(i=0; i<x; i++)
    {
       if(nums[i] > *p)
        *p = nums[i];
       if(nums[i] < *q)
        *q = nums[i];


    }

}
