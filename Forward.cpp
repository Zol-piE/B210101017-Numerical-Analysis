#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

void print(const vector<vector<float>>& arr, int n) // Using vector
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

int main()
{
    fast
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<float> x(n);
    cout << "Enter the values of X: " << endl;
    for(int i = 0; i < n; i++) cin >> x[i];


    vector<vector<float>> y(n, vector<float>(n, 0));

    cout << "Enter the values of Y: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> y[i][0];
    }


    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < (n - i); j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    cout << "Print Forward Difference Table:" << endl;
    print(y, n);

    return 0;
}
