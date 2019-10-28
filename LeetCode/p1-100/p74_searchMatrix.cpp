#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) return false;
        if(matrix[0].empty()) return false;
        int h = matrix.size(), w = matrix[0].size(), len = h * w;
        int l = 0, r = len - 1;

        while (l < r) {
            int mid = (l + r) >> 1;
            if (matrix[mid / w][mid % w] < target) l = mid + 1;
            else r = mid;
        }

        return matrix[l / w][l % w] == target;
    }
};

int main() {
    vector<vector<int>> vec = {
            {1,  3,  5,  7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
    };
    cout << Solution().searchMatrix(vec, 5);
}