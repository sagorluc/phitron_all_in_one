#include<stdio.h>
//formula of tow point er midle point er porimap
//(x+y)/2
//(x+y)/2
struct point{

    float x;
    float y;

};

struct point mid_point(struct point m, struct point n)
{
   struct point ans;
   ans.x = (m.x + n.x)/2;
   ans.y = (m.y + n.y)/2;

   return ans;
};

int main()
{
    struct point p1 = {1, 1};
    struct point p2 = {4, 5};

    struct point p3;

    p3 = mid_point(p1,p2);


//    p3.x = p2.x + p1.x;
//    p3.y = p2.y + p1.y;

    printf("%0.2f,%0.2f",p3.x,p3.y);

    return 0;
}
