#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

void print(float arr[4][4], int n) // specify size of the array
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
float solve(float y[4][4],float x[4],int n,int h,float val)
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
int main()
{
    fast
    int n = 4;
    float x[n];
    cout<<"Enter The The Value Of X "<<endl;

    for(int i =0;i<4;i++) cin>>x[i];

    float y[4][4];

    cout<<"Enter The The Value Of Y "<<endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            y[i][j] = -1;
        }
    }
    for(int i = 0;i<4;i++)
    {
        cin>>y[i][0];
    }
//    y[0][0] = .7071;
//    y[1][0] = .7660;
//    y[2][0] = .8192;
//    y[3][0] = .8660;

    for(int i = 1; i < 4; i++)
    {
        for(int j = 0; j < (n - i); j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }
    cout<<"Print Forward Difference Table"<<endl;
    print(y, n); // call the print function with n
    cout<<"Enter The Value Of X for Interpolation " <<endl;
    float z; cin>>z;
    cout<<solve(y,x,n,x[1]-x[0],z)<<endl;
    return 0;
}
