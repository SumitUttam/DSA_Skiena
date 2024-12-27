#include<bits/stdc++.h>

// find subarray with largest sum in array with divide and conquer

int leftMidMax (std::vector<int> arr, int l, int m){
    int maxArr = INT_MIN;
    int s = 0;
    for (int i=m;i>=l;i--){
        s += arr[i];
        maxArr = std::max(maxArr,s);
    }
    return maxArr;
}


int rightMidMax (std::vector<int> arr, int r, int m){
    int maxArr = INT_MIN;
    int s = 0;
    for (int i=m+1;i<=r;i++){
        s += arr[i];
        maxArr = std::max(maxArr,s);
    }
    return maxArr;
}

int midUnion (std::vector<int> arr, int l, int r, int m){
    int lmax = leftMidMax(arr,l,m);
    int rmax = rightMidMax(arr,r,m);
    return std::max(lmax+rmax, std::max(lmax, rmax));
}


int maxSubrange (std::vector<int> arr, int l, int r){
    if (l==r){
        return arr[l];
    }
    int m = (l+r)/2;
    return std::max(
            maxSubrange(arr,l,m),
            std::max(
                maxSubrange(arr,m+1,r),
                midUnion(arr,l,r,m)
            )
                   );
}

int main() {
    std::vector<int> arr {-17,5,3,-10,6,1,4,-3,8,1,-13,4};
    std::cout<< maxSubrange(arr,0,arr.size()) << std::endl;
    return 0;
}