// Binary search algorithm.
// http://en.wikipedia.org/wiki/Binary_search_algorithm

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int> &v, int start, int end, int x) {
    if(start == end) return v[start] == x ? start : -1;
    int mid = (start + end) / 2;
    if(v[mid] == x) return mid;
    if(v[mid] < x) return binarySearch(v, mid + 1, end, x);
    return binarySearch(v, start, mid, x);
}

int main() {
    vector<int> v {2, 3, 5, 7, 11, 13, 17, 19};

    cout << "Vector: ";
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    for(int x = v[0]; x <= v[v.size() - 1]; x++) {
        cout << x << " index: " << binarySearch(v, 0, v.size(), x) << endl;
    }

    return 0;
}