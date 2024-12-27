#include <bits/stdc++.h>
#include "mergeSort.h"
#include "quickSort.h"
#include "../DS/Heap/heapsort.h"

using namespace std;
using namespace std::chrono;

int main (){
    vector<int> arr1 {5,9,23,14,17,6,3,2,7,8,10};
    vector<int> arr2 {5,9,23,14,17,6,3,2,7,8,11};

    auto start1 = high_resolution_clock::now();
    quickSort::quickSort(arr1);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1);
    cout <<"QuickSort: "<< duration1.count() <<" ms"<< endl;

    for (int i:arr1){
        cout << i << " ";
    }
    cout << endl;

    auto start = high_resolution_clock::now();
    mergeSort::mergeSort(arr2);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout <<"mergeSort: "<< duration.count() <<" ms"<< endl;

    for (int i:arr2){
        cout << i << " ";
    }
    cout << endl;

    vector<int> arr {5,9,23,14,17,6,3,2,7,8,10};

    auto start2 = high_resolution_clock::now();
    heapSort::heapSort(arr);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2);
    cout << "heapSort: " << duration2.count() << "ms" <<endl;
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout << endl;

    return 0;
}