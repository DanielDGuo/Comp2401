// tw4.cpp : correct the errors/warning in the file.  




#include "stdio.h"

int fun(int x)
{
    if (x > 5) { 
        x++;
        return(x);
    }
}


int main(int argc, char* argv[])
{
 int x=2;
 
 printf("fun(%d) =%d\n",x,fun(x));

 return 0;
}

