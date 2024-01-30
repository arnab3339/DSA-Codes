#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int a[100], size, i, key;
    cout << "Enter the Size of the Array: ";
    cin >> size;
    cout << "Enter the elements of the Array (in sorted order): ";
    for (i = 0; i < size; i++) {
        cin >> a[i];
    }
    cout << "Enter The Element to be Searched: ";
    cin >> key;
    int index = binarySearch(a, size, key);
    if (index != -1) {
        cout << "Item Found at Position: " << index + 1;
    } else {
        cout << "Item Not Found";
    }
    return 0;
}
