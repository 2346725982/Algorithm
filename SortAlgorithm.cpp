#include <iostream>
#include <algorithm>
using namespace std;

void quick_sort(int arr[], int begin, int end){
    if(begin >= end) return;

    int pivot = arr[end];
    int index = begin;

    for(int i = begin; i <= end - 1;i++) 
        if(arr[i] < pivot)
            swap(arr[i], arr[index++]);
    swap(arr[end], arr[index]);
                    
    quick_sort(arr, begin, index - 1);
    quick_sort(arr, index + 1, end);
}

void merge(int a[], const int begin, const int mid, const int end ){
    int index1 = begin;
    int index2 = mid + 1;
    int storeindex = 0;
    int *b = new int[end - begin + 1];

    while(index1 < mid && index2 < end){
        if(a[index1] < a[index2])
            b[storeindex++] = a[index1++];
        else
            b[storeindex++] = a[index2++];
    }

    while(index1 < mid)
        b[storeindex++] = a[index1++];
    while(index2 < end)
        b[storeindex++] = a[index2++];


    delete[] b;
}

void merge_sort(int arr[], const int begin, const int end){
    if(end - begin == 0) return;

    int mid = ( begin + end ) / 2;
    
    merge_sort(arr, begin, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, begin, mid, end);

    return;
}

void max_heapify(int arr[], int i, int heap_size){
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int large;

    if(left < heap_size && arr[left] > arr[i])
        large = left;
    else
        large = i;

    if(right < heap_size && arr[right] > arr[large])
        large = right;

    if(large != i){
        swap(arr[i], arr[large]);
        max_heapify(arr, large, heap_size);
    }
}

void build_max_heap(int arr[], const int heap_size){
    for(int i = (heap_size - 2) / 2; i >= 0; i--)
        max_heapify(arr, i, heap_size);
}

void heap_sort(int arr[], const int heap_size){
    build_max_heap(arr, heap_size);

    for(int i = heap_size - 1;i >= 0;i--){
        swap(arr[i], arr[0]);
        max_heapify(arr, 0, i);
    }
}

void insertion_sort(int *arr, int n){
   for(int i = 1;i < n;i++){
       for(int j = i; j > 0 && arr[j] < arr[j - 1];j--)
           swap(arr[j], arr[j - 1]);
   } 
}

void shell_sort(int arr[], const int n){
    for(int gap = n / 2; gap > 0; gap /= 2)
        for(int i = gap; i < n; i++)
            for(int j = i; j - gap >= 0 && arr[j] < arr[j - gap]; j -= gap)
                swap(arr[j], arr[j - gap]);


}

void selection_sort(int arr[], const int n){
    for(int i = 0; i < n; i++){
        int index = i;
        for(int j = i + 1; j < n; j++)
            if(arr[j] < arr[index])
                index = j;
        swap(arr[i], arr[index]);
    }

}

void bubble_sort(int arr[], int n){
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n - 1 - i; j++)
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int maxdigit(int arr[], const int n){
    int d = 1;
    int p = 10;

    for(int i = 0; i < n; i++)
        while(arr[i] >= p){
            p *= 10;
            d++;
        }

    return d;
}

void radix_sort(int arr[], const int n){
    int d = maxdigit(arr, n);
    
    int *tmp = new int[n];
    int *count = new int[10];
    
    for(int i = 0, radix = 1; i < d; i++, radix *= 10){

        for(int j = 0; j < 10; j++)
            count[j] = 0;

        for(int j = 0; j < n; j++)
            count[( arr[j] / radix) % 10]++;

        for(int j = 1; j < 10; j++)
            count[j] += count[j - 1];

        for(int j = n - 1; j >= 0; j--){
            int k = ( arr[j] / radix ) % 10;
            tmp[count[k] - 1] = arr[j];
            count[k]--;
        }

        for(int j = 0; j < n; j++)
            arr[j] = tmp[j];
    }

    delete []tmp;
    delete []count;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        int arr[10000] = {0};

        for(int i = 0;i < n;i++)
            cin >> arr[i];

        radix_sort(arr, n);

        for(int i = 0;i < n;i++)
            cout << arr[i] << endl;
    }
}
