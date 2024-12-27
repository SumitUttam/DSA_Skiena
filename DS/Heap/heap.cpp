#include <bits/stdc++.h>
#include"heap.h"

using namespace std;
using namespace std::chrono;
using namespace heap;

int main(){
    vector<int> arr {5,9,23,14,17,6,3,2,7,8,11};

    auto start1 = high_resolution_clock::now();
    priorityQueue heapi = Heapify(arr);
    cout << heapi;
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1);
    cout <<"Heapify: "<< duration1.count() <<" ms"<< endl;

    vector<int> arr1 {5,9,23,14,17,6,3,2,7,8,10};

    auto start = high_resolution_clock::now();
    priorityQueue heap = makeHeap(arr1);
    cout << heap;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout <<"makeHeap: "<< duration.count() <<" ms"<< endl;

    
    Heapsort (arr);
    for (auto i: arr){
        cout << i << " ";
    }
    cout << endl;
}
