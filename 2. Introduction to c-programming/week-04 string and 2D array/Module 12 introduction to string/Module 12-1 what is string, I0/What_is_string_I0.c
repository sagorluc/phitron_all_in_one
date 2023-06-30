#include<stdio.h>
int main()
{
  char name[] = "sagor ahmed";


  name[0] = 'R';
  name[1] = 'i';
  name[2] = 'm';
  name[3] = 'o';
  name[4] = 'n';
  name[11] = 'y';
  name[12] = '\0';

  printf("%s",name);

    return 0;
}
