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
    int rangeBitwiseAnd(int m, int n) {
        int mc = 0, nc = 0, t = m, low;
        while(t){
            low = t&-t;
        }
    }
};