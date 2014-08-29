#include <iostream>
#include <vector>

using namespace std;

struct box {
	int width;
	int height;
	int depth;
};

void printStack(const vector<box> &stack) {
    for(int i = stack.size() - 1; i >= 0; i--)
        cout << stack[i].width  << "\t"
             << stack[i].height << "\t"
             << stack[i].depth  << endl;
}

bool canStack(const vector<box> &stack, box b) {
    if(stack.empty()) return true;
    return stack.back().width  > b.width  &&
           stack.back().height > b.height &&
           stack.back().depth  > b.depth;
}

bool isCandidate(const vector<box> &boxes,
                  vector<bool> &stacked,
                  vector<box> &currentStack) {
    for(int i = 0; i < boxes.size(); i++) {
        if(!stacked[i] && canStack(currentStack, boxes[i])) return false;
    }
    return true;
}

int stackHeight(const vector<box> &stack) {
    int height = 0;
    for(box b : stack) height += b.height;
    return height;
}

bool isTaller(const vector<box> &a, const vector<box> &b) {
    return stackHeight(a) > stackHeight(b);
}

void tallestStack(const vector<box> &boxes,
                  vector<bool> &stacked,
                  vector<box> &currentStack,
                  vector<box> &currentTallestStack) {
    if(isCandidate(boxes, stacked, currentStack)) {
        if(isTaller(currentStack, currentTallestStack)) {
            currentTallestStack = vector<box>(currentStack);
        }
    }

    for(int i = 0; i < boxes.size(); i++) {
        if(!stacked[i]) {
            if(canStack(currentStack, boxes[i])) {
                currentStack.push_back(boxes[i]);
                stacked[i] = true;
                tallestStack(boxes, stacked, currentStack, currentTallestStack);
                stacked[i] = false;
                currentStack.pop_back();
            }
        }
    }
}

int main() {
    vector<box> boxes{{1, 1, 1},
                      {9, 9, 9},
                      {2, 2, 3},
                      {3, 3, 4},
                      {4, 4, 4},
                      {4, 5, 6},
                      {7, 8, 8}};
    vector<bool> stacked(boxes.size(), false);
    vector<box> currentStack;
    vector<box> tallest;
    tallestStack(boxes, stacked, currentStack, tallest);

    cout << "Tallest stack:" << endl;
    printStack(tallest);
    return 0;
}