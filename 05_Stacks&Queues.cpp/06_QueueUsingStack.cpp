#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> stack1;
    stack<int> stack2;
public:
    void push(int x) {
        stack1.push(x);
    }
    int pop() {
        if(stack2.empty()){
            while(stack1.empty() != 1){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
            int num = stack2.top();
            stack2.pop();
            return num;
    }
    int peek() {
        if(stack2.empty()){
            while(stack1.empty() != 1){
                stack2.push(stack1.top());
                stack1.pop();
            }
            return stack2.top();
        } else {
            return stack2.top();
        }
    }
    bool empty() {
        if(stack2.empty() && stack1.empty()){
            return true;
        } else {
            return false;
        }
    }
};
