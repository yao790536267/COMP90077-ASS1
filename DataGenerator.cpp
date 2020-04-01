//
// Created by 姚泽铭 on 31/3/20.
//

#include <cstdlib>
#include <sys/time.h>
#include "DataGenerator.h"
using namespace std;

//ex1
Operation* generate_5_insertion_seq(int length) {
    Operation array1[length];
    for (int i = 0; i < length; i++){
        Element element = gen_element();
        Operation operation;
        operation.element = element;
        operation.operation_type = INSERTION;
        array1[i] = operation;
    }

}


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
