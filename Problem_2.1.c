#include <stdio.h>
#include <math.h>

void checkErrorSingle(double N, double k)
{
    double h=0.0,error=0.0,diff=0.0,rel=0.0,j=0.0,temp=0.0,temp2=0.0,x=0.0;
    h=(double)1/N;
    for(j=0;j<=N;j++)
    {
        x=(double)j*h;
        temp=k*cos(k*x);
        temp2=(-sin(k*x)+sin(k*(x+h)))/h;
        if(temp>temp2)
        {
            diff=temp-temp2;
        }
        else
        {
            diff=temp2-temp;
        }
        error+=diff;
    }
    rel=error/k;
    printf("Absolute Error:     %lf\n\n",error);
    printf("Relative Error:     %lf\n\n",rel);

}

void checkErrorDouble(double N, double k)
{
    double h=0.0,error=0.0,diff=0.0,rel=0.0,j=0.0,temp=0.0,temp2=0.0,x=0.0;
    h=(double)1/N;
    for(j=0;j<=N;j++)
    {
        x=(double)j*h;
        temp=-k*k*sin(k*x);
        temp2=(sin(k*(x+h))-2*sin(k*x)+sin(k*(x-h)))/(h*h);
        if(temp>temp2)
        {
            diff=temp-temp2;
        }
        else
        {
            diff=temp2-temp;
        }
        error+=diff;
    }
    rel=error/(k*k);
    printf("Absolute Error:     %lf\n\n",error);
    printf("Relative Error:     %lf\n\n",rel);

}

int main()
{
    printf("Problem 2.1\n\n");

    /*double dt=0.01;
    int size=4*M_PI/dt;
    double x[size];
    x[0]=1.0;
    double v[size];
    v[0]=0.0;
    x[1]=cos(dt);//(x[0]+dt*v[0]);
    v[1]=-sin(dt);//(v[0]-dt*x[1]);
    double t=0.0;
    int count=1;

    printf("x(%2.2f):  %f\tv(%2.2f):  %f\tExact x(%2.2f):  %f\tExact v(%2.2f):  %f\n\n",
               t,x[count],t,v[count],t,cos(t),t,-sin(t));

    for(t=0;t<(4*M_PI);t+=dt)
    {
        //x[count]=(x[count-1]+dt*v[count-1]);
        //v[count]=(v[count-1]-dt*x[count]);

        x[count+1]=(v[count]*dt*dt)+(2*x[count])-(x[count-1]);
        v[count+1]=(x[count]*dt*dt)+(2*v[count])-(v[count-1]);
        //x[count]=(4*x[count-1])-(3*x[count-2])+(2*dt*((Ox*(dt*dt))-v[count-2]));
        //v[count]=(4*v[count-1])-(3*v[count-2])+(2*dt*((Ov*(dt*dt))-x[count-2]));
        //v[count]=((4*x[count]+dt-3*x[count]-x[count-1]+(2*dt))/2*dt)+O*(dt*dt);

        printf("x(%2.2f):  %f\tv(%2.2f):  %f\tExact x(%2.2f):  %f\tExact v(%2.2f):  %f\n\n",
               t,x[count],t,v[count],t,cos(t),t,-sin(t));
        count++;
    }*/

    printf("A. Take N=10 and calculate error incurred by the preceding formulas for k=1\n\n");
    //derv of sinkx = kcoskx
    double N,k;
    N=10;
    k=1;
    checkErrorDouble(N,k);

    printf("\n\nB. Repeat by taking k=5,10,20 with N=10\n\n");
    printf("\nFor k=5:\n\n");
    N=10;
    k=5;
    checkErrorDouble(N,k);
    printf("\nFor k=10:\n\n");
    N=10;
    k=10;
    checkErrorDouble(N,k);
    printf("\nFor k=20:\n\n");
    N=10;
    k=20;
    checkErrorDouble(N,k);

    printf("\n\nC. Repeat by taking k=20 and N=100 and N=500\n\n");
    printf("\nFor N=100:\n\n");
    N=100;
    k=20;
    checkErrorDouble(N,k);
    printf("\nFor N=500:\n\n");
    N=500;
    k=20;
    checkErrorDouble(N,k);

    printf("\n\nD. Repeat by taking k=1 and N=100,10^3,10^4,10^6,10^9\n\n");
    printf("\nFor N=100:\n\n");
    N=100;
    k=1;
    checkErrorDouble(N,k);
    printf("\nFor N=10^3:\n\n");
    N=1000;
    k=1;
    checkErrorDouble(N,k);
    printf("\nFor N=10^4:\n\n");
    N=10000;
    k=1;
    checkErrorDouble(N,k);
    printf("\nFor N=10^6:\n\n");
    N=1000000;
    k=1;
    checkErrorDouble(N,k);
    printf("\nPlease Wait...\n\n");
    printf("\nFor N=10^9:\n\n");
    N=1000000000;
    k=1;
    checkErrorDouble(N,k);

    printf("\nAfter N=10^6, the error begins to increase again.\n\n");

    return 0;
}

