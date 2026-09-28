class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int>s1;
    int m=-1;

    void push(int x) {
        if(m==-1) m=x;
        s1.push(x);
    }
    
    int pop() {
        if(s1.size()==0) return 0;

        stack<int>s2;
        while(s1.size()>1) s2.push(s1.top()), s1.pop();

        int a=s1.top();
        s1.pop();

        m=-1;
        if(s2.size()!=0) m=s2.top();
        while(!s2.empty()) s1.push(s2.top()), s2.pop();

        return a;
    }
    
    int peek() {
        return m;
    }
    
    bool empty() {
        return s1.size()==0;
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