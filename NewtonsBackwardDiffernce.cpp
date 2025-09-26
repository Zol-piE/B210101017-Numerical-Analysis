#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define test int t; cin>>t;
typedef vector<vector<double>> vec;
typedef vector<double> vec1;
void Backward(vec &y,int n)
{
    for(int i = 1;i<n;i++)
    {
        for(int j = i;j<n;j++)
        {
            y[j][i] = y[j][i-1] - y[j-1][i-1];
        }
    }
}
void print(vec &y,int n)
{
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            cout<<y[i][j]<< " ";
        }
        cout<<endl;
    }
}
double firstdef(vec &y,vec1 &x,double xth,double h,int n)
{
    int i =0;
    double sum=0;
    for(;i<n;i++)
    {
        if(x[i]==xth) break;
    }
    for(int j  =1;j<n;j++)
    {
        sum+= (y[i][j] / (double)j);
    }
    sum/=h;
    return sum;
}double secondDef(vec &y,vec1 &x,double xth,double h,int n)
{
    int i =0;
    double sum=0;
    vector<double> con = { 1,1,.9166,.8333};
    int conSize = con.size();
    for(;i<n;i++)
    {
        if(x[i]==xth) break;
    }
    for(int j  =2,k =0;k<conSize;j++,k++)
    {
        sum+= (y[i][j] * con[k] );
    }
    h*=h;
    sum/=h;
    return sum;
}
int main()
{
    fast
    int n ; cin>>n;
    vector<double> x(n,0);
    for(int i =0;i<n;i++) cin>>x[i];
    vector<vector<double>> y(n,vector<double>(n,0));
    for(int i =0;i<n;i++) cin>>y[i][0];
    Backward(y,n);
    print(y,n);
    cout<<firstdef(y,x,x[n-1],x[1]-x[0],n)<<endl;
    cout<<secondDef(y,x,x[n-1],x[1]-x[0],n)<<endl;
    return 0;
}

