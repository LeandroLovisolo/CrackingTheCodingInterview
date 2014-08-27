// Merge sort algorithm.
// http://en.wikipedia.org/wiki/Merge_sort

#include <iostream>
#include <vector>

using namespace std;

void mergesort(vector<int> &v, int start, int end) {
    if(start == end) return;
    int mid = (start + end) / 2;
    mergesort(v, start, mid);
    mergesort(v, mid + 1, end);

    vector<int> buffer(end - start + 1, 0);

    int m1 = start, m2 = mid + 1;
    for(int i = 0; i < buffer.size(); i++) {
        if(m1 <= mid && m2 <= end) {
            if(v[m1] <= v[m2]) {
                buffer[i] = v[m1];
                m1++;
            } else {
                buffer[i] = v[m2];
                m2++;
            }
        } else if(m1 <= mid) {
            buffer[i] = v[m1];
            m1++;
        } else {
            buffer[i] = v[m2];
            m2++;
        }
    }

    for(int i = 0; i < buffer.size(); i++) {
        v[start + i] = buffer[i];
    }
}

int main() {
    vector<int> v {1, 7, 6, 2, 4, 3};
    mergesort(v, 0, v.size() - 1);

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}