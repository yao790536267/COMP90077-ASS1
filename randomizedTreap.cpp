//
// Created by 姚泽铭 on 31/3/20.
//

#include <iostream>
#include "randomizedTreap.h"
#include <ctime>
using namespace std;

// class Treap implements the operations in Treap Data Structure
    void Treap::preOrderHelper(NodePtr node) {
        if (node != nullptr) {
            cout<<node->element.key<<" ";
            preOrderHelper(node->left);
            preOrderHelper(node->right);
        }
    }

    void Treap::inOrderHelper(NodePtr node) {
        if (node != nullptr) {
            inOrderHelper(node->left);
            cout<<node->element.key<<" ";
            inOrderHelper(node->right);
        }
    }

    void Treap::postOrderHelper(NodePtr node) {
        if (node != nullptr) {
            postOrderHelper(node->left);
            postOrderHelper(node->right);
            cout<<node->element.key<<" ";
        }
    }

    NodePtr Treap::searchTreeHelper(NodePtr node, int key) {
        if (node == nullptr || key == node->element.key) {
            return node;
        }

        if (key < node->element.key) {
            return searchTreeHelper(node->left, key);
        }
        return searchTreeHelper(node->right, key);
    }



    void Treap::printHelper(NodePtr root, string indent, bool last) {
        // print the tree structure on the screen
        if (root != nullptr) {
            cout<<indent;
            if (last) {
                cout<<"└────";
                indent += "     ";
            } else {
                cout<<"├────";
                indent += "|    ";
            }

            cout<<root->element.key<<"("<<root->priority<<")"<<endl;

            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }

    // rotate left at node x
    void Treap::leftRotate(NodePtr x) {
        NodePtr y = x->right;
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    // rotate right at node x
    void Treap::rightRotate(NodePtr x) {
        NodePtr y = x->left;
        x->left = y->right;
        if (y->right != nullptr) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    // we move the node up until its priority is greater than
    // or equal the parent's priority
    void Treap::moveUp(NodePtr x) {
        if (x->parent == nullptr) {
            return;
        }
        if (x->parent != nullptr && x->priority >= x->parent->priority) {
            return;
        }

        if (x == x->parent->left) {
            rightRotate(x->parent);
        } else {
            leftRotate(x->parent);
        }

        // recursively move the x up
        moveUp(x);
    }

    // delete key k
    void Treap::deleteNodeHelper(NodePtr node, int k) {
        // find k
        NodePtr x = nullptr;
        while (node != nullptr) {
            if (node->element.key == k) {
                x = node;
                break;
            }

            if (node->element.key <= k) {
                node = node->right;
            } else {
                node = node->left;
            }
        }

        if (x == nullptr) {
            cout<<"couldn't find the "<<k<<" in the treap"<<endl;
            return;
        }

        // move down x
        moveDown(x);

        // in this point x is in the leaf node
        // delete x
        if (x == x->parent->left) {
            x->parent->left = nullptr;
        } else {
            x->parent->right = nullptr;
        }
        delete x;
        x = nullptr;
    }

    // move down x to the leaf of the tree
    void Treap::moveDown(NodePtr x) {
        if (x->left == nullptr && x->right == nullptr) {
            return;
        }

        if (x->left != nullptr && x->right != nullptr) {
            if (x->left->priority < x->right->priority) {
                rightRotate(x);
            } else {
                leftRotate(x);
            }
        } else if (x->left != nullptr) {
            rightRotate(x);
        } else {
            leftRotate(x);
        }

        moveDown(x);
    }

    // Public
Treap::Treap() {
        root = nullptr;
    }

    // Pre-Order traversal
    // Node->Left Subtree->Right Subtree
    void Treap::preorder() {
        preOrderHelper(this->root);
    }

    // In-Order traversal
    // Left Subtree -> Node -> Right Subtree
    void Treap::inorder() {
        inOrderHelper(this->root);
    }

    // Post-Order traversal
    // Left Subtree -> Right Subtree -> Node
    void Treap::postorder() {
        postOrderHelper(this->root);
    }

    // search the tree for the key k
    // and return the corresponding node
    NodePtr Treap::searchTree(int k) {
        return searchTreeHelper(this->root, k);
    }

    // find the node with the minimum key
    NodePtr Treap::minimum(NodePtr node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // find the node with the maximum key
    NodePtr Treap::maximum(NodePtr node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    // find the successor of a given node
    NodePtr Treap::successor(NodePtr x) {
        // if the right subtree is not null,
        // the successor is the leftmost node in the
        // right subtree
        if (x->right != nullptr) {
            return minimum(x->right);
        }

        // else it is the lowest ancestor of x whose
        // left child is also an ancestor of x.
        NodePtr y = x->parent;
        while (y != nullptr && x == y->right) {
            x = y;
            y = y->parent;
        }
        return y;
    }

    // find the predecessor of a given node
    NodePtr Treap::predecessor(NodePtr x) {
        // if the left subtree is not null,
        // the predecessor is the rightmost node in the
        // left subtree
        if (x->left != nullptr) {
            return maximum(x->left);
        }

        NodePtr y = x->parent;
        while (y != nullptr && x == y->left) {
            x = y;
            y = y->parent;
        }

        return y;
    }

//void Treap::insert(Element element) {
//    srand((unsigned)time(NULL));
//    int pri = (rand() % (1000000-1+1))+ 1;
//    insert(element, pri);
//    }

    // insert the key to the tree in its appropriate position
    void Treap::insert(Element element, float priority) {
        NodePtr node = new Node;
        node->parent = nullptr;
        node->left = nullptr;
        node->right = nullptr;
        node->element.key = element.key;
        node->priority = priority;
        NodePtr y = nullptr;
        NodePtr x = this->root;

        while (x != nullptr) {
            y = x;
            if (node->element.key < x->element.key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        // y is parent of x
        node->parent = y;
        if (y == nullptr) {
            root = node;
        } else if (node->element.key < y->element.key) {
            y->left = node;
        } else {
            y->right = node;
        }

        // rotate the tree to fix the priorities.
        if (node->parent != nullptr) {
            moveUp(node);
        }
    }

    // split the tree into two trees
//    void Treap::split(int x, Treap* t1, Treap* t2) {
//        // insert a dummy node with lowest priority
//        this->insert(x, -99);
//
//        // this node is in the root node
//        t1->root = this->root->left;
//        t2->root = this->root->right;
//
//        this->root->left = nullptr;
//        this->root->right = nullptr;
//        delete this->root;
//        this->root = nullptr;
//    }

    // merge trees t1 and t2
    void Treap::merge(Treap t1, Treap t2) {
        // find the largest node in t1
        NodePtr largest = t1.maximum(t1.root);
        // find the smallest node in t2
        NodePtr smallest = t2.minimum(t2.root);

        // create a dummy node
        NodePtr newRoot = new Node();
        newRoot->element.key = (largest->element.key + smallest->element.key) / 2;
        newRoot->left = t1.root;
        newRoot->right = t2.root;
        newRoot->parent = nullptr;
        newRoot->priority = 99;

        // move down the dummy node to the leaf node
        moveDown(newRoot);

        NodePtr currPtr = newRoot;
        while(currPtr->parent != nullptr) {
            currPtr = currPtr->parent;
        }

        this->root = currPtr;

        if (newRoot == newRoot->parent->left) {
            newRoot->parent->left = nullptr;
        } else {
            newRoot->parent->right = nullptr;
        }

        // delete the dummy node
        delete(newRoot);
        newRoot = nullptr;

    }

    NodePtr Treap::getRoot(){
        return this->root;
    }

    // delete the node from the tree
    void Treap::deleteNode(int data) {
        deleteNodeHelper(this->root, data);
    }

    // print the tree structure on the screen
    void Treap::prettyPrint() {
        printHelper(this->root, "", true);
    }


