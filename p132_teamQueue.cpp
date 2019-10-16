#include <iostream>
#include <queue>

using namespace std;

static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

const int N = 1000010;
const int NT = 1010;

class Queue {
public:
    int serial[N];

    int team[NT];
    queue<int> n[NT];
    int hdx;
    int tdx;

    Queue() : hdx(1), tdx(0) {}

    void enqueue(int s) {
        int tIdx = serial[s];
        if (team[tIdx] == 0) {
            tdx = (tdx + 1) % NT;
            n[tdx].push(s);
            team[tIdx] = tdx;
        } else {
            n[team[tIdx]].push(s);
        }
    }

    int dequeue() {
        int res = n[hdx].front();
        n[hdx].pop();
        if (n[hdx].empty()) {
            team[serial[res]] = 0;
            hdx = (hdx + 1) % NT;
        }
        return res;
    }

    void clear(){
        memset(team,0, sizeof(team));
        for(int i = hdx; i <= tdx; ++i){
            while (!n[i].empty()) n[i].pop();
        }
        hdx = 1;
        tdx = 0;
    }
};

char cmd[10];
Queue tq;

int main() {
    int ni = 0, n, m, p, k, q;
    while (cin >> n, n) {
        k = 0;
        tq.clear();
        cout << "Scenario #" << ++ni << endl;
        while (n--) {
            cin >> m;
            ++k;
            while (m--) {
                cin >> p;
                tq.serial[p] = k;
            }
        }
        while (cin >> cmd) {
            char c = *cmd;
            if (c == 'E') {
                cin >> q;
                tq.enqueue(q);
            } else if (c == 'D') {
                cout << tq.dequeue() << endl;
            } else if (c == 'S') {
                break;
            }
        }
        cout << endl;
    }
    return 0;
}