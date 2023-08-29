#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int m, n, i, j, no_of_zero = 0;
    cout << "Enter the number of row m:";
    cin >> m;
    cout << "Enter the number of column n:";
    cin >> n;
    int matrix[m][n];
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cout << "Enter the element for row:" << i << " column " << j + 1 << ":";
            cin >> matrix[i][j];
            if (matrix[i][j] == 0)
                no_of_zero++;
        }
    }
    cout << "Your Matrix:" << endl;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    if (no_of_zero > ((m * n) / 2)) {
        cout << "Sparse Matrix" << endl;

        cout << "Row\tColumn\tValue" << endl;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (matrix[i][j] != 0) {
                    cout << i + 1 << "\t" << j + 1 << "\t" << matrix[i][j] << endl;
                }
            }
        }
    } else {
        cout << "Not a Sparse Matrix" << endl;
    }

    return 0;
}
