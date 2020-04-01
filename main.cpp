#include <iostream>

#include "DataGenerator.h"
#include "randomizedTreap.h"
#include "competitor.h"
#include <ctime>
#include <cstdlib>
#include "Element.h"

using namespace std;


int main() {
    Treap bst;
    // test insert
    Element ele = Element(5,5);
    srand((unsigned)time(NULL));
    int pri = (rand() % (1000000-1+1))+ 1;
    bst.insert(ele,pri);
    ele = Element(7,7);
    pri = (rand() % (1000000-1+1))+ 1;
    bst.insert(ele,pri);
    ele = Element(19,19);
    pri = (rand() % (1000000-1+1))+ 1;
    bst.insert(ele,pri);
    ele = Element(23,23);
    pri = (rand() % (1000000-1+1))+ 1;
    bst.insert(ele,pri);
    ele = Element(30,30);
    pri = (rand() % (1000000-1+1))+ 1;
    bst.insert(ele,pri);
    ele = Element(31,31);
    pri = (rand() % (1000000-1+1))+ 1;
    bst.insert(ele,pri);
    ele = Element(45,45);
    pri = (rand() % (1000000-1+1))+ 1;
    bst.insert(ele,pri);
    ele = Element(48,48);
    pri = (rand() % (1000000-1+1))+ 1;
    bst.insert(ele,pri);
    ele = Element(51,51);
    pri = (rand() % (1000000-1+1))+ 1;
    bst.insert(ele,pri);
    ele = Element(25,25);
    pri = (rand() % (1000000-1+1))+ 1;
    bst.insert(ele,pri);
    bst.prettyPrint();
    cout<<endl;
    bst.inorder();
    cout<<endl;
    // search
    NodePtr temp_node_ptr= bst.searchTree(7);
    cout<<"search result node'skey is : "<<temp_node_ptr->priority<<endl;
    // test delete
    bst.deleteNode(45);
    bst.prettyPrint();
    cout<<endl;
    bst.inorder();
    cout<<endl;


    return 0;
}