#include <bits/stdc++.h>

using namespace std;

namespace mergeSort{
    int compare (int a, int b){
        return a<=b;
    }

    void mergeSortedArray (vector<int> &arr, int low, int mid, int high, std::function<int(int,int)> compare) {
        queue<int> buffer1, buffer2;

        for (int i=low; i<=mid; i++) buffer1.push(arr[i]);
        for (int i=mid+1; i<=high; i++) buffer2.push(arr[i]);

        int i=low;

        while (!(buffer1.empty() || buffer2.empty())) {
            if (compare(buffer1.front() ,buffer2.front())) {
                arr[i++] = buffer1.front();
                buffer1.pop();
            }
            else {
                arr[i++] = buffer2.front();
                buffer2.pop();
            }
        }

        while (!buffer1.empty()){
            arr[i++] = buffer1.front();
            buffer1.pop();
        }

        while (!buffer2.empty()){
            arr[i++] = buffer2.front();
            buffer2.pop();
        }
    
    }

    void mergeSort (vector<int> &arr, std::function<int(int,int)> compare=compare, int low=0, int high=-1){
        if (high == -1){
            high = arr.size()-1;
        }
        if (low<high){
            int mid = (low+high)/2;
            mergeSort(arr, compare, low, mid);
            mergeSort(arr, compare, mid+1, high);

            mergeSortedArray(arr, low, mid, high, compare);
        }
    }
}
