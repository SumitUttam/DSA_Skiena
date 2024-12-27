#include <bits/stdc++.h>

//Not Complete Yet;

//right rotate, left rotate;

//      y                               x
//     / \     Right Rotation          /  \
//    x   T3   - - - - - - - >        T1   y 
//   / \       < - - - - - - -            / \
//  T1  T2     Left Rotation            T2  T3

namespace AVL{
    class avl{
        int key;
        // data;

        public:
        avl *left, *right;
        int height;

        avl (int x){
            key = x;
            left = nullptr;
            right = nullptr;
            height = 1;
        }

        int insert (int x){
            if (key > x){
                if (left == nullptr) {
                    left = new avl(x);
                    height++;
                }
                else height += left->insert(x);
            }
            else {
                if (right == nullptr){
                    right = new avl(x);
                    height--;
                }
                else height -= right->insert(x);
            }
            return (!height?0:1);
        }

        friend avl *rotateRight (avl *root);
        friend avl *rotateLeft (avl *root);
        

        void inorderBal (){
            if (left!=nullptr) left->inorderBal();
            std::cout << key <<" "<< height <<std::endl;
            if (right!=nullptr) right->inorderBal();
        }

        int Height(){
            if (this == nullptr){
                return 0;
            }
            return height;
        }

    };

    avl *rotateRight(avl *root){
        avl *T2 = root->left->right; 
        root->left->right = root;
        root = root->left;
        root->right->left = T2;

        root->left->height = std::max(root->left->right->Height(),root->left->right->Height())+1;
        root->height = std::max(root->left->Height(),root->right->Height())+1;

        return root;
    }


    avl *rotateLeft(avl *root){
        avl *T2 = root->right->left; 
        root->right->left = root;
        root = root->right;
        root->left->right = T2;

        root->right->height = std::max(root->right->right->Height(),root->right->right->Height())+1;
        root->height = std::max(root->left->Height(),root->right->Height())+1;

        return root;
    }
}

int main (){
    AVL::avl root(6);
    root.inorderBal();
    std::cout << std::endl;
    root.insert(5);
    root.inorderBal();
    std::cout << std::endl;
    root.insert(3);
    root.inorderBal();
    std::cout << std::endl;
    root.insert(4);
    root.inorderBal();
    std::cout << std::endl;
    root.insert(7);
    root.inorderBal();
    std::cout << std::endl;
    root.insert(9);
    root.inorderBal();
    std::cout << std::endl;
    root.insert(2);
    root.inorderBal();
    std::cout << std::endl;
    root.insert(1);
    root.inorderBal();
    std::cout << std::endl;
    root.insert(8);

    root.inorderBal();
    std::cout << std::endl;


    return 0;
}