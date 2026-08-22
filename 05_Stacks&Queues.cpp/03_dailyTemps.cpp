#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemp(vector<int>&temps){
    int n = temps.size();
    vector<int>result(n,0);
    stack<int> st;
    for(int i = 0;i<n ;i++){
        while(!st.empty() && temps[i] > temps[st.top()]){
            int idx = st.top();
            st.pop();
            result[idx] = i - idx;
        }
        st.push(i);
    } 
    return result;
}