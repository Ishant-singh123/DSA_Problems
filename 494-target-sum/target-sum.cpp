class Solution {
public:
    int f(vector<int>&v,int indx,int target,int t,map<pair<int,int>,int>&mp){
        if(indx==v.size()){
            if(t==target){
                return 1;
            }
            return 0;
        }
        if(mp.find({indx,t})!=mp.end()){
            return mp[{indx,t}];
        }
        return mp[{indx,t}]=f(v,indx+1,target,t+v[indx],mp)+f(v,indx+1,target,t-v[indx],mp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int count=0;
        int t=0;
        map<pair<int,int>,int>mp;
        return f(nums,0,target,t,mp);
    }
};