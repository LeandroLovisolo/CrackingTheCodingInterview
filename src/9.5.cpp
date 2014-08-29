#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool allUsed(const vector<bool> &mask) {
    for(bool used : mask) {
        if(!used) return false;
    }
    return true;
}

void permutationsRec(const string &s,
                     vector<bool> &mask,
                     string &current,
                     vector<string> &perms) {
    if(allUsed(mask)) {
        perms.push_back(current);
        return;
    }

    for(int i = 0; i < mask.size(); i++) {
        if(!mask[i]) {
            mask[i] = true;
            current.push_back(s[i]);
            permutationsRec(s, mask, current, perms);
            current.pop_back();
            mask[i] = false;
        }
    }
}

vector<string> permutations(const string &s) {
    vector<bool> mask(s.size(), false);
    string current;
    vector<string> perms;
    permutationsRec(s, mask, current, perms);
    return perms;
}

int main() {
    string s = "hola";
    vector<string> ps = permutations(s);
    for(string p : ps) cout << p << endl;
    return 0;
}