class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>record;
        for(string op: operations){
            if(op == "+"){
                int topVal = record.top();
                record.pop();
                int secondVal = record.top();
                int sum = topVal + secondVal;
                record.push(topVal);
                record.push(sum);
            }else if(op == "D"){
                record.push(record.top()*2);
            }else if(op == "C"){
                record.pop();
            }else{
                record.push(stoi(op));
            }
        }
        int ans = 0;
        while(!record.empty()){
            ans += record.top();
            record.pop();
        }
        return ans;
    }
};

/*
3
2
1
*/