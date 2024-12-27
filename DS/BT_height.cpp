//Binary Tree Height in O(n) time;

#include<bits/stdc++.h>

class Node{
public:
    int key;
    //Buffer for Data
public:
    Node* left;
    Node* right;

public:
    Node(int key){
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
    }

    int find_height (){
        int height = 0;
        if (this == nullptr){
            return height;
        }

        height = std::max(height,this->left->find_height());
        height = std::max(height,this->right->find_height());
        
        return height+1;
    }
    

};

int main(){

    Node *root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(13);
    root->right->left = new Node(1);
    root->right->left->right = new Node(1);
    root->right->left->right->right = new Node(1);
    
    std::cout <<"The height of tree is: "<< root->find_height()<<std::endl;

    return 0;
}