// Binary search algorithm (iterative).
// http://en.wikipedia.org/wiki/Binary_search_algorithm

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int> &v, int start, int end, int x) {
    while(start != end) {
        int mid = (start + end) / 2;
        if(v[mid] == x) return mid;
        if(v[mid] < x) start = mid + 1;
        else end = mid;
    }
    return v[start] == x ? start : -1;
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