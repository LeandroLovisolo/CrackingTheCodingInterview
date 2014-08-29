#include <iostream>
#include <vector>

using namespace std;

void printCurrentSet(const vector<int> &set, const vector<bool> &current) {
    for(int i = 0; i < set.size(); i++) {
        if(current[i]) cout << set[i];
        else           cout << " ";
    }
    cout << endl;
}

void printPowersetRec(const vector<int> &set, vector<bool> &current, int start) {
    if(start == set.size()) {
        printCurrentSet(set, current);
        return;
    }

    // include start
    current[start] = true;
    printPowersetRec(set, current, start + 1);
    current[start] = false;

    // exclude start
    printPowersetRec(set, current, start + 1);
}

void printPowerset(const vector<int> &set, int start) {
    vector<bool> current(set.size(), false);
    printPowersetRec(set, current, 0);
}


int main() {
    vector<int> set {1, 2, 3, 4, 5};
    printPowerset(set, 0);
    return 0;
}