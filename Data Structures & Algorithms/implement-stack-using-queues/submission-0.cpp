class MyStack {
public:
    queue<int>q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        queue<int>q2;
        int ans = 0;
        while(!q1.empty()){
            if(q1.size() == 1){
                ans = q1.front();
                q1.pop();
            }else{
                int val = q1.front();
                q1.pop();
                q2.push(val);
            }
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
    }
    
    int top() {
        queue<int>q2;
        int ans = 0;
        while(!q1.empty()){
            if(q1.size() == 1){
                ans = q1.front();
                q2.push(ans);
            }else{
                int val = q1.front();
                q2.push(val);
            }
            q1.pop();
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
    }
    
    bool empty() {
        if(q1.size() == 0){
            return true;
        }
        return false;
    }
};


/*
    3
    2
    1

    queue: 1,2
    queue: 1,2 
*/

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */