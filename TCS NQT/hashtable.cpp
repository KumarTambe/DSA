#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, T;
    cin >> N >> T;
    vector<int> nums(N,0);
    for(int i=0;i<T;i++){
        int x , y;
        cin >> x >> y;
        nums[x % N] += y;
    }
    for(int i = 0;i<N;i++){
        cout << " Index " << i <<":" << nums[i];
    }
}