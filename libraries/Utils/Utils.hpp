#ifndef UTILS_H
#define UTILS_H

namespace Utils{

class MinHeap {
public:
    void* heap;        
    int capacity;     
    int size;         
    int type;
    
    void heapifyUp(int index);

    void heapifyDown(int index);
    
    MinHeap(void *heap, int cap, int size, int type);

    void insert(void *element);

    void removeMin();

    void* getMin();

    int getId(void* record);

    ~MinHeap();
};

}
#endif