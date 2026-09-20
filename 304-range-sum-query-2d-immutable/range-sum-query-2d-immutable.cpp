class NumMatrix {
public:
    vector<vector<int>>prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        vector<int>v;
        for(int i=0;i<matrix[0].size();i++){
            v.push_back(0);
        }
        v.push_back(0);
        prefix.push_back(v);
        for(int i=0;i<matrix.size();i++){
            vector<int>temp;
            temp.push_back(0);
            for(int j=0;j<matrix[0].size();j++){
                temp.push_back(0);
            }
            prefix.push_back(temp);
        }
        for(int i=1;i<prefix.size();i++){
            for(int j=1;j<prefix[0].size();j++){
                prefix[i][j]=matrix[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2+1][col2+1]-prefix[row1][col2+1]-prefix[row2+1][col1]+prefix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */