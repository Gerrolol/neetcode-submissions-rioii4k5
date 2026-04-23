class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0){
            nums1 = nums2;
            return;
        }
        for(int num: nums2){
            for(int i=0; i<m+n; i++){
                if(num < nums1[i]){
                    int temp = nums1[i];
                    nums1[i] = num; 
                    for(int j = i+1; j<m+n; j++){
                        int newnum = nums1[j];
                        nums1[j] = temp;
                        temp = newnum;
                    }
                    break;
                }else if(i >= m && nums1[i] == 0){
                    cout << "runs" << endl;
                    nums1[i] = num;
                    break;
                }
            }

            for(int val : nums1){
                cout << val << " ";
            }
            cout << endl;
        }
    }
};


/*
10,20,20,40,0,0
   15 
insert 1 
*/