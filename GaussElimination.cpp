#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define test int t; cin>>t;
void print(double arr[4][5])
{
    for(int i =1;i<4;i++)
    {
        for(int j =1;j<5;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    fast
    double arr[4][5];
    for(int i =1;i<4;i++)
    {
        for(int j =1;j<5;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    for(int i =1;i<4;i++)
    {
        for(int j =1;j<5;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int  k =1;k<3;k++)
    {
        for(int j = k+1;j<4;j++)
        {
            double x = (arr[j][k]/arr[k][k]) ;
            for(int i=k;i<5;i++)
            {
                arr[j][i] = arr[j][i]   - (x * arr[k][i]);
            }
        }
    }
    cout<<endl;
    for(int i =1;i<4;i++)
    {
        for(int j =1;j<5;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    double ans[4] = {0};

    for(int i = 3;i>=1;i--)
    {
        ans[i] = arr[i][4];
        for(int j = i+1;j<4;j++)
        {
            ans[i] -= arr[i][j] * ans[j];
        }
        ans[i] /= arr[i][i];
    }

    cout<<"Ans : ";
    for(int i=1;i<4;i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}
