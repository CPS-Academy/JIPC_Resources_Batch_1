#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int len = high - low + 1;
    int pivotIndex = (rand() % len) + low;
    swap(arr[pivotIndex], arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        QuickSort(arr, low, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };

    int n = 6;

    QuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}