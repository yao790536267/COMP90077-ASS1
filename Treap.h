//
// Created by 姚泽铭 on 31/3/20.
//

#ifndef AADS_ASS1_TREAP_H
#define AADS_ASS1_TREAP_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Element.h"

using namespace std;

// data structure that represents a node in the tree
struct Node {
//    int data; // holds the key
    Element element; // hold the key and id
    float priority; // priority of the node
    Node *parent; // pointer to the parent
    Node *left; // pointer to left child
    Node *right; // pointer to right child
};


typedef Node *NodePtr;

// class Treap implements the operations in Treap Data Structure
class Treap {
private:
    NodePtr root;

    void preOrderHelper(NodePtr node);


    void inOrderHelper(NodePtr node);

    void postOrderHelper(NodePtr node);

    NodePtr searchTreeHelper(NodePtr node, int key);


    void printHelper(NodePtr root, string indent, bool last);

    // rotate left at node x
    void leftRotate(NodePtr x) ;

    // rotate right at node x
    void rightRotate(NodePtr x);

    // we move the node up until its priority is greater than
    // or equal the parent's priority
    void moveUp(NodePtr x);

    // delete key k
    void deleteNodeHelper(NodePtr node, int k);
    // move down x to the leaf of the tree
    void moveDown(NodePtr x);

public:
    Treap();
    // Pre-Order traversal
    // Node->Left Subtree->Right Subtree
    void preorder();

    // In-Order traversal
    // Left Subtree -> Node -> Right Subtree
    void inorder();
    // Post-Order traversal
    // Left Subtree -> Right Subtree -> Node
    void postorder();

    // search the tree for the key k
    // and return the corresponding node
    NodePtr searchTree(int k);

    // find the node with the minimum key
    NodePtr minimum(NodePtr node);

    // find the node with the maximum key
    NodePtr maximum(NodePtr node) ;

    // find the successor of a given node
    NodePtr successor(NodePtr x);

    // find the predecessor of a given node
    NodePtr predecessor(NodePtr x);

    // insert the key to the tree in its appropriate position
//    void insert(int key, float priority);
    void insert(Element element, float priority);

    // split the tree into two trees
//    void split(int x, Treap* t1, Treap* t2);

    // merge trees t1 and t2
    void merge(Treap t1, Treap t2);
    NodePtr getRoot();

    // delete the node from the tree
    void deleteNode(int key);

    // print the tree structure on the screen
    void prettyPrint();

//    void insert(Element element);
};




#endif //AADS_ASS1_TREAP_H
