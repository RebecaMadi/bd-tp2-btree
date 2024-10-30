#include "Utils.hpp"
#include "../Record/Record.hpp"
#include <iostream>
#include <cstring>

namespace Utils {

MinHeap::MinHeap(void *heap, int cap, int size, int type) {
    this->capacity = cap;
    this->size = size;  
    this->heap = heap;
    this->type = type;
}

void MinHeap::insert(void* element) {
    ((void**)heap)[size] = element;  
    size++;                
    heapifyUp(size - 1);   
    
}

void MinHeap::removeMin() {
    ((void**)heap)[0] = ((void**)heap)[size - 1]; 
    size--;                  
    heapifyDown(0);  
    /*
    retfor (unsigned short i = 0; i < this->size; ++i) {
        static_cast<Record::Record*>(((void**)heap)[i])->display();
    }
    */
}

void* MinHeap::getMin() {
    if (size == 0) {
        return nullptr;
    }
    return ((void**)heap)[0];
}

void MinHeap::heapifyUp(int index) {
    int parent = (index - 1) / 2;
    if (index && getId(((void**)heap)[parent]) > getId(((void**)heap)[index])) {
        std::swap(((void**)heap)[parent], ((void**)heap)[index]);
        heapifyUp(parent);
    }
}

void MinHeap::heapifyDown(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < size && getId(((void**)heap)[leftChild]) < getId(((void**)heap)[smallest])) {
        smallest = leftChild;
    }

    if (rightChild < size && getId(((void**)heap)[rightChild]) < getId(((void**)heap)[smallest])) {
        smallest = rightChild;
    }

    if (smallest != index) {
        std::swap(((void**)heap)[index], ((void**)heap)[smallest]);
        heapifyDown(smallest); 
    }
}

int MinHeap::getId(void* record) {
    if (type == 0) {
        return static_cast<Record::Record*>(record)->id;
    }
    return -1; 
}

MinHeap::~MinHeap(){
    //free(&heap);
}

}