//
// Created by 姚泽铭 on 1/4/20.
//

#ifndef AADS_ASS1_ELEMENT_H
#define AADS_ASS1_ELEMENT_H

struct Element {
    int id;
    int key;
    Element():id(), key(){}
    Element(int id1, int key1): id(id1), key(key1){}
};

#endif //AADS_ASS1_ELEMENT_H
