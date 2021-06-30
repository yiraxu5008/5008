#define PQ_SIZE 64

#ifndef MIN_HEAP_INT_H

#define MIN_HEAP_INT_H


typedef struct
{
        int data[PQ_SIZE+1];
        int num_elems;  //size
} Heap;

/**
* returns a that contains all the elements in the array data,
* which contains num_elems ints.
*/
Heap* CreateHeap(int* data, int num_elems);

/**
* inserts the int val into heap heap.
* If the heap currently has n elements,
* this takes O(log n) time.
*/
void Insert(Heap* heap, int val);

/**
* identifies and deletes an element with
* minimum value from a heap.
*/
int ExtractMin(Heap* heap);

/**
* deletes the element in heap position i.
* This is implemented in O(log n) time for
* heaps that have n elements.
*/
int Delete(Heap* heap, int position);

/**
* bubbles the element at location index up
* to its correct position.
*/
void BubbleUp(Heap* heap, int index);

/**
* bubbles the element at location index
* down to its correct position.
*/
void BubbleDown(Heap* heap, int index);

/**
* swaps the elements at index first_ind
* and second_ind.
*/
void Swap(Heap* heap, int first_ind, int second_ind);

/**
* frees all resources associated with
* heap heap.
*/
void DestroyHeap(Heap* heap);


#endif
