#include <iostream>
#include <queue>

using namespace std;


int *median_running_stream(int arr[], int size)
{
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;

    int *median = new int(size);

    max_heap.push(arr[0]);
    median[0] = arr[0];

    for (int i=1; i<size; i++)
    {
        if (max_heap.size()>min_heap.size())
        {
            if (arr[i]<median[i-1])
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(arr[i]);
            }

            else    
                min_heap.push(arr[i]);

            median[i] = (max_heap.top() + min_heap.top()) / 2;
        }

        else if (max_heap.size()==min_heap.size())
        {
            if (arr[i]<median[i-1])
            {
                max_heap.push(arr[i]);
                median[i] = max_heap.top();
            }

            else
            {
                min_heap.push(arr[i]);
                median[i] = min_heap.top();
            }

            //median = arr[i];
        }

        else 
        {
            if (arr[i]>median[i-1])
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(arr[i]);
            }

            else
                max_heap.push(arr[i]);

            median[i] = (max_heap.top() + min_heap.top()) / 2;
        }

        //cout << median << " ";
    }

    return median;
}

int main()
{
    int arr[5] = {5, 15, 10, 20, 3};
    int *median = median_running_stream(arr, 5);

    //median_running_stream(arr, 5);
    for (int i=0; i<5; i++)
        cout << *(median+i) << " ";
 }