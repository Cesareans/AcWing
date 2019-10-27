#include <vector>
#include <iostream>
using namespace std;

bool compare(int a, int b){
    if(a%2==0){
        return b%2==0?a<b:true;
    }else{
        return b%2==0?false:a<b;
    }
}

class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int> vec;
        vec.reserve(N);
        for(int i = 1 ; i <= N; ++i){
            int l = 0, r = vec.size()-1;
            while (l<=r){
                int mid = (l+r)>>1;
                if(compare(vec[mid], i)) l = mid+1;
                else r = mid-1;
            }
            vec.insert(vec.begin()+l, i);
        }
        return vec;
    }
};
class Solution1 {
public:
    vector<int> specialSort(int N) {
        vector<int> vec;
        vec.reserve(N);
        for(int i = 1 ; i <= N ; ++i) vec.push_back(i);
        quickSort(vec, 0, N-1);
        return vec;
    }

private:
    void quickSort(vector<int>& vec, int l, int r){
        if(l >= r) return;
        int ll = l, rr = r+1;
        int axis = vec[ll];
        while (true){
            while (compare(vec[++ll], axis) && ll < rr); //
            while (compare(axis, vec[--rr]));
            if(ll >= rr) break;
            swap(vec[ll], vec[rr]);
        }
        vec[l] = vec[rr];
        vec[rr] = axis;
        quickSort(vec, l,rr-1);
        quickSort(vec, rr+1,r);
    }
};

int main(){
    vector<int> v = (Solution1().specialSort(10));
    for(int i = 0 ; i < v.size(); ++i){
        cout<<v[i]<<endl;
    }
    return 0;
}