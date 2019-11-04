#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

class Node{
public:
    int wgt;
    int ver;
    Node* next;
    Node():wgt(0),ver(0),next(nullptr){}
    Node(int wgt, int ver, Node *next) : wgt(wgt), ver(ver), next(next) {}
};

const int N = 100010;
Node nodes[N];
int dist[N], visited[N];

void add(int x, int y ,int z){
    Node* next = new Node(z, y, nodes[x].next);
    nodes[x].next = next;
}

int main(){
    memset(dist, 0x3f, sizeof(dist));
    int n = 0,m = 0,x = 0,y = 0,z = 0;
    cin >> n >> m;
    while(m--){
        cin >> x >> y >> z;
        add(x,y,z);
    }
    dist[1] = 0;
    priority_queue<pair<int,int>> minDis;
    minDis.emplace(0, 1);
    while(!minDis.empty()){
        int ver = minDis.top().second;
        minDis.pop();
        visited[ver] = 1;
        Node* arc = nodes[ver].next;
        while(arc){
            if(dist[arc->ver] > dist[ver] + arc->wgt){
                dist[arc->ver] = dist[ver] + arc->wgt;
                if(!visited[arc->ver]) minDis.emplace(-dist[arc->ver], arc->ver);
            }
            arc = arc->next;
        }
    }
    cout << (dist[n] == 0x3f3f3f3f?-1:dist[n]);
    return 0;
}