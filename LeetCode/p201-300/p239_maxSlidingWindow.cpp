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

using UL = unsigned long;
class Solution {
public:
    vector<int> maxSlidingWindow(const vector<int>& num, unsigned int size){
        vector<int> vec;
        deque<int> q;
        for(UL i = 0; i < num.size(); ++i){
            while((!q.empty() && num[q.back()] < num[i])) q.pop_back();
            if(!q.empty() && i-q.front() >= size) q.pop_front();
            q.emplace_back(i);
            if(i >= size - 1){
                vec.push_back(num[q.front()]);
            }
        }
        return vec;
    }
};