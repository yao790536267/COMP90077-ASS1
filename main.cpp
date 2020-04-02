#include <iostream>

#include "DataGenerator.h"
#include "Treap.h"
#include "DynamicArray.h"
#include <ctime>
#include <cstdlib>
#include "Element.h"

using namespace std;

/*
 *  Dynamic array definition
 */

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

//    int  size();
////    int  capacity();
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
        std::cout << "Dynamic Array[" << i << "]: id= " << tmp.id << "  and key= " << tmp.key << "\n";
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
    return true;
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



int main() {
    srand((unsigned)time(NULL));
    Element element;
    Data_generator generator1 = Data_generator();

    //  TEST Treap
//    Treap bst;
//    // test insert
//    Element ele = Element(5,5);
//    int pri = (rand() % (1000000-1+1))+ 1;
//    bst.insert(ele,pri);
//    ele = Element(7,7);
//    pri = (rand() % (1000000-1+1))+ 1;
//    bst.insert(ele,pri);
//    ele = Element(19,19);
//    pri = (rand() % (1000000-1+1))+ 1;
//    bst.insert(ele,pri);
//    ele = Element(23,23);
//    pri = (rand() % (1000000-1+1))+ 1;
//    bst.insert(ele,pri);
//    ele = Element(30,30);
//    pri = (rand() % (1000000-1+1))+ 1;
//    bst.insert(ele,pri);
//    ele = Element(31,31);
//    pri = (rand() % (1000000-1+1))+ 1;
//    bst.insert(ele,pri);
//    ele = Element(45,45);
//    pri = (rand() % (1000000-1+1))+ 1;
//    bst.insert(ele,pri);
//    ele = Element(48,48);
//    pri = (rand() % (1000000-1+1))+ 1;
//    bst.insert(ele,pri);
//    ele = Element(51,51);
//    pri = (rand() % (1000000-1+1))+ 1;
//    bst.insert(ele,pri);
//    ele = Element(25,25);
//    pri = (rand() % (1000000-1+1))+ 1;
//    bst.insert(ele,pri);
//    bst.prettyPrint();
//    cout<<endl;
//    bst.inorder();
//    cout<<endl;
//    // search
//    NodePtr temp_node_ptr= bst.searchTree(7);
//    cout<<"search result node'skey is : "<<temp_node_ptr->priority<<endl;
//    // test delete
//    bst.deleteNode(45);
//    bst.prettyPrint();
//    cout<<endl;
//    bst.inorder();
//    cout<<endl;



//    // TEST dynamic array
//    DynamicArray<Element> arr;
//    arr.print();
//    Element ele;
//    ele.id = 1;
//    ele.key = 1;
//    arr.insert(ele);
//    arr.print();
//    ele.id = 2;
//    ele.key = 2;
//    arr.insert(ele);
//    arr.print();

    // count running time
    clock_t start = clock();

//    /*
//     * Experiment 1 - dynamic array
//     */
//    DynamicArray<Element> array;
//    for (int i=0; i < 1000000; i++) {
//        int key = (rand() % (1000000-1+1))+ 1;
//        element = generator1.gen_element(key);
//        array.insert(element);
//    }
//    array.print();

    /*
     * Experiment 1 - Treap
     */

//    Treap treap;
//    for (int i=0; i < 1000000; i++) {
//        int pri = (rand() % (10000000-1+1))+ 1;
//        int key = (rand() % (10000000-1+1))+ 1;
//        element = generator1.gen_element(key);
//        treap.insert(element,pri);
//    }
//    treap.prettyPrint();

    /*
     * Experiment 2 - dynamic array
     */
//    DynamicArray<Element> array;
//    for (int i=0; i < 1000000; i++) {
//        if ( 100 >= (rand() % (1000-1+1))+ 1) {
//            int key_del = (rand() % (1000000-1+1))+ 1;
//            array.delet(key_del);
//        }
//        else {
//            int key = (rand() % (1000000-1+1))+ 1;
//            element = generator1.gen_element(key);
//            array.insert(element);
//        }
//    }
//    array.print();

    /*
     * Experiment 2 - Treap
     */

//    Treap treap;
//    for (int i=0; i < 1000000; i++) {
//        if (100 >= (rand() % (1000 - 1 + 1)) + 1) {
//            int key_del = (rand() % (1000000 - 1 + 1)) + 1;
//            treap.deleteNode(key_del);
//        } else {
//            int pri = (rand() % (10000000 - 1 + 1)) + 1;
//            int key = (rand() % (10000000 - 1 + 1)) + 1;
//            element = generator1.gen_element(key);
//            treap.insert(element, pri);
//        }
//    }
//    treap.prettyPrint();

    /*
     * Experiment 3 - Dynamic array
     */
//    DynamicArray<Element> array;
//    for (int i=0; i < 1000000; i++) {
//        if (100 >= (rand() % (1000 - 1 + 1)) + 1) {
//            int key_search = (rand() % (1000000 - 1 + 1)) + 1;
//            array.search(key_search);
//        } else {
//            int key = (rand() % (10000000 - 1 + 1)) + 1;
//            element = generator1.gen_element(key);
//            array.insert(element);
//        }
//    }

    /*
     * Experiment 3 - Treap
     */
//    Treap treap;
//    for (int i=0; i < 1000000; i++) {
//        if (100 >= (rand() % (1000 - 1 + 1)) + 1) {
//            int key_search = (rand() % (1000000 - 1 + 1)) + 1;
//            treap.searchTree(key_search);
//        } else {
//            int pri = (rand() % (10000000 - 1 + 1)) + 1;
//            int key = (rand() % (10000000 - 1 + 1)) + 1;
//            element = generator1.gen_element(key);
//            treap.insert(element, pri);
//        }
//    }

    /*
     * Experiment 4 - Dynamic array
     */
//    DynamicArray<Element> array;
//    for (int i=0; i < 1000000; i++) {
//        int randomNum = (rand() % (100 - 1 + 1)) + 1;
//        if (5 >= randomNum) {
//            // del
//            int key_del = (rand() % (1000000 - 1 + 1)) + 1;
//            array.delet(key_del);
//        }
//        else if(randomNum > 5 && randomNum <=10) {
//            // search
//            int key_search = (rand() % (1000000 - 1 + 1)) + 1;
//            array.search(key_search);
//        }
//        else {
//            int key = (rand() % (10000000 - 1 + 1)) + 1;
//            element = generator1.gen_element(key);
//            array.insert(element);
//        }
//    }

    /*
     * Experiment 4 - Treap
     */
    Treap treap;
    for (int i=0; i < 1000000; i++) {
        int randomNum = (rand() % (100 - 1 + 1)) + 1;
        if (5 >= randomNum) {
            // del
            int key_del = (rand() % (1000000 - 1 + 1)) + 1;
            treap.deleteNode(key_del);
        }
        else if(randomNum > 5 && randomNum <=10) {
            // search
            int key_search = (rand() % (1000000 - 1 + 1)) + 1;
            treap.searchTree(key_search);
        }
        else {
            int pri = (rand() % (10000000 - 1 + 1)) + 1;
            int key = (rand() % (10000000 - 1 + 1)) + 1;
            element = generator1.gen_element(key);
            treap.insert(element, pri);
        }
    }

// count running time
    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}