#include<bits/stdc++.h>
using namespace std;

class MinStack{
    stack<int> main;
    stack<int> minSt;

    public:
        void push(int val){
            main.push(val);
            if(minSt.empty() || val < minSt.top()){
                minSt.push(val);
            } else {
                minSt.push(minSt.top());
            }
        }
        void pop(){
            minSt.pop();
            main.pop();
        }
        int top(){
            return main.top();
        }
        int getMin(){
            return minSt.top();
        }
};