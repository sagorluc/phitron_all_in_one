#include<stdio.h>
#include<math.h>

struct point{

    int x;
    int y;

};

double distance(struct point p, struct point q)
{

    return sqrt( pow(p.x-q.x,2) + pow(p.y-q.y,2));//sqrt() for math and pow() for root over hole square.

}


int main()
{
    struct point p1,p2;

    scanf("%d %d",&p1.x,&p1.y);
    scanf("%d %d",&p2.x,&p2.y);

    int res;
    res = distance(p1,p2);

    printf("The distance between them = %lf\n",res);



    return 0;
}

//(x1,y1) (x2,y2)
//
//root over (x1-y1)2 + (x2-y2)2 //2 point er distance sutro/rules.

