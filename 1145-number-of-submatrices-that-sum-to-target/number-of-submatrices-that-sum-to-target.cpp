class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        for(int i=0;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                matrix[i][j]=matrix[i][j]+matrix[i][j-1];
            }
        }
        
        int s_c=0;
        int count=0;

        for(int s_c=0;s_c<matrix[0].size();s_c++){
            for(int j=s_c;j<matrix[0].size();j++){
                unordered_map<int,int>mp;
                int sum=0;
                mp[0]++;
                for(int row=0;row<matrix.size();row++){
                    if(s_c>=1){
                        sum=sum+matrix[row][j]-matrix[row][s_c-1];
                    }
                    else{
                        sum=sum+matrix[row][j];
                    }
                    if(mp.find(sum-target)!=mp.end()){
                        count=count+mp[sum-target];
                    }
                    mp[sum]++;
                }
            }
        }
        return count;
    }
};