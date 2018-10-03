#include <stdlib.h>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <regex>

using namespace std;

double y , a , x ; //乘方运算y=a^x
long N = 30 ; //泰勒展式的展开项数,其意为计算精度

// double result( double a , double x)
// {
// 	double ex = 0.0;



// }



double get_pow(double x , double n)
{
	double spr = 1.0;
	for( long i = 0 ;i < n ; i++)
	{
		spr = spr * x;
	}
    return spr;
}


long get_factorial( long n  )
{
    if(n == 0)
    	return 1;

    return n*get_factorial(n - 1);
}

double get_ex( double x )
{
   double ex = 0.0 ;
   
   for( long i = 0 ;i < N ; i++)
   {
   	    printf("%f",ex);
   		ex += get_pow(x ,i)/get_factorial(i);
   }

   return ex;

}

double get_lnx( double x )
{
   double lnx = 0.0 ;
   
   for( long i = 0 ;i < N ; i++)
   {
   	    printf("%f",ex);
   		lnx += get_pow(x ,i)/get_factorial(i);
   }

   return lnx;

}


int main(int argc, char *argv[])
{
    
	printf("get_factorial:%f\n",get_ex(2.0));

    return 0;
}
