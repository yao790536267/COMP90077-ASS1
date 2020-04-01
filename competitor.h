//
// Created by 姚泽铭 on 31/3/20.
//

#ifndef AADS_ASS1_COMPETITOR_H
#define AADS_ASS1_COMPETITOR_H


#include <cstddef>
#include "DataGenerator.h"

#define MIN_CAPACITY 1
#define GROWTH_FACTOR 2


template <class T>
class DynamicArray {

public:
    DynamicArray();
    ~DynamicArray();

    void push_back(T value);
    T pop();
    void set(int index, T value);
    T get(int index);

    int  size();
    int  capacity();
    void print();
    int is_empty();

    void insert(T element);
    void delet(int key_del);
    T search(int search_key);


private:
    int m_size;
    int m_capacity;
    T* m_data;
    void resize();
    bool shrink();
};



#endif //AADS_ASS1_COMPETITOR_H
