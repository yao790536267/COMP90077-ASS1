//
// Created by 姚泽铭 on 31/3/20.
//

#ifndef AADS_ASS1_DATAGENERATOR_H
#define AADS_ASS1_DATAGENERATOR_H


//#include "DataGenerator.h"
#include <vector>
#include <map>
#include "Element.h"

#define M 1000000

static int id_next = 1;
static std::vector<int> id_del_vector = {};
static std::map<int, int> elements_alive = {};

enum OPERATIONTYPE {INSERTION, DELETION, SEARCH};

//struct Element {
//    int id;
//    int key;
//};

// Union WAIT
union Operation {
    OPERATIONTYPE operation_type;
    int key_del;
    int key_search;
    Element element;
};


Element gen_element();

Operation gen_insertion();

Operation gen_deletion();

Operation gen_search();

// ex1
Operation* generate_5_insertion_seq(int length);


#endif //AADS_ASS1_DATAGENERATOR_H
