#include <iostream>
#include <string>

using namespace std;

bool is_rotation(const string &s, const string &t) {
    string u;
    u += s;
    u += s;
    return u.find(t) != string::npos;
}

int main(int argc, char **argv) {
    if(argc != 3) return -1;
    string s(argv[1]);
    string t(argv[2]);
    if(is_rotation(s, t)) {
        cout << "One is a rotation of the other." << endl;
    } else {
        cout << "The strings are not rotations." << endl;
    }
    return 0;
}