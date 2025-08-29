#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[], int l, int mid, int r)
{
  int i = l, j = mid + 1, k = 0;
  int temp[r - l + 1];

  while (i <= mid && j <= r)
  {
    if (arr[i] < arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }

  while (i <= mid)
    temp[k++] = arr[i++];
  while (j <= r)
    temp[k++] = arr[j++];

  for (i = l, k = 0; i <= r; i++, k++)
    arr[i] = temp[k];
}

void mergeSort(int arr[], int l, int r)
{
  if (l == r)
    return;
  int mid = (l + r) / 2;

  mergeSort(arr, l, mid);
  mergeSort(arr, mid + 1, r);

  Merge(arr, l, mid, r);
}

int main()
{
  int arr[] = {4, 5, 1, 3, 2, 3, 10, 7};

  mergeSort(arr, 0, 7);
  for (int i = 0; i < 8; i++)
    cout << arr[i] << " ";

  cout << endl;
  return 0;
}
