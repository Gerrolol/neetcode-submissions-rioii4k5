class NumMatrix {
public:
    vector<vector<int>>Matrix;
    vector<vector<int>>prefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
        Matrix = matrix;
        prefixSum = Matrix;
        findPrefixSum();
    }
    
    void findPrefixSum(){
        for(int row =0; row<Matrix.size(); row++){
            for(int col = 0; col< Matrix[0].size(); col++){
                int count = 0;
                if(row-1 >= 0){
                    prefixSum[row][col] += prefixSum[row-1][col];
                    count++;
                }
                if(col-1 >= 0){
                    prefixSum[row][col] += prefixSum[row][col-1];
                    count++;
                }
                if(count == 2){
                    prefixSum[row][col] -= prefixSum[row-1][col-1];
                }
            }
        }   
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = prefixSum[row2][col2];
        int count = 0;
        if(row1-1 >=0){
            total -= prefixSum[row1-1][col2];
            count++;
        }
        if(col1-1 >=0){
            total -= prefixSum[row2][col1-1];
            count++;
        }
        if(count == 2){
            total += prefixSum[row1-1][col1-1];
        }
        return total;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */