class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // -4 -1 -1 0 1 2
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        unordered_map<int,int>mp1;
        for(int i=0;i<nums.size();i++){
            if(mp1.find(nums[i])!=mp1.end()){
                continue;
            }
            unordered_map<int,int>mp2;
            for(int j=i+1;j<nums.size();j++){
                if(mp2.find(nums[j])!=mp2.end()){
                    continue;
                }
                int find=-(nums[i]+nums[j]);
                int lo=j+1;
                int hi=nums.size()-1;
                vector<int>temp;
                while(lo<=hi){
                    int mid=(lo+hi)/2;
                    if(nums[mid]==find){
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[mid]);
                        ans.push_back(temp);
                        // lo++;
                        // hi--;
                        break;
                    }
                    else if(nums[mid]>find){
                        hi=mid-1;
                    }
                    else{
                        lo=mid+1;
                    }
                }
                mp2[nums[j]]++;
            }
            mp1[nums[i]]++;
        }
        return ans;

    }
};