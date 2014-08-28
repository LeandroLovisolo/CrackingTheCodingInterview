// Insertion sort algorithm.
// http://en.wikipedia.org/wiki/Insertion_sort

#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &v, int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void insertionsort(vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = i; j >= 0; j--) {
            if(v[j - 1] > v[j]) swap(v, j - 1, j);
        }
    }
}

int main() {
    vector<int> v {3, 9, 4, 6, 8, 2, 1, 7, 5};

    insertionsort(v);

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}