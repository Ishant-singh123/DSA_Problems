class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            int maxi=INT_MIN;
            int maxi_ele=INT_MIN;
            for(auto p:mp){
                if(maxi<p.second){
                    maxi=p.second;
                    maxi_ele=p.first;
                }
            }
            ans.push_back(maxi_ele);
            mp.erase(maxi_ele);
        }
        return ans;
    }
};