:// tw4.cpp : correct the errors/warning in the file.  




#include "stdio.h"

int fact(int x)
{
    if (x == 0 || x == 1) return(1);
    return(x*fact(x-1);
}


int main(int argc, char* argv[])
{
 float x=2;
 
 printf("fact(%d) =%d\n",x,fact(x));
 printf("hit <cr> to continue "); getchar();
 x = -5;
 printf("fact(%d) =%d\n",x,fact(x));

 return 0;
}

