#include <iostream>

#include "DataGenerator.h"
#include "randomizedTreap.h"
#include "competitor.h"


int main() {
    Element ele;
    ele.id = 1;
    ele.key = 1;
    TreapNode *node = new TreapNode(ele);
    node->search(1);

    Element ele1;
    ele1.id = 2;
    ele1.key = 2;
    node->insert(ele1);

}