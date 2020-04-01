//
// Created by 姚泽铭 on 31/3/20.
//

#ifndef AADS_ASS1_DATAGENERATOR_H
#define AADS_ASS1_DATAGENERATOR_H


#include "DataGenerator.h"
#include <vector>
#include <map>

static int id_next = 1;
static std::vector<int> id_del_vector = {};
static std::map<int, int> elements_alive = {};

enum OPERATIONTYPE {INSERTION, DELETION, SEARCH};

struct Element {
    int id;
    int key;
};

// Union WAIT
struct Operation {
    OPERATIONTYPE operation_type;
    int key_del;
    int key_search;
    Element element;
};


Element gen_element() {
    int id = id_next;
    id_next++;
    srand((unsigned)time(NULL));
    int key = (rand() % (10000000-0+1))+ 0;
    Element element;
    element.id = id;
    element.key = key;
    return element;
}

Operation gen_insertion() {
    Element element = gen_element();
    Operation insertion;
    insertion.element = element;
    insertion.operation_type = INSERTION;
    return  insertion;
}

Operation gen_deletion() {
    srand((unsigned)time(NULL));
    int id_del = (rand() % (id_next - 1 - 1 + 1)) + 1;

    std::vector<int>::iterator ite = find(id_del_vector.begin(), id_del_vector.end(), id_del);
    if(ite != id_del_vector.end()) {
        int key_del = (rand() % (10000000-0+1))+ 0;
        Operation deletion;
        deletion.operation_type = DELETION;
        deletion.key_del = key_del;
        // record delete id WAIT
        return deletion;
    }
    else {
        // return a deletion for deleting the search key x.key WAIT
        Operation deletion;
        deletion.operation_type = DELETION;
        //find element in elements_alive
        std::map<int, int>::iterator it = elements_alive.find(id_del);
        if(it != elements_alive.end()) {
            deletion.key_del = elements_alive[id_del];
        }

        return deletion;
    }

}

Operation gen_search() {
    srand((unsigned)time(NULL));
    int q = (rand() % (10000000-0+1))+ 0;
    Operation search;
    search.operation_type = SEARCH;
    search.key_search = q;
    return search;
}


#endif //AADS_ASS1_DATAGENERATOR_H
