#include<stdio.h>
#include<math.h>

//manhattan distance formula
//
//|x1-x2| + |y1-y2|

struct point  //create deta type structure.
{

    int x;
    int y;

};

int manhattan(struct point p1, struct point p2)//function for main calculation.
{
    int res;
    res = abs(p1.x - p2.x) + abs(p1.y - p2.y); //this is the formula code of manhattan distance.
                                              //abs() built_in function.means absolute.

    return res;

}


int main() //main file.
{

    struct point p1; //= {1, 1} ;//initialize
    struct point p2; //={4, 5};//initialize

    printf("Enter the input of manhattan distance\n");

    scanf("%d,%d\n",&p1.x,&p1.y);//taking input from user

    scanf("%d,%d",&p2.x,&p2.y);//taking input from user



    int ans;
    ans = manhattan(p1,p2);

    printf("Mahattan distance is = %d\n",ans);

    return 0;
}





