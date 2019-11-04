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
    int minDistance(string word1, string word2) {
        vector<int> c(word2.length() + 1);
        for (int i = 0; i <= word2.length(); ++i) c[i] = i;
        int leftTop = 0, t;
        for (int i = 1; i <= word1.length(); ++i) {
            leftTop = c[0];
            c[0] = i;
            for (int j = 1; j <= word2.length(); ++j) {
                t = c[j];
                c[j] = word1[i - 1] == word2[j - 1] ? leftTop : min({leftTop, c[j - 1], c[j]}) + 1;
                leftTop = t;
            }
        }
        return c[word2.length()];
    }
};