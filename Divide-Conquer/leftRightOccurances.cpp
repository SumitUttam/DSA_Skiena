#include<bits/stdc++.h>

using namespace std;

int binarySearch1 (std::vector<int> arr, int key, int l, int r){    
    
    if (l>r) {
        if (arr[r+1]==key)
            return r+1;
        else return -1;
    }
    int m = (l+r)/2;
    if (arr[m]<key) {
        return binarySearch1(arr,key,m+1,r);
    }
    else {
        return binarySearch1(arr,key,l,m-1);
    }
}

//searches for rightmost occurance of element

int binarySearch2 (std::vector<int> arr, int key, int l, int r){
    if (l>r) {
        if (arr[r]==key)
            return r;
        else return -1;
    }
    int m = (l+r)/2;
    if (arr[m]>key) {
        return binarySearch2(arr,key,l,m-1);
    }
    else {
        return binarySearch2(arr,key,m+1,r);
    }
}


vector<int> searchRange(vector<int>& arr, int key) {
    if (arr.size()==0) return vector<int> {-1,-1};
    return vector<int> {binarySearch1(arr, key, 0, arr.size()), binarySearch2(arr, key, 0, arr.size())};
}

int main (){
    vector<int> arr {1};
    int key = 0;

    vector<int> ans = searchRange(arr,key);
    cout << ans[0] << " " << ans[1] << endl;
}