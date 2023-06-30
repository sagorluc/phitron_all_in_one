#include<stdio.h>

int main(){

    int x;
    printf("please enter an input: ");
    scanf("%d", &x);

    int y , z;
    printf("enter a number and chack the big or small number ");
    scanf("%d%d", &y , &z);

    if (y > z){
        printf("y is bigger then z \n" );
    }
    else{
        printf("z is smaller then y \n");
    }

    if (x % 2 == 0){

        //ekhane code executed hobe jodi condition sotto hoy

        printf("the number is EVEN \n");

    }
    else {

        //Ehane code executed hobe jodi condition mittha hoy.

        printf("the number is ODD ");
    }

    return 0;
}
