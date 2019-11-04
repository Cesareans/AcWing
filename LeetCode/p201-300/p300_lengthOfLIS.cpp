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
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> lis(nums.size(), 0);
        int res = INT_MIN;
        for(int i = 0 ; i < nums.size(); ++i){
            int m = 1;
            for(int j = 0 ; j <= i ; ++j) m = max(m, nums[j] < nums[i]?(1+lis[j]):1);
            lis[i] = m;
            res = max(res, lis[i]);
        }
        return res;
    }
};
class Solution1 {
public:
    int lengthOfLIS(const vector<int>& nums) {
        vector<int> vec(nums.size() + 1, INT_MAX);
        int len = 0;
        for(int num : nums){
            int l = 0, r = len;
            while(l < r){
                int mid = (l+r)>>1;
                if(vec[mid] < num) l = mid + 1;
                else r = mid;
            }
            if(num < vec[l]) vec[l] = num;
            if(l == len) ++len;
        }
        return len;
    }
};

int main(){
    cout << Solution1().lengthOfLIS({10,9,2,5,3,7,101,18}) << endl;
    cout << Solution1().lengthOfLIS({1,2,3,4});
}