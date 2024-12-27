#include<bits/stdc++.h>

using namespace std;

namespace heapSort{
    bool compare (int a, int b) {
        return a>b; //for max-heap;
    }

    void bubbleDown (vector<int> &heap, int p, int n=-1){
        if (n==-1)
            n=heap.size();
        int min_index = p;
        // cout << n <<endl;

        for (int i=0; i<=1; i++){
            if (p*2+i <= n){
                if (compare(heap[p*2+i-1],heap[min_index-1])){
                    min_index = p*2+i;
                }
            }
        }
        if (min_index != p) {
            swap (heap[min_index-1],heap[p-1]);
            bubbleDown(heap, min_index,n);
        }
    }

    void heapify (vector<int> &heap){
        int n=heap.size();
        for (int i=n/2; i>0; i--){
            bubbleDown(heap, i);
        }   
    }

    void heapSort (vector<int> &heap){
        int n=heap.size();
        heapify(heap);
        
        for (int i=n-1; i>0; i--){
            swap(heap[0],heap[i]);
            bubbleDown(heap,1,i);
        }
    }
}