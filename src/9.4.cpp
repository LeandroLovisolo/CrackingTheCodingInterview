#include <iostream>
#include <vector>

using namespace std;

void addCurrent(const vector<int> &set,
                vector<vector<int>> &powerset,
                const vector<bool> &currentMask) {
    vector<int> current;
    for(int i = 0; i < set.size(); i++) {
        if(currentMask[i]) current.push_back(set[i]);
    }
    powerset.push_back(current);
}

void powersetRec(const vector<int> &set, vector<vector<int>> &powerset,
                 vector<bool> &currentMask, int start) {
    if(start == set.size()) {
        addCurrent(set, powerset, currentMask);
        return;
    }

    // include start
    currentMask[start] = true;
    powersetRec(set, powerset, currentMask, start + 1);
    currentMask[start] = false;

    // exclude start
    powersetRec(set, powerset, currentMask, start + 1);
}

void printPowerset(const vector<int> &set, int start) {
    vector<bool> currentMask(set.size(), false);
    vector<vector<int>> powerset;

    powersetRec(set, powerset, currentMask, 0);

    for(auto set : powerset) {
        for(auto element : set) cout << element;
        cout << endl;
    }
}


int main() {
    vector<int> set {1, 2, 3, 4, 5};
    printPowerset(set, 0);
    return 0;
}