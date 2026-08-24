#include<bits/stdc++.h>
using namespace std;

class MyStack{
    queue<int> queue;
public:
    void push(int x){
        queue.push(x);
        for(int i=0;i<queue.size()-1;i++){
            queue.push(queue.front());
            queue.pop();
        }
    }

    int pop(){
        int num = queue.front();
        queue.pop();
        return num;
    }

    int top(){
        return queue.front();
    }

    bool empty(){
        if(queue.empty()){
            return true;
        } else {
            return false;
        }
    }
};