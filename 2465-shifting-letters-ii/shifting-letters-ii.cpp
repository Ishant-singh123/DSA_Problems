class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>v(s.length()+1,0);
        for(int i=0;i<shifts.size();i++){
            if(shifts[i][2]==1){
                v[shifts[i][0]]=v[shifts[i][0]]+1;
                v[shifts[i][1]+1]=v[shifts[i][1]+1]-1;
            }
            else{
                v[shifts[i][0]]=v[shifts[i][0]]-1;
                v[shifts[i][1]+1]=v[shifts[i][1]+1]+1;
            }
        }
        for(int i=1;i<v.size();i++){
            v[i]=v[i]+v[i-1];
        }
        for(int i=0;i<v.size();i++){
            if(v[i]>0){
                v[i]=v[i]%26;
            }
            else{
                v[i]=-abs(v[i])%26;
            }
        }
        string ans="";
        for(int i=0;i<s.length();i++){
            if(v[i]>0){
                if(s[i]+v[i]>122){
                    ans.push_back(96+((s[i]+v[i])-122));
                }
                else{
                    ans.push_back(s[i]+v[i]);
                }
            }
            else{
                if(s[i]+v[i]<97){
                    ans.push_back(123-(97-(s[i]+v[i])));
                }
                else{
                    ans.push_back(s[i]+v[i]);
                }
            }
        }
        return ans;
    }
};