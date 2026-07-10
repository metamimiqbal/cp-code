#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
    vector<int>heap;
    void heapifyUp(int index) {
        while(index>0) {
            int parent = (index-1)/2;
            if(heap[index]>heap[parent]) swap(heap[index], heap[parent]), index = parent;
            else break;
        }
    }
    void heapifyDown(int index) {
        while(true) {
            int n = heap.size();
            int left = 2*index + 1;
            int right = 2*index + 2;
            int largest = index;
    
            if(left < n && heap[left]>heap[largest]) {
                largest = left;
            }
            if(right < n && heap[right]>heap[largest]) {
                largest = right;
            }
    
            if(largest == index) break;
    
            swap(heap[largest], heap[index]);
            index = largest;
        }
    }

    public:

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void deleteRoot() {
        if(heap.empty()) {
            cout<<"Heap is empty\n"; 
            return -1;
        }

        heap[0] = heap.back();
        heap.pop_back();

        if(!heap.empty()) {
            heapifyDown(0);
        }

    }

};



int main() {
    
}