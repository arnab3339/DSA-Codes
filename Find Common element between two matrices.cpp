#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int m, n, i, j, no_of_zero = 0;
    cout << "Enter the number of rows m: ";
    cin >> m;
    cout << "Enter the number of columns n: ";
    cin >> n;

    int matrix1[m][n], matrix2[m][n];

   
    cout << "Enter elements for first matrix:" << endl;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cout << "Enter the element for row " << i + 1 << " column " << j + 1 << ": ";
            cin >> matrix1[i][j];
        }
    }


    cout << "Enter elements for second matrix:" << endl;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cout << "Enter the element for row " << i + 1 << " column " << j + 1 << ": ";
            cin >> matrix2[i][j];
        }
    }

    cout << "Common elements between the two matrices:" << endl;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matrix1[i][j] == matrix2[i][j] && matrix1[i][j] != 0) {
                cout << "Row: " << i + 1 << ", Column: " << j + 1 << ", Value: " << matrix1[i][j] << endl;
            }
        }
    }
    
    return 0;
}
