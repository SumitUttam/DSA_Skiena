#include <bits/stdc++.h>


//searches for leftmost occurance - 1 of element
template<typename T=int>
int binarySearch1 (std::vector<T> arr, T key, int l, int r){
    if (l>r) {
        return r;
    }
    int m = (l+r)/2;
    if (arr[m]<key) {
        return binarySearch1<T>(arr,key,m+1,r);
    }
    else {
        return binarySearch1<T>(arr,key,l,m-1);
    }
}

//searches for rightmost occurance of element
template<typename T=int>
int binarySearch2 (std::vector<T> arr, T key, int l, int r){
    if (l>r) {
        return r;
    }
    int m = (l+r)/2;
    if (arr[m]>key) {
        return binarySearch2<T>(arr,key,l,m-1);
    }
    else {
        return binarySearch2<T>(arr,key,m+1,r);
    }
}

template<typename T=int>
int countOccurances (std::vector<T> arr, T key){
    return <binarySearch2(arr, key, 0, arr.size()), binarySearch1(arr, key, 0, arr.size())>;
}

int main() {
    std::vector<int> arr {1,2,2,3,5,6,7,7,7,7,9};
    std::cout<< "frequency of 4 in arr: " <<countOccurances(arr,4)<<std::endl;
    std::cout<< "frequency of 7 in arr: " <<countOccurances(arr,7)<<std::endl;
    std::cout<< "frequency of 8 in arr: " <<countOccurances(arr,8)<<std::endl;
    std::cout<< "frequency of 3 in arr: " <<countOccurances(arr,3)<<std::endl;
}