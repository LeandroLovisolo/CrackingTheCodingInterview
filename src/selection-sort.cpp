// Selection sort algorithm.
// http://en.wikipedia.org/wiki/Selection_sort

#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &v, int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void selectionsort(vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        int min = i;
        for(int j = i; j < v.size(); j++) {
            if(v[j] < v[min]) min = j; 
        }
        swap(v, i, min);
    }
}

int main() {
    vector<int> v {3, 9, 4, 6, 8, 2, 1, 7, 5};

    selectionsort(v);

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}