class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        for(int i=0;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                grid[i][j]=grid[i][j-1]+grid[i][j];
            }
        }
        int count=0;
        for(int s_c=0;s_c<grid[0].size();s_c++){
            int sum=0;
            for(int row=0;row<grid.size();row++){
                sum=sum+grid[row][s_c];
                if(sum<=k){
                    count++;
                }
            }
        }
        return count;
    }
};