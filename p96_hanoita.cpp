#include <iostream>

using namespace std;

void hanoi(int n, int src, int mid, int des) {
    if (n > 0) {
        // 将n顶上的圆盘，通过目标柱移动到中间柱上
        hanoi(n-1, src, des, mid);
        // 把n移到目标柱上
        cout << "Move " << n << " from " << src << " to " << des << endl;
        // 把中间柱上的圆盘经过源柱移动到目标柱上
        hanoi(n-1, mid, src, des);
    }
}

int main() {
    hanoi(3,1,2,3);
}