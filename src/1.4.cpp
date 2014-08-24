#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    if(argc != 2) return -1;
    string s(argv[1]);
    int whitespaces = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') whitespaces++;
    }
    int length = s.length();
    s.resize(length + 2 * whitespaces, ' ');
    int j = s.length() - 1;
    for(int i = length - 1; i >= 0; i--) {
        if(s[i] == ' ') {
            s[j--] = '0';
            s[j--] = '2';
            s[j--] = '%';
        } else {
            s[j--] = s[i];
        }
    }
    cout << s << endl;
    return 0;
}