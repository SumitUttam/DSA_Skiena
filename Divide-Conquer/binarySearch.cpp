#include <bits/stdc++.h>

template<typename T=int>
int binarySearch (std::vector<T> arr, T key, int l, int r){
    if (l>r) {
        std::cout<<key<<" not found in array!"<<std::endl;
        return (-1);
    }
    int m = (l+r)/2;
    if (arr[m]==key) {
        std::cout<<key<<" found in array at index "<<m<<std::endl;
        return m;
    }
    if (arr[m]<key) {
        return binarySearch<T>(arr,key,m+1,r);
    }
    else {
        return binarySearch<T>(arr,key,l,m-1);
    }
}

int main() {
    std::vector<int> arr {1,2,4,5,6,7,9};
    binarySearch<int>(arr,5,0,arr.size());
    binarySearch(arr,8,0,arr.size());
}