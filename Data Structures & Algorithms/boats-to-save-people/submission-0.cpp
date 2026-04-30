class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int numPeople = people.size()-1;
        sort(people.begin(), people.end());
        int left = 0;
        int right = numPeople;
        int numBoats = 0;
        while(left + numPeople-right <= numPeople){
            if(people[right] == limit){
                right--;
            }else if(people[left] + people[right] <= limit){
                right--;
                left++;
            }else{
                right--;
            }
            numBoats++;
        }
        return numBoats;
    }
};


/*
limit = 6
1,2,4,5
  ^ ^

1,2,2,3,3
^ ^

*/