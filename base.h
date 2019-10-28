
#ifndef CPP_BASE_H
#define CPP_BASE_H

#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    static TreeNode *build(initializer_list<int> arr) {
        if (!arr.size()) return nullptr;
        return buildNode(arr, 0);

    }

private:
    static TreeNode *buildNode(const initializer_list<int> &arr, int c) {
        if (c >= arr.size() || *(arr.begin() + c) == -1) return nullptr;
        auto *tn = new TreeNode(*(arr.begin() + c));
        tn->left = buildNode(arr, 2 * c + 1);
        tn->right = buildNode(arr, 2 * c + 2);
        return tn;
    }
};

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}

    static ListNode *build(initializer_list<int> arr) {
        ListNode *head = new ListNode(0), *node = head;
        for (int i : arr) {
            node->next = new ListNode(i);
            node = node->next;
        }
        return head->next;
    }

    friend ostream &operator<<(ostream &os, ListNode *node) {
        while (node != nullptr) {
            os << node->val << " ";
            node = node->next;
        }
        os << endl;
        return os;
    }
};

template<class T>
ostream& operator<<(ostream& os, vector<T> vec){
    for (T t : vec) os << t << " ";
    os << endl;
    return os;
}

#endif //CPP_BASE_H
