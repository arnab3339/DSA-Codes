#include <iostream>
using namespace std;
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
   while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    insertionSort(arr, n);
    std::cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
return 0;
}
