#include <bits/stdc++.h>

namespace quickSort{
    int compare (int a, int b){
        return a<b;
    }

    int partition (std::vector<int> &arr, int l, int r, std::function<int(int,int)> compare){
        int highStart = l;
        int pivot = r;
        
        for (int i=l; i<r; i++){
            if (compare(arr[i],arr[pivot])){
                std::swap(arr[i], arr[highStart++]);
            }
        }
        std::swap (arr[pivot],arr[highStart]);
        return highStart;
    }

    void quickSort (
        std::vector<int> &arr,
        std::function<int(int,int)> compare=compare, 
        int l=0, int r=-1
    )
    {
        if (r==-1){
            r = arr.size()-1;
        }

        if (l<r){
            int pivot=partition (arr, l, r, compare);
            quickSort (arr, compare, l, pivot-1);
            quickSort (arr, compare, pivot+1, r);
        }
    }
}

