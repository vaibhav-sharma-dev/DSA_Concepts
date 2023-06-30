#include <iostream>
using namespace std;

// 20, 5, 30, 15, 12, 6, 10


class heap
{
    public:
    int heap_arr[100];
    int size;

    heap()
    {
        heap_arr[0] = -1;
        size = 0;
    }

    void create_max_heap (int val)
    {
        size = size + 1;
        int idx = size;
        heap_arr[idx] = val;

        while (idx>1)
        {
            if (heap_arr[idx]>heap_arr[idx/2])
            {
                swap(heap_arr[idx], heap_arr[idx/2]);
                idx = idx/2;
            }

            return;
        }
    }

    void delete_max_heap()
    {
        heap_arr[1] = heap_arr[size];
        size--;

        int idx = 1;
        while (idx<size)
        {
            int left_idx = idx*2;
            int right_idx = idx*2 + 1;

            if (heap_arr[idx]<heap_arr[left_idx])
            {
                swap (heap_arr[idx], heap_arr[left_idx]);
                idx = left_idx;
            }

            else if (heap_arr[idx]<heap_arr[right_idx])
            {
                swap(heap_arr[idx], heap_arr[right_idx]);
                idx = right_idx;
            }

            else return;
        }
    }

    void print_max_heap()
    {
        for (int i=1; i<=size; i++)
            cout << heap_arr[i] << " ";
    }
};


int main()
{
    heap max_heap;
    int arr[7] = {20, 5, 30, 15, 12, 6, 10};

    for (int i=0; i<7; i++)
        max_heap.create_max_heap(arr[i]);

    max_heap.print_max_heap();
    cout << endl;

    max_heap.delete_max_heap();
    max_heap.print_max_heap();
}