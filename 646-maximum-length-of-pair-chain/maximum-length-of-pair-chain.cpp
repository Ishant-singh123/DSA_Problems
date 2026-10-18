class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());

        int len=INT_MIN;
        for(int i=0;i<pairs.size();i++){
            vector<vector<int>>ans;
            ans.push_back(pairs[i]);
            for(int j=i+1;j<pairs.size();j++){
                if(ans[ans.size()-1][1]<pairs[j][0]){
                    ans.push_back(pairs[j]);
                }
            }
            int n=ans.size();
            len=max(len,n);
        }
        for(int i=pairs.size()-1;i>=0;i--){
            vector<vector<int>>ans;
            ans.push_back(pairs[i]);
            for(int j=i-1;j>=0;j--){
                if(ans[ans.size()-1][0]>pairs[j][1]){
                    ans.push_back(pairs[j]);
                }
            }
            int n=ans.size();
            len=max(len,n);
        }
        return len;
    }
};