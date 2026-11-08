class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int>pre_r(grid.size(),0);
        for(int i=0;i<grid.size();i++){
            int sum=0;
            for(int j=0;j<grid[0].size();j++){
                sum=sum+grid[i][j];
            }
            pre_r[i]=sum;
        }
        vector<int>pre_c(grid[0].size(),0);
        for(int j=0;j<grid[0].size();j++){
            int sum=0;
            for(int i=0;i<grid.size();i++){
                sum=sum+grid[i][j];
            }
            pre_c[j]=sum;
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && (pre_r[i]>1 || pre_c[j]>1)){
                    ans++;    
                }
            }
        }
        return ans;
    }
};