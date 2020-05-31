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
    vector<int> singleNumber(vector<int>& nums) {
        int low = 0;
        for(int n : nums) low ^= n;
        low &= (-low);

        int n1 = 0, n2 = 0;
        for(int n : nums){
            if(n & low) n1^=n;
            else n2^=n;
        }
        return {n1,n2};
    }
};
