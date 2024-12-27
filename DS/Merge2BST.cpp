#include "bst.h"

std::vector<int> mergeSorted (std::vector<int> a1,
                              std::vector<int> a2)
{
    std::vector<int> res;

    int i=0, j=0;

    while (i<a1.size() && j<a2.size() ){
        if (a1[i] < a2[j])
            res.push_back(a1[i++]);

        else 
            res.push_back(a2[j++]);
    }

    while (i<a1.size())
        res.push_back(a1[i++]);

    while (j<a2.size())
        res.push_back(a2[j++]);

    return res;
}

int main (){
    BST::bst root (3);
    root.insertNode(5);
    root.insertNode(2);
    root.insertNode(2);
    root.insertNode(1);

    std::vector<int> inor;
    root.inorder(inor);   


    std::cout << "BST 1 Inorder" << std::endl;
    for (int i: inor) 
        std::cout<<i<<" ";
    std::cout << std::endl;


    BST::bst root2 (6);
    root2.insertNode(8);
    root2.insertNode(7);
    root2.insertNode(4);
    root2.insertNode(9);

    std::vector<int> inor2 = root2.inorderVector();

    std::cout << "BST 2 Inorder" << std::endl;
    for (int i: inor2) 
        std::cout<<i<<" ";
    std::cout << std::endl;  

    std::vector<int> res;

    res = mergeSorted(inor, inor2);


    std::cout << "Merged Vector" << std::endl;
    for (int i: res) 
        std::cout<<i<<" ";
    std::cout << std::endl; 
    
}