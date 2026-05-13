class MinStack {
public:
    stack<int>st1;  //for actual value
    stack<int>st2;  //for minimum value
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        if(st2.empty()){
            st2.push(val);
        }
        else{
            
            if(val > st2.top()){
                st2.push(st2.top());
            }
            else{
                st2.push(val);
            }
        }
    }
    
    void pop() {
        if(st1.empty()) return;
        st1.pop();
        st2.pop();
    }
    
    int top() {
        if(st1.empty()) return -1;
        return st1.top();
    }
    
    int getMin() {
        if(st1.empty()) return -1;
        return st2.top();
    }
};
