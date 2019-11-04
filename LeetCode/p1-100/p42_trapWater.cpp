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
    int trap(vector<int> &height) {
        deque<pair<int,int>> q;
        int res = 0;
        for(int i = 0 ; i < height.size(); ++i){
            for(int j = q.size() -2; j >= 0; --j){
                if(q[j+1].second >= height[i]) break;
                res += (min(q[j].second, height[i]) - q[j+1].second) * (i-q[j].first-1);
            }
            while(!q.empty() && q.back().second <= height[i]) q.pop_back();
            q.emplace_back(i, height[i]);
        }
        return res;
    }
};

int main() {
    vector<int> vec = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << Solution().trap(vec);
    return 0;
}