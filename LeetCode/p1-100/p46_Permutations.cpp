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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        permute(res, nums, 0);
        return res;
    }
    void permute(vector<vector<int>>& vec, vector<int>& nums, int idx){
        if(idx == nums.size()){
            vec.push_back(nums);
            return ;
        }
        for(int i = idx; i < nums.size(); ++i){
            swap(nums[idx], nums[i]);
            permute(vec, nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
};