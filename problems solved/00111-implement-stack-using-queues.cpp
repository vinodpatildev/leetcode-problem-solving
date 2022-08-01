class MyStack {
public:
    queue<int> qu1,qu2;
    MyStack() {
        
    }
    
    void push(int x) {
        if(qu1.empty()){
            qu2.push(x);
        }else{
            qu1.push(x);
        }
    }
    
    int pop() {
        int top_element = -1;
        if(qu2.empty() && qu1.size()>0){
            while(!qu1.empty() && qu1.size()!=1){
                qu2.push(qu1.front());
                qu1.pop();
            }
            top_element = qu1.front();
            qu1.pop();
        }else if(qu1.empty()  && qu2.size()>0){
            while(!qu2.empty() && qu2.size()!=1){
                qu1.push(qu2.front());
                qu2.pop();
            }
            top_element = qu2.front();
            qu2.pop();
        }
        return top_element;
    }
    
    int top() {
        int top_element = -1;
        if(qu2.empty() && qu1.size()>0){
            while(!qu1.empty()){
                top_element = qu1.front();
                qu2.push(qu1.front());
                qu1.pop();
            }
        }else if(qu1.empty()  && qu2.size()>0){
            while(!qu2.empty()){
                top_element = qu2.front();
                qu1.push(qu2.front());
                qu2.pop();
            }
        }
        return top_element;
    }
    
    bool empty() {
        return qu1.empty() && qu2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */