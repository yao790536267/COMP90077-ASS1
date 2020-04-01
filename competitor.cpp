//
// Created by 姚泽铭 on 31/3/20.
//

#include <new>
#include <iostream>
#include "competitor.h"
using namespace std;

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




// debug Dynamic array
//
//int m1ain () {
//    DynamicArray<Element> arr;
//    arr.print();
//    std::cout<<" about to insert \n";
//    Element ele;
//    ele.id = 1;
//    ele.key = 1;
//    arr.insert(ele);
//    arr.print();
//    std::cout<<" about to search \n";
//    Element ele2 = arr.search(1);
//    std::cout << "Dynamic Array search: id= " << ele2.id << "  and key= " << ele2.key << "\n";
//    std::cout<<" about to delete \n";
//    arr.delet(1);
//    arr.print();
//
//    return 0;
//}









