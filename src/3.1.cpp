#include <iostream>
#include <climits>
#include <string>

using namespace std;

#define N 24

int stacks[N];
int tops[3] = {-1, -1, -1};

int stack_begin(int n) {
    return (N / 3) * (n - 1);
}

int stack_end(int n) {
    return (N / 3) * n - 1;
}

bool is_stack_empty(int n) {
    return tops[n - 1] == -1;
}

void push(int n, int x) {
    if(stack_begin(n) + tops[n] == stack_end(n)) return;
    stacks[stack_begin(n) + tops[n] + 1] = x;
    tops[n]++;
}

int peek(int n) {
    if(tops[n] == -1) return INT_MIN;
    return stacks[stack_begin(n) + tops[n]];
}

int pop(int n) {
    if(tops[n] == -1) return INT_MIN;
    int top = stacks[stack_begin(n) + tops[n]];
    tops[n]--;
    return top;
}


int main() {
    string s = "Stacks are vewwwy important.";
    int n = 1;
    for(int i = 0; i < s.length(); i++) {
        push(n, (int) s[i]);
        n++;
        if(n == 4) n = 1;
    }

    string t;
    while(!(is_stack_empty(1) && is_stack_empty(2) && is_stack_empty(3))) {
        int x = pop(n);
        if(x != INT_MIN) t += (char) x;
        n--;
        if(n == 0) n = 3;
    }

    for(auto it = t.rbegin(); it != t.rend(); it++) cout << *it;
    cout << endl;

    return 0;
}