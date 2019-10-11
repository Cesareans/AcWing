#include <cstdio>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

/*
 * 使用定长数组记录
 * 注意到排列的种数为n*n-1*n-2...*1
 * 可以意识到，每层向下递归为ni次，故使用循环进行递归
 */

/*
 * 传统交换法，但是注意该方法产生的结果可能非字典序
 * 算法运算次数为n!
 */
void ExponentEnum(int *arr, int n, int ni) {
    if (ni == n - 1) {
        for (int i = 0; i < n; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = ni; i < n; ++i) {
        swap(arr[i], arr[ni]);
        ExponentEnum(arr, n, ni + 1);
        swap(arr[i], arr[ni]);
    }
}

//void ExponentEnum(int n) {
//    int * arr = new int[n];
//    for(int i = 0 ; i < n; ++i){
//        arr[i] = i + 1;
//    }
//    ExponentEnum(arr, n, 0);
//}

/*
 * 记录法，字典序
 * 算法运算次数为n^n
 */
void ExponentEnum(vector<int> vec, int n, int ni, int state) {
    if (ni > n) {
        for (auto i : vec) printf("%d ", i);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!(state & (1 << i))) {
            vec.push_back(i);
            ExponentEnum(vec, n, ni + 1, state | 1 << i);
            vec.pop_back();
        }
    }
}

void ExponentEnum(int n) {
    vector<int> vec;
    vec.reserve(n);
    ExponentEnum(vec, n, 1, 0);
}

int main() {
    int n;
    scanf("%d", &n);
    ExponentEnum(n);
    return 0;
}