#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double function(double x)///////////////ghrthnerre6e5jhn65e
{
	return  ((x*x*x*x) + 8 * (x*x*x) - 6 * (x*x) - 72 * x + 90);
}
int main()
{
	int iterations = 0;
	double a = 1.5, b=2.0, x_m = (a+b)/2;
	double y, z, f1, f2, f3, eps = 0.0001;
	double res_x, L2;

    do
    {

    	double L2 = b-a;
    	y = a + L2/4 ;
	z = b - L2/4;
	f1 = function(y);
    	f2 = function(z);
    	f3 = function(x_m);
    	iterations++;

              if( f1 < f3 )
              {
                      b = x_m;
                      x_m = y;
              }

              else if ( f2 < f3)
              {
                      a = x_m;
                      x_m = z;
              }
              else if (f2 >= f3)
              {
              	a = y;
              	b = z;

              }
    }
    while( abs( L2 ) > eps );
    res_x = (a + b) / 2;
    cout <<  fixed << setprecision(33) << res_x;
    cout <<  fixed << setprecision(33) << function(res_x);
    cout <<  iterations;
    return 0;
}
