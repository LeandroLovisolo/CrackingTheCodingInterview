#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> moreCombinations(string s) {
    if(s == "") return unordered_set<string> {"()"};

    unordered_set<string> combinations;

    for(int i = 0; i < s.length(); i++) {
        for(int j = i; j < s.length(); j++) {
            string combination = s.substr(0, i);
            combination.push_back('(');
            combination += s.substr(i, j - i);
            combination.push_back(')');
            combination += s.substr(j, s.length() - j);
            combinations.insert(combination);
        }
    }

    return combinations;
}

unordered_set<string> parentheses(int n) {
    unordered_set<string> combinations { "" };
    
    for(int i = 0; i < n; i++) {
        unordered_set<string> newCombinations;

        for(string c : combinations) {
            unordered_set<string> more = moreCombinations(c);
            for(auto m : more) newCombinations.insert(m);
        }

        combinations = newCombinations;
    }

    return combinations;
}

int main() {
    int n = 4;

    unordered_set<string> combinations = parentheses(n);

    for(string s : combinations) {
        cout << s << endl;
    }

    return 0;
}