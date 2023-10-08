#include <iostream>
using namespace std;
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}
int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
int arr[n];
    std::cout << "Enter " << n << " elements:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    selectionSort(arr, n);
    std::cout << "Sorted array:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  return 0;
}
