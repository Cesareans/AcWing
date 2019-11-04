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

void find(const vector<int>& heights, vector<int>& neighbor){
    stack<pair<int,int>> s;
    s.emplace(-1, INT_MIN);
    for(int i = 0 ; i < heights.size(); ++i){
        while(!s.empty() && s.top().second >= heights[i]) s.pop();
        neighbor[i] = s.top().first;
        s.emplace(i, heights[i]);
    }
}

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int m = 0, len = heights.size();
        vector<int> ll(len, 0), rr(len, 0);
        find(heights, ll);
        reverse(heights.begin(), heights.end());
        find(heights, rr);
        for(int i = 0 ; i < len; ++i){
            m = max(m, heights[i] * (len - rr[i] - ll[len-1-i] - 2));
        }
        return m;
    }
};

int main(){
    vector<int> vec = {2,1,5,6,2,3};
    cout << Solution().largestRectangleArea(vec) << endl;
    vector<int> vec1 = {2};
    cout << Solution().largestRectangleArea(vec1) << endl;
    vector<int> vec2 = {};
    cout << Solution().largestRectangleArea(vec2) << endl;
    return 0;
}