//
// Created by 姚泽铭 on 31/3/20.
//

#ifndef AADS_ASS1_RANDOMIZEDTREAP_H
#define AADS_ASS1_RANDOMIZEDTREAP_H

#include "DataGenerator.h"

class TreapNode {

public:
    Element element{};
    int priority;

    TreapNode* left, *right;

    TreapNode(Element element);
    void insert(Element element);
    void delet(int key_del);
    Element search(int key_q);
    void displayTreap(TreapNode *root, int space = 0, int height =10);

private:
    static void rotLeft(TreapNode* &root);
    static void rotRight(TreapNode* &root);
    static void insert_node(TreapNode* root, Element element);
    void delete_node(TreapNode* &root, int key);
    Element* search_node(TreapNode* root, int key);
};





#endif //AADS_ASS1_RANDOMIZEDTREAP_H
