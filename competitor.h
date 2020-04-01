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


template <class T>
DynamicArray<T>::DynamicArray() {
    m_capacity = MIN_CAPACITY;
    m_size = 0;
    m_data = (T*)malloc(m_capacity * sizeof(*m_data));
    if (!m_data) {
        throw std::bad_alloc();
    }
}

template <class T>
DynamicArray<T>::~DynamicArray() {
    free(m_data);
}

template <class T>
void DynamicArray<T>::push_back(T value) {
    if (m_size >= m_capacity) {
        resize();
    }
    *(m_data + m_size++) = value;
}

template <class T>
void DynamicArray<T>::resize() {
    int capacity = m_capacity*GROWTH_FACTOR;
    T *tmp = (T*)realloc(m_data, capacity * sizeof(*m_data));
    if (!tmp)
        throw std::bad_alloc();
    // copy
    for(int index = 0; index < m_size; index++) {
        *(tmp + index) = *(m_data + index);
    }
    m_data = tmp;
    m_capacity = capacity;
}

template <class T>
T DynamicArray<T>::pop() {
    return *(m_data + --m_size);
}

template <class T>
T DynamicArray<T>::get(int index) {
    return *(m_data + index);
}

template <class T>
void DynamicArray<T>::set(int index, T value) {
    while (index >= m_size)
        this->push_back(0);
    *(m_data + index) = value;
}

template <class T>
void DynamicArray<T>::print() {
    int i = 0;
    if (m_size == 0) {
        std::cout<<"nothing to print \n";
        return;
    }
    std::cout<<"about to print \n";
    while (i < m_size) {
        T tmp = this->get(i);
        std::cout << "Dynamic Array[" << i << "]: id= " << tmp.id << "and key= " << tmp.key << "\n";
        i++;
    }
}

template <class T>
int DynamicArray<T>::is_empty() {
    return m_size == 0;
}

template <class T>
bool DynamicArray<T>::shrink() {
    int capacity = m_capacity/2;
    T *tmp = (T*)realloc(m_data, capacity * sizeof(*m_data));
    if (!tmp)
        throw std::bad_alloc();
    // copy
    for(int index = 0; index < m_size; index++) {
        *(tmp + index) = *(m_data + index);
    }
    T* data_to_del = m_data;
    delete[] data_to_del;
    m_data = tmp;
    m_capacity = capacity;
}

template <class T>
void DynamicArray<T>::insert(T element) {
    push_back(element);
}

template <class T>
void DynamicArray<T>::delet(int key_del) {

    int search_key_del = key_del;
    int index = 0;
    for (; index < m_size; index ++) {
        T ele = *(m_data + index);
        int ele_key = ele.key;
        if (ele_key == search_key_del) {
            T last_ele = *(m_data + m_size - 1);
            *(m_data + index) = last_ele;
            *(m_data + m_size - 1) = ele;
            pop();
            if (m_size < m_capacity/4) {
                shrink();
            }
        }
    }


}

template <class T>
T DynamicArray<T>::search(int search_key) {
    int index = 0;
    for (; index < m_size; index ++) {
        T ele = *(m_data + index);
        int ele_key = ele.key;
        if (ele_key == search_key) {
            return ele;
        }
    }
    Element no_ele;
    no_ele.id = -1;
    return no_ele;
}

#endif //AADS_ASS1_COMPETITOR_H
