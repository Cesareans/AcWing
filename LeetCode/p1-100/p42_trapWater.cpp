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
    int trap(vector<int>& height) {
        deque<int> q;
        for(int i = 0; i < height.size(); ++i){
            if(q.empty()) q.push_back(height[i]);

            while (q.front() <= height[i]) q.pop_front();
        }
    }
};