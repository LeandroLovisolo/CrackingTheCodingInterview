#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    if(argc != 2) return -1;
    char occurrences[256];
    for(int i = 0; i < 256; i++) occurrences[i] = 0;
    char *str = argv[1];
    while(*str != 0) {
        occurrences[*str]++;
        str++;
    }
    for(int i = 0; i < 256; i++) {
        if(occurrences[i] > 1) {
            cout << "Not all characters unique." << endl;
            return 0;
        }
    }
    cout << "All characters unique." << endl;
    return 0;
}