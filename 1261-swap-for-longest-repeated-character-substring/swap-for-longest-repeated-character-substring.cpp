class Solution {
public:
    int maxRepOpt1(string text) {
        int i=0;
        int j=0;
        int ans=0;
        unordered_map<char,int>mp;
        for(int i=0;i<text.size();i++){
            mp[text[i]]++;
        }
        vector<int>v(26,0);
        char maxc=0;
        int maxf=0;
        while(j<text.size()){
            v[text[j]-'a']++;
            mp[text[j]]--;
            if(maxf<=v[text[j]-'a']){
                maxf=v[text[j]-'a'];
                maxc=text[j];
            }
            if((j-i+1)-maxf<=1){
                if(mp[maxc]>0){
                    ans=max(ans,j-i+1);
                }
            }
            else{
                v[text[i]-'a']--;
                mp[text[i]]++;
                i++;
            }
            j++;
        }
        return ans;
    }
};