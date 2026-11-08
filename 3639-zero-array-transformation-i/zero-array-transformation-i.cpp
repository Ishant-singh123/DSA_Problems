class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>v(nums.size()+1,0);
        for(int i=0;i<queries.size();i++){
            v[queries[i][0]]=v[queries[i][0]]-1;
            v[queries[i][1]+1]=v[queries[i][1]+1]+1;
        }
        for(int i=1;i<v.size();i++){
            v[i]=v[i]+v[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]+v[i]>0){
                return false;
            }
        }
        return true;

    }
};