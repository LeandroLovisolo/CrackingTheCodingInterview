#include <iostream>
#include <vector>

using namespace std;

int findTimesItWasRotated(vector<int> v, int start, int end) {
    if(start == end) return start + 1;
    if(end == start + 1) {
        if(v[start] > v[end]) return start + 1;
        return end + 1;
    }

    int m = start + ((end - start) / 2);

    if(v[m] > v[m + 1]) return m + 1;
    if(v[start] > v[m]) return findTimesItWasRotated(v, start, m);
    return findTimesItWasRotated(v, m + 1, end);
}


int main() {
    vector<int> v {6,7,8,1,2,3,4,5};

    cout << findTimesItWasRotated(v, 0, v.size() - 1) << endl;

    return 0;
}