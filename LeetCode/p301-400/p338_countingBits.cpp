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
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for(int i = 2; i <= num; ++i) res[i] = (i&1) + res[i >> 1];
        return res;
    }
};

int main(){
    Solution().countBits(5);
}