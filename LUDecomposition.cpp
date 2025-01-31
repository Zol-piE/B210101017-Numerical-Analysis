#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

void printMatrix(const vector<vector<double>>& arr, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    fast
    int n;
    cout << "Enter the row or column of the square matrix:\n";
    cin >> n;

    /*
    4 3 1
    2 1 3
    1 2 4
    */
    vector<vector<double>> arr(n, vector<double>(n, 0));
    cout << "Enter a " << n << " x " << n << " matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<double>> L(n, vector<double>(n, 0));
    vector<vector<double>> U(n, vector<double>(n, 0));

    for(int i = 0; i < n; i++) {
        for(int k = i; k < n; k++) {
            double sum = 0;
            for(int j = 0; j < i; j++) {
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = arr[i][k] - sum;
        }

        for(int k = i; k < n; k++) {
            if(i == k) {
                L[i][i] = 1.0;
            } else {
                double sum = 0;
                for(int j = 0; j < i; j++) {
                    sum += L[k][j] * U[j][i];
                }
                L[k][i] = (arr[k][i] - sum) / U[i][i];
            }
        }
    }

    cout << "The Lower matrix of the given matrix is:\n";
    printMatrix(L, n);

    cout << "The Upper matrix of the given matrix is:\n";
    printMatrix(U, n);

    return 0;
}
