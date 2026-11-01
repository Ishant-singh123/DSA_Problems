class Solution {
public:
    int longestWPI(vector<int>& hours) {
        // problem is like maximum subarray where sum is greater than zero
        unordered_map<int,int>mp;
        int count=0;
        int maxlen=0;
        for(int i=0;i<hours.size();i++){
            if(hours[i]>8){
                count++;
            }
            else{
                count--;
            }
            if(count>0){
                maxlen=max(maxlen,i+1);
                continue;
            }
            else if(mp.find(count)==mp.end()){
                mp[count]=i;
            }
            if(mp.find(count-1)!=mp.end()){
                maxlen=max(maxlen,i-mp[count-1]);
            }
        }
        return maxlen;
    }
};