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
    int getSum(int a, int b) {
        while (b) {
            a = a ^ b;
            b = (unsigned int)((a ^ b) & b) << 1;
        }
        return a;
    }
};

int main(){
    cout << Solution().getSum(-1,1);
}