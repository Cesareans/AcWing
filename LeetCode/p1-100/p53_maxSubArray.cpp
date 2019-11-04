#include <vector>
#include <iostream>
#include <queue>
#include <stack>
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
    int maxSubArray(vector<int>& nums) {
        int m = INT_MIN, sum = 0;
        for(int i : nums){
            sum = max(i, sum + i);
            m = max(m, sum);
        }
        return m;
    }
};
