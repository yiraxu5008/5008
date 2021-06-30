#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "min_heap_int.h"
#define PQ_SIZE 64
#define MIN_VALUE -10000
/**
* returns a that contains all the elements in the array data,
* which contains num_elems ints.
*/
Heap* CreateHeap(int* data, int num_elems)
{
        Heap* h;
        int i;
        h = (Heap*)malloc(sizeof(struct Heap*));
        if (h == NULL)
        {
                printf("fail to malloc");
        }
        h->num_elems = 0;
        h->data[0] = MIN_VALUE;
        for (i = 0; i <num_elems; i++)
        {
                Insert(h, data[i]);
        }

        return h;
}

/**
* inserts the int val into heap heap.
* If the heap currently has n elements,
* this takes O(log n) time.
*/
void Insert(Heap* heap, int val)
{
        if (heap->num_elems == PQ_SIZE)
        {
                printf("priority queue is full");
                return;
        }
        heap->num_elems++;
        heap->data[heap->num_elems] = val;
        if(val<heap->data[heap->num_elems/2])
                BubbleUp(heap, heap->num_elems);

}

/**
* identifies and deletes an element with
* minimum value from a heap.
*/
int ExtractMin(Heap* heap)
{
        int min_index = 1;
        int min_data = heap->data[min_index];
        Delete(heap, min_index);
        return min_data;
}

/**
* deletes the element in heap position i.
* This is implemented in O(log n) time for
* heaps that have n elements.
*/
int Delete(Heap* heap, int position)
{
        if (position < 1 || position > heap->num_elems)
        {
                printf("delete position is wrong");
                return 0;
        }

        heap->data[position] = heap->data[heap->num_elems];
        BubbleDown(heap, position);
        heap->num_elems--;
        return 1;
}

/**
* bubbles the element at location index up
* to its correct position.
*/
void BubbleUp(Heap* heap, int index)
{
        if (index <2)
        {
                return;
        }
        int tp = index;
        int t = heap->data[index];
        int parent=tp/2;
        while ((tp > 1) && (heap->data[parent] > t))
        {
                heap->data[tp]=heap->data[parent];
                tp = parent;
                parent=parent/2;
        }
        heap->data[tp]=t;
}

/**
* bubbles the element at location index
* down to its correct position.
*/
void BubbleDown(Heap* heap, int index)
{
        int i = index, child = i * 2;
        int t = heap->data[index];
        while (child <= heap->num_elems)
        {
                if ((child != heap->num_elems ) && (heap->data[child] > heap->data[child + 1]))
                {
                        child++;
                }
                if (t <= heap->data[child])
                {
                        break;
                }
                else
                {
                        heap->data[i] = heap->data[child];
                        i = child;
                        child = child * 2;
                }
        }
        heap->data[i] = t;
}

/**
* swaps the elements at index first_ind
* and second_ind.
*/
void Swap(Heap* heap, int first_ind, int second_ind)
{
        int t;
        t = heap->data[first_ind];
        heap->data[first_ind] = heap->data[second_ind];
        heap->data[second_ind] = t;
}

/**
* frees all resources associated with
* heap heap.
*/
void DestroyHeap(Heap* heap)
{
        int i;
        for(i=0;i<heap->num_elems+1;i++)
                heap->data[i]=NULL;
        free(heap);
}
