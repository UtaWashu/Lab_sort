#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        max_val = max(max_val, arr[i]);
    }
    return max_val;
}

void countingSort(int arr[], int n, int exp) {
    const int range = 10; // число разрядов
    int count[range] = {0};
    int output[n];

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int max_val = getMax(arr, n);
    for (int exp = 1; max_val/exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int arr[] = {550, 434, 242, 1234, 121, 99};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
