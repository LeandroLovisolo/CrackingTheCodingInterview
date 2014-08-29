#include <iostream>
#include <vector>

using namespace std;

void waysOfRepresentingRec(int n, int &ways,
                           const vector<int> &denominations,
                           int firstDenomination) {
    for(int d = firstDenomination; d < denominations.size(); d++) {
        int m = n - denominations[d];
        if(m == 0) {
            ways++;
        } else if(m > 0) {
            waysOfRepresentingRec(m, ways, denominations, d);
        }
    }
}

int main() {
    vector<int> denominations {25, 10, 5, 1};

    cout << "denominations: ";
    for(int d : denominations) cout << d << " ";
    cout << endl;

    for(int n = 0; n <= 100; n++) {
        int ways = 0;
        waysOfRepresentingRec(n, ways, denominations, 0);
        cout << "ways of representing " << n << ": " << ways << endl;
    }

    return 0;
}