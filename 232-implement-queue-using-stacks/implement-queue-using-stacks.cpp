class MyQueue {
    stack<int> inSt;
    stack<int> outSt;
public:
    MyQueue() {}
    
    void push(int x) {
        inSt.push(x);
    }
    
    int pop() {
        if(outSt.empty()){
            while(!inSt.empty()){
                outSt.push(inSt.top());
                inSt.pop();
            }
        }
        int num = outSt.top();
        outSt.pop();
        return num;
    }
    
    int peek() {
        if(outSt.empty()){
            while(!inSt.empty()){
                outSt.push(inSt.top());
                inSt.pop();
            }
        }
        return outSt.top();
    }
    
    bool empty() {
        if(inSt.empty() && outSt.empty()){
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */