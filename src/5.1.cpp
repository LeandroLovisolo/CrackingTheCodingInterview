#include <iostream>
#include <bitset>

using namespace std;

int insertInto(int N, int M, int i, int j) {
    M << i;

    int andmask = 0;
    for(int k = 0; k < j - i + 1; k++) {
        andmask = andmask << 1;
        andmask++;
    }
    andmask = andmask << i;
    andmask = ~andmask;
    N = N & andmask;
    M = M << i;
    return N | M;
}

int main() {
    int M = 0b1010;
    int N = 0b10111100;
    int i = 2;
    int j = 5;
    int res = insertInto(N, M, i, j);

    cout << "M: " << (bitset<8>) M << endl;
    cout << "N: " << (bitset<8>) N << endl;
    cout << "i: " << i << endl;
    cout << "j: " << j << endl << endl;
    cout << "After inserting M into N: " << (bitset<8>) res << endl;

    return 0;
}