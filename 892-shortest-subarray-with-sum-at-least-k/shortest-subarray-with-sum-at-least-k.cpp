class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<int,int>>dq;
        vector<int>pre(nums.size()+1,0);
        pre[1]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i+1]=nums[i]+pre[i];
        }
        int i=0;
        int j=0;
        int minlen=INT_MAX;
        while(j<pre.size()){
            int currsum=pre[j];
            if(currsum>=k){
                minlen=min(minlen,j-i);
            }
            while(dq.size()>0 && currsum-dq.front().first>=k){
                i=dq.front().second;
                minlen=min(minlen,j-i);
                dq.pop_front();
            }
            while(dq.size()>0 && dq.back().first>=pre[j]){
                dq.pop_back();
            }
            dq.push_back({pre[j],j});
            j++;
        }
        if(minlen==INT_MAX){
            return -1;
        }
        return minlen;
    }
};