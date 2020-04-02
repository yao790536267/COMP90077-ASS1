//
// Created by 姚泽铭 on 31/3/20.
//

#ifndef AADS_ASS1_DATAGENERATOR_H
#define AADS_ASS1_DATAGENERATOR_H


//#include "DataGenerator.h"
#include <vector>
#include <map>
#include "Element.h"


static int id_next = 1;

class Data_generator {

private:
    int id_next;


public:
    Element gen_element(int key);
    Data_generator();
};

#endif //AADS_ASS1_DATAGENERATOR_H
