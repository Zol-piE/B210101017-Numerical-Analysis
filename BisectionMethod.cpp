#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define test int t; cin>>t;
double fun(double x)
{
    return ((x*x*x) -2*x-5);
}

void bisection(double a,double b,double tol)
{
    double mid = b;
    while((b-a)>=tol)
    {
        mid = (a+b)/2;
        double res = fun(mid);
        if(mid==0) break;

        if(fun(a)*res<0)
        {
            b = mid; // root lies between a and mid
        }
        else if(fun(b)*res<0)
        {
            a = mid;// root lies between a and mid
        }
    }
        cout<<"Root Of the Equation :"<<mid<<endl;
}
int main()
{
//    fast
    double a,b;
    cout<<"Enter The intervals A and B ";
    cin>>a>>b;
    while(fun(a) * fun(b)>=0)
    {
        cout<<"Enter Valid intervals"<<endl;
        cin>>a>>b;
    }
    cout<<"Input Tolerance :"; double tol; cin>>tol;
    bisection(a,b,tol);

    return 0;
}

