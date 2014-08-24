#include <iostream>
#include <string>

using namespace std;

string compress(const string &s) {
    string compressed(s.length() * 2, ' ');
    int repetitions, j = 0;
    for(int i = 0; i < s.length(); i++) {
        if(i == 0) {
            compressed[j++] = s[i];
            repetitions = 1;
        } else if(s[i - 1] != s[i]) {
            string n = to_string(repetitions);
            for(int k = 0; k < n.length(); k++) {
                compressed[j++] = n[k];
            }
            compressed[j++] = s[i];
            repetitions = 1;
        } else {
            repetitions++;
        }
    }
    string n = to_string(repetitions);
    for(int k = 0; k < n.length(); k++) {
        compressed[j++] = n[k];
    }
    return string(compressed, 0, j);
}

int main(int argc, char **argv) {
    if(argc != 2) return -1;
    string s(argv[1]);
    string compressed = compress(s);
    if(compressed.length() >= s.length()) {
        cout << s << endl;
    } else {
        cout << compressed << endl;
    }
    return 0;
}
