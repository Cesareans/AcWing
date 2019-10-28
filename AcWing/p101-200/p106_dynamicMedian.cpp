#include <iostream>
#include <queue>
using namespace std;
int x = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Dynamic {
private:
    priority_queue<int> maxHeap;
    priority_queue<int> minHeap;
public:
    void Insert(int num){
        if(!minHeap.empty() && num > -minHeap.top()){
            maxHeap.push(-minHeap.top());
            minHeap.pop();
            minHeap.push(-num);
        }else{
            maxHeap.push(num);
        }

        if(maxHeap.size() >= minHeap.size() + 2){
            minHeap.push(-maxHeap.top());
            maxHeap.pop();
        }
    }

    double GetMedian(){
        return maxHeap.size() == minHeap.size()? (maxHeap.top()-minHeap.top()) / 2.0 : maxHeap.top();
    }
};

int main(){
    int n;
    cin >> n;
    while(n--){
        int p, m, cnt = 0, t;
        cin >> p >> m;
        cout << p << " " << (m+1)/2 << endl;
        Dynamic d;
        while(m--){
            cin >> t;
            cnt++;
            d.Insert(t);
            if(cnt%2==1){
                cout<<d.GetMedian()<<" ";
            }
            if(cnt == 20){
                cout << endl;
                cnt = 0;
            }
        }
        cout<<endl;
    }
}