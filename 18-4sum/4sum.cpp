class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        unordered_set<int>st1;
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            if(st1.find(nums[i])!=st1.end()){
                continue;
            }
            unordered_set<int>st2;
            for(int j=i+1;j<nums.size();j++){
                if(st2.find(nums[j])!=st2.end()){
                    continue;
                }
                unordered_set<int>st3;
                for(int k=j+1;k<nums.size();k++){
                    if(st3.find(nums[k])!=st3.end()){
                        continue;
                    }
                    long long curr=(long long)((long long)nums[i]+(long long)nums[j]+(long long)nums[k]);
                    int lo=k+1;
                    int hi=nums.size()-1;
                    vector<int>temp;
                    while(lo<=hi){
                        int mid=(lo+hi)/2;
                        if(nums[mid]+curr==target){
                            temp.push_back(nums[i]);
                            temp.push_back(nums[j]);
                            temp.push_back(nums[k]);
                            temp.push_back(nums[mid]);
                            ans.push_back(temp);
                            break;
                        }
                        else if(nums[mid]+curr>target){
                            hi=mid-1;
                        }
                        else{
                            lo=mid+1;
                        }
                    }
                    st3.insert(nums[k]);
                }
                st2.insert(nums[j]);
            }
            st1.insert(nums[i]);
        }
        return ans;
    }
};