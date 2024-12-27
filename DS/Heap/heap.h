#include <bits/stdc++.h>

using namespace std;

namespace heap {
    bool compare_min (int a, int b) {
        return a<b; //for min-heap;
    }

    bool compare_max (int a, int b) {
        return a>b; //for max-heap;
    }


    class priorityQueue{
    private:
        vector<int> heap;
        int n;
        function <bool(int, int)> compare;

        //To be used for Heapify;
        priorityQueue(vector<int> vec, function <bool(int, int)> comp){
            heap = vector<int>{-1};
            n=vec.size();
            heap.insert(heap.end(), vec.begin(), vec.end());
            compare = comp;
        }

        void bubbleDown(int p);
        void bubbleUp (int p);

    public:
        priorityQueue(){
            heap = vector<int> {-1};
            n=0;
            compare = &compare_min; //min-heap default;
        }

        priorityQueue (function<bool(int,int)> comp){
            heap = vector<int> {-1};
            n=0;
            compare = comp;
        }

        void insert(int x);
        int extract_top();

        friend std::ostream &operator<<(std::ostream &os, priorityQueue const &m);
        friend priorityQueue Heapify (vector<int>, function<bool(int,int)>);
    };

    // Bubble Up
    void priorityQueue::bubbleUp (int p){
        if (p<=1) return;

        if (compare(heap[p],heap[p/2])) {
            swap(heap[p/2], heap[p]);
            bubbleUp(p/2);
        }
    }

    // insert
    void priorityQueue::insert (int x){
        n++;
        heap.push_back(x);
        bubbleUp(n);
    }

    // Bubble Down
    void priorityQueue::bubbleDown (int p){
        int min_index = p;

        for (int i=0; i<=1; i++){
            if (p*2+i <= n){
                if (compare(heap[p*2+i],heap[min_index])){
                    min_index = p*2+i;
                }
            }
        }
        if (min_index != p) {
            swap (heap[min_index],heap[p]);
            bubbleDown(min_index);
        }
    }

    // Extract Top
    int priorityQueue::extract_top(){
        if (n<1) {
            cout << "Warning: priorityQueue is empty" << endl;
            return -1;
        }

        int min = heap[1];
        heap[1] = heap[n];
        heap.pop_back();
        n--;
        bubbleDown(1);
        return min;
    }

    //Faster heap making
    priorityQueue Heapify (vector<int> vec, function<bool(int,int)> comp = &compare_min){
        priorityQueue heap(vec, comp);
        //implementation;
        for (int i=heap.n/2; i>0; i--){
            heap.bubbleDown(i);
        }
        return heap;    
    }

    //Naive makeHeap
    priorityQueue makeHeap (vector<int> vec, function<bool(int,int)> comp = &compare_min){
        priorityQueue heap(comp);
        for (auto i:vec){
            heap.insert(i);
        }
        return heap;    
    }

    void Heapsort (vector<int> &vec){
        priorityQueue heap = Heapify(vec);
        // priorityQueue heap = makeHeap(vec);
        for (auto &i:vec){
            i = heap.extract_top();
            // cout << i << heap;
        }
    }

    //std ostream function;
    std::ostream &operator<<(std::ostream &os, priorityQueue const &m) { 
        os<<std::endl;
        for (int i=1; i<=m.n; i++){
            os<<m.heap[i]<<" ";
        }
        os<<std::endl;
        os<<"size: "<<m.n<<std::endl;
        return os;
    }
}