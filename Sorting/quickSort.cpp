#include<bits/stdc++.h>
#include"quickSort.h"

int main (){
    std::vector<int> arr {5,9,2,1,3,7,4,6,8};

    quickSort::quickSort(arr);

    for (auto i: arr){
        std::cout << i<< " ";
    }

    std::cout << std::endl;
    return 0;
}