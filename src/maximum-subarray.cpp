// Maximum sum contiguous subarray problem.
// http://en.wikipedia.org/wiki/Maximum_subarray_problem

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> maximumSubarray(vector<int> v) {
    if(v.size() == 0) return make_pair(-1, -1);

    vector<pair<int, int>> dp(v.size() + 1, make_pair(0, 0));

    for(int i = 1; i <= v.size(); i++) {
        if(dp[i - 1].first + v[i] >= v[i]) {
            // we improve on the previous subarray
            dp[i].first = dp[i - 1].first + v[i];
            dp[i].second = dp[i - 1].second + 1;
        } else {
            // we start a new subarray
            dp[i].first = v[i];
            dp[i].second = 1;
        }
    }

    pair<int, int> result = dp[0];
    for(int i = 0; i <= dp.size(); i++) {
        if(dp[i].first > result.first) result = dp[i];
    }

    return result;
}


int main() {
    vector<int> v = {5, -8, 2, 6, -4, 2, 5, 3, -7};

    pair<int, int> result = maximumSubarray(v);
    cout << "Maximum sum: " << result.first << endl;
    cout << "Subarray length: " << result.second << endl;

    return 0;
}