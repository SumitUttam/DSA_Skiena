#pragma once
#ifndef BST_H
#define BST_H

#include <bits/stdc++.h>


namespace BST
{
    class bst
    {
    private:
        int key;
        //data
    public:
        bst *left;
        bst *right;

    
        bst (int x);
        bst* insertNode (int x);
        void inorder ();
        void inorder (std::vector<int> &vec);
        std::vector<int> inorderVector();
    };


    bst::bst (int x){
        key = x;
        left = nullptr;
        right = nullptr;
    }

    bst* bst::insertNode (int x){
        if (this == nullptr)
            return new bst(x);
        if (x > key)
            this->right = this->right->insertNode(x);

        else if (x < key)
            this->left = this->left->insertNode(x);

        else {
            std::cout << "Key already exsists in Tree" << std::endl;
        }
        return this;
    }

    void bst::inorder (){
        if (this == nullptr) return;

        this->left->inorder();
        std::cout << this->key << std::endl;
        this->right->inorder();
    }

    void bst::inorder (std::vector<int> &vec){
        if (this == nullptr) return;

        this->left->inorder(vec);
        vec.push_back(this->key);
        this->right->inorder(vec);
    }

    std::vector<int> bst::inorderVector (){
        std::vector<int> res;
        this->inorder(res);
        return res;
    }


}



#endif