#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000010;
char str[N];
char lstr[2 * N + 1];
int len[2 * N + 1];
char ecd[4] = "END";

int main() {
    int idx = 0;
    while (cin >> str) {
        if (!strcmp(str, ecd)) break;
        int l = 0, m = 0, li, ri;
        for (int i = 0; str[i] != 0; ++i) {
            lstr[2 * i + 1] = str[i];
            ++l;
        }
        l = 2 * l + 1;
        len[0] = 1;
        for (int i = 1; i < l; ++i) {
            if (m + len[m] <= i) {
                for (li = i - 1, ri = i + 1; li >= 0 && ri < l; --li, ++ri) {
                    if (lstr[li] != lstr[ri]) break;
                }
                len[i] = i - li;
                if (len[i] >= len[m]) {
                    m = i;
                }
            } else if(len[2 * m - i] >= len[m] - i + m) {
                for (ri = m + len[m], li = 2*i - ri; li >= 0 && ri < l; --li, ++ri) {
                    if (lstr[li] != lstr[ri]) break;
                }
                len[i] = i - li;
                if (len[i] >= len[m]) {
                    m = i;
                }
            }else{
                len[i] = len[2 * m - i];
            }
        }
        cout << "Case " << ++idx << ": " << len[m] - 1 << endl;
    }
    return 0;
}