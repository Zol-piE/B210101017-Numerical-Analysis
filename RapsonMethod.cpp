#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define test int t; cin>>t;
double f1(double a)
{
    return a*sin(a)+cos(a);
}
double f2(double a)
{
    return a*cos(a);
}
double f3(double a)
{
    return a*exp(a) -1;
}
double f4(double a)
{
    return a*exp(a) + exp(a);
}
void rapsonMethod(double a,int iter)
{
    int i =0;
    double xnew,xold=a;
    while(i<=iter)
    {
        xnew = xold - ( f3(xold) / f4(xold) );
        if(xold==xnew) break;
        xold = xnew;
        i++;
    }
    cout<<fixed<<setprecision(4)<<"Root of The equation : "<<xnew<<endl;

}
int main()
{
    fast
    double x,n;
    cout<<"Enter First X0 and Number Of iterations: ";
    cin>>x>>n;
    rapsonMethod(x,n);
    return 0;
}

