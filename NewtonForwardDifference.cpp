#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define test double t; cin>>t;
void prdouble(vector<vector<double>> &arr,int n)
{
    cout<<"Print Forward Difference Table"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }
}
double firstdef(vector<vector<double>> &y,vector<double> &x,double xth,int n,double h)
{
    int i = 0;
    for(;i<n;i++)
    {
        if(x[i]==xth) break;
    }
    double sum = 0.0;

    for(int j = 1;j<n;j++)
    {
        cout<<"DEBUG-> "<<sum<<" "<<y[i][j]<<" "<<j<<" "<<(pow(-1,j+1))<<endl;
        sum += (y[i][j] * pow(-1, j+1) / j);
    }
    sum /=h;
    return sum;
}
int main()
{
    /*
    1 1.2 1.4 1.6 1.8 2.0 2.2
    2.7183 3.3201 4.0552 4.9530  6.0496 7.3891  9.0250
    */
    fast
    cout << "Enter the size of the array: ";
    int n ; cin>>n;
    vector<double> x(n,0);

    for(int i =0;i<n;i++) cin>>x[i];

    vector<vector<double>> y(n,vector<double>(n,0));

    for(int i =0;i<n;i++) cin>>y[i][0];

    for(int i=1;i<n;i++)
    {
        for(int j =0;j<(n-i);j++)
        {
            y[j][i] = y[j+1][i-1] - y[j][i-1];
        }
    }
    prdouble(y,n);
    cout<<firstdef(y,x,x[1],n,x[1]-x[0])<<endl;
    return 0;
}

