#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<double>> &arr, int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n + 1; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void GaussianElimination(vector<vector<double>> &arr, int n) {
    double sum;
    for(int i = 1; i <= n - 1; i++) {
        for(int j = i + 1; j <= n; j++) {
            sum = arr[j][i] / arr[i][i];
            for(int k = 1; k <= n + 1; k++) {
                arr[j][k] = arr[j][k] - sum * arr[i][k];
            }
        }
    }

    cout << "After Gaussian Elimination:\n";
    print(arr, n);

    vector<double> sol(n + 1);
    for(int i = 1; i <= n; i++) {
        sol[i] = arr[i][n + 1] / arr[i][i];
    }

    cout << "The Solutions are:\n";
    for(int i = 1; i <= n; i++) {
        cout << "x" << i << " = " << fixed << setprecision(2) << sol[i] << endl;
    }
}

int main() {
    int n;
    cout << "Enter Number of Unknowns in the System:\n";
    cin >> n;

    vector<vector<double>> arr(n,vector<double>(n,0));

    cout << "Enter Augmented Matrix:\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n + 1; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Entered Augmented Matrix:\n";
    print(arr, n);

    GaussianElimination(arr, n);

    return 0;
}
