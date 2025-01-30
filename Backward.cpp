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
int main()
{
    fast
    cout<<"Enter Number Of variable"<<endl;
    int n; cin>>n;
    vector<float> x(n,0);
    cout<<"Enter X variable "<<endl;
    for(int i =0;i<n;i++) cin>>x[i];

    vector<vector<float>> y(n,vector<float>(n,0));

    cout<<"Enter Y Variable "<<endl;
    for(int i =0;i<n;i++) cin>>y[i][0];

    cout<<"Print Table "<<endl;
    Backward(y,n);
    print(y,n);
    return 0;
}

