//
// Created by 姚泽铭 on 31/3/20.
//

#include <iostream>
#include "randomizedTreap.h"
using namespace std;

static TreapNode* treap_root = nullptr;

TreapNode::TreapNode(Element ele) {
    element.id = ele.id;
    element.key = ele.key;
    // priority range : [1, 100000]
    srand((unsigned)time(NULL));
    this->priority = (rand() % (100000-1+1))+ 1;
    this->left = this->right = nullptr;
}



// Left Rotation
void TreapNode::rotLeft(TreapNode* &root) {
    TreapNode* R = root->right;
    TreapNode* X = root->right->left;
    R->left = root;
    root->right = X;
    root = R;
}

//Right Rotation
void TreapNode::rotRight(TreapNode* &root) {
    TreapNode* L = root->left;
    TreapNode* Y = root->left->right;
    L->right = root;
    root->left = Y;
    root = L;
}

// Insertion
//void insert_node(TreapNode* &root, int key, int id) {
void TreapNode::insert_node(TreapNode* root, Element element) {
    if(root == nullptr) {
        std::cout<<"insert : treap root is null! \n";

//        root = new TreapNode(key, id);
        root = new TreapNode(element);
        treap_root = root;
        std::cout<<" insert success node priority is "<<root->priority<<"\n";
        return;
    }

//    if(key < root->search_key) {
//        insert_node(root->left, key, id);
    if(element.key < root->element.key) {
        insert_node(root->left, element);
        if (root->left != nullptr && root->left->priority > root->priority) {
            rotRight(root);
        }
    } else {
//        insert_node(root->right, key, id);
        insert_node(root->right, element);
        if (root->right != nullptr && root->right->priority > root->priority) {
            rotLeft(root);
        }
    }
}

// Deletion
void TreapNode::delete_node(TreapNode* &root, int key) {
    //node to be deleted which is a leaf node
    if (root == nullptr) {
        return;
    }
//    if (key < root->search_key) {
    if (key < root->element.key) {
        delete_node(root->left, key);
    }
//    else if (key > root->search_key) {
    else if (key > root->element.key) {
        delete_node(root->right, key);
        //node to be deleted which has two children
    }
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        else if (root->left && root->right) {
            if (root->left->priority < root->right->priority) {
                rotLeft(root);
                delete_node(root->left, key);
            } else {
                rotRight(root);
                delete_node(root->right, key);
            }
        }
        else {
            TreapNode* child = (root->left)? root->left:root->right;
            TreapNode* curr = root;
            root = child;
            delete curr;
        }
    }
}

// Search
Element* TreapNode::search_node(TreapNode* root, int key) {
    if (root == nullptr) {
        std::cout<<" not found - null treap_root !\n";
        return nullptr;
    }

//    if (root->search_key == key) {
    if (root->element.key == key) {
//        int id = root->id;
//        Element ele;
//        ele.id = id;
//        ele.key = key;
//        Element ele = root->element;
        return &(root->element);
    }
//    if (key < root->search_key) {
    if (key < root->element.key) {
        return search_node(root->left, key);
    }
    return search_node(root->right, key);
}

//
void TreapNode::insert(Element element){
//    int key = element.key;
//    int id = element.id;
//    insert_node(treap_root, key, id);
    insert_node(treap_root, element);
}

void TreapNode::delet(int key_del) {
    delete_node(treap_root, key_del);
}

Element TreapNode::search(int key_q) {
    if (treap_root == nullptr) {
        std::cout<<"first search: treap root is null! \n";
    }
    Element* ele = search_node(treap_root, key_q);
    if (ele != nullptr) {
        std::cout<<"find!! id:"<<ele->id<<" key:"<<ele->key<<"\n";
    }
    else {
        std::cout<<" search failed\n";
    }
    return *ele;
}

// display
void TreapNode::displayTreap(TreapNode *root, int space, int height) {
    if (root == nullptr)
        return;
    space += height;
    displayTreap(root->left, space);
    std::cout << std::endl;
    for (int i = height; i < space; i++)
        std::cout << ' ';
    std::cout << root->element.key << "(" << root->priority << ")\n";
    std::cout << std::endl;
    displayTreap(root->right, space);
}