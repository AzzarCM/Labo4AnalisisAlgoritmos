#include<iostream>
#include<cmath>
using namespace std;
 

void swap(int* a, int* b)
{
  int t = *a;
  *a = *b;
  *b = t;
}
 
int partition (int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
    i++;
    swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}
 
void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
  int pi = partition(arr, low, high);
  quickSort(arr, low, pi - 1);
  quickSort(arr, pi + 1, high);
  }
}


int getInto(int arr[], int longitud) {

    quickSort(arr, 0, longitud-1);
    int p=2, k=2;
    for(int i=0;i<longitud;i++){
        if(arr[i]>=p)
        p=2*(k++);
    }
    return p;
}
 
int main() {
    int T;
    cin >> T;
    for(int i=0; i<T; i++)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int j=0; j<n; j++)
        {
        	cin >> arr[j];
        }
        cout << getInto(arr, n);
        cout << "\n";
    }
}
