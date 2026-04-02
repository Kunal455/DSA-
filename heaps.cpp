#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &heap, int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && heap[l] > heap[largest])
        largest = l;

    if(r < n && heap[r] > heap[largest])
        largest = r;

    if(largest != i)
    {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

void insertHeap(vector<int> &heap, int value)
{
    heap.push_back(value);

    int i = heap.size() - 1;

    while(i > 0)
    {
        int parent = (i - 1) / 2;

        if(heap[parent] < heap[i])
        {
            swap(heap[parent], heap[i]);
            i = parent;
        }
        else
            break;
    }
}

void heapSort(vector<int> &heap)
{
    int n = heap.size();

    for(int i = n-1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        heapify(heap, i, 0);
    }
}

int main()
{
    vector<int> heap;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertHeap(heap, x);
    }

    cout<<"Max Heap:\n";
    for(int x : heap)
        cout<<x<<" ";

    cout<<"\nSorted Array:\n";

    heapSort(heap);

    for(int x : heap)
        cout<<x<<" ";
}