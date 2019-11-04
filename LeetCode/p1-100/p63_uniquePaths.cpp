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
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == -1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long>> res(m+1, vector<long>(n+1, 0));
        res[1][1] = 1;
        for (auto &&ri : res[0]) ri = 0;
        for (int i = 1; i <= m; ++i) {
            res[i][0] = 0;
            for (int j = 1; j <= n; ++j) {
                if(obstacleGrid[i-1][j-1] == 1) res[i][j] = 0;
                else{
                    res[i][j] += res[i - 1][j] == -1 ? 0 : res[i - 1][j];
                    res[i][j] += res[i][j - 1] == -1 ? 0 : res[i][j - 1];
                }
            }
        }
        return res[m][n];
    }
};

int main(){
    vector<vector<int>> vec = {
            {1}
    };
    cout << Solution().uniquePathsWithObstacles(vec);
}