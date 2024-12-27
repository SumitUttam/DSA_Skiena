#include <bits/stdc++.h>
#include "mergeSort.h"

using namespace std;

int main (){
    vector<int> arr {5,9,23,14,17,6,3,2,7,8,10};
    mergeSort::mergeSort(arr);

    for (auto i:arr) cout << i << " ";
    cout << endl;
    return 0;
}