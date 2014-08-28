// Heap sort algorithm.
// http://en.wikipedia.org/wiki/Heap_sort

#include <iostream>
#include <vector>

using namespace std;

int left(int i) {
    return 2*(i + 1) - 1;
}

int right(int i) {
    return 2*(i + 1);
}

void swap(vector<int> &v, int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

int heapify(vector<int> &v, int i, int size) {
    int largest = i;
    if(left(i)  < size && v[left(i)]  > v[largest]) largest = left(i);
    if(right(i) < size && v[right(i)] > v[largest]) largest = right(i);
    if(largest != i) {
        swap(v, i, largest);
        heapify(v, largest, size);
    }
}

void buildHeap(vector<int> &v) {
    if(v.size() < 2) return;
    for(int i = v.size()/2 - 1; i >= 0; i--) {
        heapify(v, i, v.size());
    }
}

void heapsort(vector<int> &v) {
    if(v.size() < 2) return;

    buildHeap(v);

    for(int size = v.size(); size > 0; size--) {
        swap(v, 0, size - 1);
        heapify(v, 0, size - 1);
    }
}

int main() {
    vector<int> v {3, 9, 4, 6, 8, 2, 1, 7, 5};

    heapsort(v);

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}