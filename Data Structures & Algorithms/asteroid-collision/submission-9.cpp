class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>best;
        for(int rock : asteroids){
            int bestRock = best.top();
            if(best.empty() || (bestRock < 0 && rock < 0) || (bestRock > 0 && rock > 0) || (bestRock < 0 && rock > 0)){
                best.push(rock);
            }else if(abs(bestRock) > abs(rock)){
                continue;
            }else if(abs(bestRock) == abs(rock)){
                best.pop();
            }else{
                while(!best.empty() && (best.top() > 0 && rock < 0) && abs(best.top()) < abs(rock)){
                    best.pop();
                }
                // cout << "called" << endl;
                if(best.empty() || (best.top() < 0 && rock < 0) || (best.top() > 0 && rock > 0) || (best.top() < 0 && rock > 0)){
                    best.push(rock);
                }else if(abs(best.top()) == abs(rock)){
                    best.pop();
                }
            }
        }
        vector<int>remainingRocks;
        while(!best.empty()){
            remainingRocks.push_back(best.top());
            best.pop();
        }
        reverse(remainingRocks.begin(), remainingRocks.end());
        return remainingRocks;
    }
};

/*
[2,4,-4,-1]
 ^ 


[5,5]


[7,-3,9]

9
7
stack
*/


