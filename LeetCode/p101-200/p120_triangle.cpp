#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>

using namespace std;

static int closeStream = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        if (triangle.empty()) return 0;
        vector<int> res(triangle[triangle.size() - 1].size(), 0);
        int lt, t;
        for (int i = 0; i < triangle.size(); ++i) {
            lt = res[0];
            for (int j = 0; j < triangle[i].size(); ++j) {
                t = res[j];
                res[j] = (j == triangle[i].size() - 1 ? lt : min(lt, res[j])) + triangle[i][j];
                lt = t;
            }
        }
        int m = INT_MAX;
        for (int i = 0; i < res.size(); ++i) m = min(m, res[i]);
        return m;
    }
};

int main() {
    vector<vector<int>> vec = {
            {-10}
    };
    cout << Solution().minimumTotal(vec);
}