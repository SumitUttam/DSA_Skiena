#include "bst.h"
#include <bits/stdc++.h>

using namespace BST;

bst *sorted2balancedBST (std::vector<int> keys, int i, int j){
    int mid = (i+j)/2;
    if (i > j){
        return nullptr;
    }
    bst *root = new bst(keys[mid]);
    std::cout << keys[mid] << std::endl;
    root->left = sorted2balancedBST(keys, i, mid-1);
    root->right = sorted2balancedBST(keys, mid+1, j);

    return root;
}

bst *sorted2balancedBST (std::vector<int> keys){
    return sorted2balancedBST(keys, 0, keys.size()-1);
}

int main(){
    bst root (3);
    root.insertNode(5);
    root.insertNode(6);
    root.insertNode(2);
    root.insertNode(1);
    root.insertNode(8);
    root.insertNode(7);
    root.insertNode(4);
    root.insertNode(9);

    bst *root2 = sorted2balancedBST(root.inorderVector());

    std::cout << "Balanced BST" << std::endl;
    for (int i: root2->inorderVector()) 
        std::cout<<i<<" ";
    std::cout << std::endl; 

}