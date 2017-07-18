
#include <stdio.h>
#include <math.h>
#define L 600

double funct(double x)
{
    //double y=2.31*pow(10,-14);
    double y=exp(-x)-x;
    //y*=(-5*pow(x,4)+4*L*L*x-pow(L,4));

    return y;
}

double bisection(double tol, double xLow, double xUp)
{
    double xr,err=1.0;
    while(err>tol)
    {
        printf("running\n");
        xr=(xLow+xUp)/2;
        if(funct(xr)*funct(xLow)<0)
            xUp=xr;
        else if(funct(xr)*funct(xLow)>0)
            xLow=xr;
        else
            break;
        err=fabs((xLow-xUp)/(xLow+xUp))*100;
    }
    printf("Bisection Method: Root: %lf\tError: %.20lf\n\n",xr,err);
}

double Raul(double x,double tol)
{
    double xr,err=1.0;

    while(err>tol)
    {
        //xr=x-(funct(x)/(2.31*pow(10,-14)*(-20*pow(x,3)+(4*L*L))));
        xr=x-(funct(x))/(-exp(-x)-1);
        err=fabs((xr-x)/x);
        x=xr;
    }
    printf("Newton Raphson Method: Root: %lf\tError: %.20lf\n\n",xr,err);
}

int main()
{
    bisection(0.001,-5,5);
    Raul(-5,0.001);
}
