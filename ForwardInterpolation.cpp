#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

void print(vector<vector<float>>&arr, int n) // specify size of the array
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
unsigned int factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
float solve(vector<vector<float>>&y,vector<float> &x,int n,int h,float val)
{
    double  p = (val -x[0]) / h;

    float res = 0;
    res+= y[0][0];
    for(int i =1;i<n;i++)
    {
        float z = 1;
        for(int j = 0;j<i;j++)
        {
           z *=(p-j);
        }
        res += (z * y[0][i]) / (float)factorial(i);

    }
    return res;
}
void forwardDifference(vector<vector<float>>&y,int n)
{
        for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < (n - i); j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }
}
int main()
{
    fast
    int n ; cin>>n;
    vector<float> x(n,0);
    /*
        4
        1 3 5 7
        24 120 336 720
        8

        ans = 990
    */
    cout<<"Enter The The Value Of X "<<endl;

    for(int i =0;i<n;i++) cin>>x[i];

    vector<vector<float>> y(n,vector<float>(n,0));

    cout<<"Enter The The Value Of Y "<<endl;
    for(int i = 0;i<n;i++)
    {
        cin>>y[i][0];
    }
//    y[0][0] = .7071;
//    y[1][0] = .7660;
//    y[2][0] = .8192;
//    y[3][0] = .8660;
    forwardDifference(y,n);
    cout<<"Print Forward Difference Table"<<endl;
    print(y, n); // call the print function with n
    cout<<"Enter The Value Of X for Interpolation " <<endl;
    float z; cin>>z;
    cout<<solve(y,x,n,x[1]-x[0],z)<<endl;
    return 0;
}
