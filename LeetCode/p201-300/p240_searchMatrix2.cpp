#include <iostream>
#include <vector>

using namespace std;

static int fast_streams = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int h = matrix.size(), w = matrix[0].size();
        for (int i = h - 1, j = 0; i >= 0 && j < w;) {
            if (matrix[i][j] > target)--i;
            else if (matrix[i][j] < target) ++j;
            else return true;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> vec = {
            {1,  4,  7,  11, 15},
            {2,  5,  8,  12, 19},
            {3,  6,  9,  16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
    };
    cout << Solution().searchMatrix(vec, 30);
    return 0;
}