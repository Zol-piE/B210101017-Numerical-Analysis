
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define test int t; cin>>t;
void Backward(vector<vector<float>> &arr,int n)
{
    for(int i =1;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            arr[j][i] = arr[j][i-1] - arr[j-1][i-1];
        }
    }
}
void print(vector<vector<float>> &arr,int n)
{
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
unsigned int factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
double solve(vector<vector<float>> &y,vector<float>&x,int val,int h,int n)
{
    double p = (val - x[n-1]) / h;
    double res = y[n-1][0];
    for
}
int main()
{
    fast
    cout<<"Enter Number Of variable"<<endl;
    int n; cin>>n;
    vector<float> x(n,0);
    cout<<"Enter X variable "<<endl;
    for(int i =0;i<n;i++) cin>>x[i];

    vector<vector<float>> y(n,vector<float>(n,-1));

    cout<<"Enter Y Variable "<<endl;
    for(int i =0;i<n;i++) cin>>y[i][0];

    cout<<"Print Table "<<endl;
    print(y,n);
    cout<<"Print Backward Table "<<endl;
    Backward(y,n);
    print(y,n);
    cout<<"Enter The Value Of X for Interpolation " <<endl;
    float z; cin>>z;
    cout<<solve(y,x,n,x[1]-x[0],z);
    return 0;
}
