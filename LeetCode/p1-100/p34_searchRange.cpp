#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        int ll,rr, l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = (l+r)>>1;
            if(nums[mid] < target) l = mid+1;
            else r = mid;
        }
        ll = l, l = 0, r= nums.size() - 1;
        while(l < r){
            int mid = (l+r+1)>>1;
            if(nums[mid] > target) r = mid-1;
            else l = mid;
        }
        rr = l;
        if(nums[ll] == target) return {ll, rr};
        else return {-1,-1};
    }
};