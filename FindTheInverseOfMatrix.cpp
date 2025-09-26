#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define test int t; cin>>t;
typedef vector<vector<double>> vec;
int main()
{
    fast
    int n =3;
    vector<vector<double>> mat(n,vector<double>(n,0));
    cout<<"INput Matrix"<<endl;
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    vec inverse(n,vector<double>(n,0)),res(n,vector<double>(n,0));


    return 0;
}

