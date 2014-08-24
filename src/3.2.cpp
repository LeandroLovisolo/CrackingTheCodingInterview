#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

#define N 20

int stack[N];
int top = -1;
int stack_min;

bool is_stack_empty() {
    return top == -1;
}

void push(int x) {
    if(top == N - 1) return;
    stack[++top] = x;
    stack_min = (top == 0 || x < stack_min) ? x : stack_min;
}

int peek() {
    if(is_stack_empty()) return INT_MIN;
    return stack[top];
}

int pop() {
    if(is_stack_empty()) return INT_MIN;
    int val = stack[top--];
    if(!is_stack_empty()) {
        stack_min = stack[top] < stack_min ? stack[top] : stack_min;
    }
    return val;
}

int get_stack_min() {
    if(is_stack_empty()) return INT_MIN;
    return stack_min;
}

int main() {
    for(int i = 0; i < N; i++) push(rand() % 100);
    int m = get_stack_min();

    while(!is_stack_empty()) cout << pop() << " ";
    cout << endl << "Minimum: " << m << endl;

    return 0;
}