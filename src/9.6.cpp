#include <iostream>
#include <vector>

using namespace std;

bool fullCombination(vector<char> &parens) {
    for(char c : parens) {
        if(c == ' ') return false;
    }
    return true;
}

void print(vector<char> &parens) {
    for(char p : parens) {
        cout << p;
    }
    cout << endl;
}

void clean(vector<char> &parens, int first, int last) {
    for(int i = first; i <= last; i++) parens[i] = ' ';
}

void printParenthesesRec(vector<char> &parens, int first, int last) {
    if(last == first + 1) {
        parens[first] = '(';
        parens[last] = ')';
        if(fullCombination(parens)) print(parens);
    } else {
        parens[first] = '(';
        int currentLast = first + 1;
        while(currentLast <= last) {
            if(currentLast == first + 1) {
                parens[currentLast] = ')';    
                clean(parens, first + 2, last);
                printParenthesesRec(parens, first + 2, last);
            } else {
                clean(parens, first + 1, last);
                parens[currentLast] = ')';
                printParenthesesRec(parens, first + 1, currentLast - 1);
                if(currentLast != last - 1) {
                    printParenthesesRec(parens, currentLast + 1, last - 1);
                }
            }
            currentLast += 2;
        }
    }
}

void printParentheses(int n) {
    vector<char> parens(2*n, ' ');
    printParenthesesRec(parens, 0, parens.size() - 1);
}

int main() {
    printParentheses(4);
    return 0;
}