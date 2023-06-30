#include<stdio.h>

int main(){
    int a , b ;
    int c , d ;
    int e , f , g ;
    int h , i , j , k;

    scanf("%d%d", &a , &b);
    scanf("%d%d" , &c , &d);
    scanf("%d%d%d" , &e , &f , &g);
    scanf("%d%d%d%d" , &h , &i , &j , &k );


    int jog , biyog , gun , vag ;
    jog = a + b;
    biyog = c - d;
    gun = e * f * g ;
    vag = h % i % j % k;

    printf("jog of the tow numbers is %d \n", jog );
    printf("biyog of the tow numbers is %d  \n", biyog );
    printf("multiple of the three numbers is %d \n", gun );
    printf("vag of the four numbers is %d ", vag );

    return 0;

}


