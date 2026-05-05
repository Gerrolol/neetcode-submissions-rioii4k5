class StockSpanner {
public:
    stack<int>vals;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(vals.empty()){
            vals.push(price);
            return 1;
        }else if(!vals.empty() && vals.top() > price){
            vals.push(price);
            return 1;
        }else{
            stack<int>vals2;
            int counter = 1;
            while(!vals.empty() && vals.top() <= price){
                counter++;
                vals2.push(vals.top());
                vals.pop();
            }
            while(!vals2.empty()){
                vals.push(vals2.top());
                vals2.pop();
            }
            vals.push(price);
            return counter;
        }
    }
};


/*
3
1 2
2 1
7 3 
*/
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */