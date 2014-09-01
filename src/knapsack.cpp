// 0-1 Knapstack problem.
// http://en.wikipedia.org/wiki/Knapsack_problem

#include <iostream>
#include <vector>

using namespace std;

typedef int size;
typedef int value;
typedef pair<size, value> item;

inline int getSize(const item &i) { return i.first; }
inline int getValue(const item &i) { return i.second; }

int knapsack(vector<item> items, int capacity) {
    vector<vector<value>> dp(items.size() + 1, vector<value>(capacity + 1, 0));

    for(int i = 1; i <= items.size(); i++) {
        for(int j = 0; j <= capacity; j++) {
            if(items[i - 1].first <= j) {
                int with = getValue(items[i - 1]) + dp[i - 1][j - getSize(items[i - 1])];
                int without = dp[i - 1][j];
                dp[i][j] = max(with, without);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[items.size()][capacity];
}

int main() {
    vector<item> items {{2, 3}, {3, 4}, {4, 5}, {5, 8}, {9, 10}};
    int capacity = 20;

    int max_value = knapsack(items, capacity);
    cout << max_value << endl;
    return 0;
}