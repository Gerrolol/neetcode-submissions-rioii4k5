class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int>freq;
        for(int i =0; i<hand.size(); i++){
            freq[hand[i]]++;
        }
        sort(hand.begin(), hand.end());

        for(int i=0; i<hand.size(); i++){
            if(freq[hand[i]] == 0){
                continue;
            }
            for(int j = 0; j< groupSize; j++){
                if(freq[hand[i] + j] <= 0){
                   return false;
                }else{
                    freq[hand[i] + j]--;
                }
            }
        }
        return true;
    }
};
