#include "../../base.h"

static int closeStream = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        return minDepthRecursively(root);
    }

    int minDepthRecursively(TreeNode *node) {
        if (node == nullptr || (node->left == nullptr && node->right == nullptr)) return 1;
        return min(minDepth(node->left), minDepth(node->right)) + 1;
    }
};