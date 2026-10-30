class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>v(words.size()+1,0);
        for(int i=0;i<words.size();i++){
            if((words[i][0]=='a' || words[i][0]=='e' || words[i][0]=='i' || words[i][0]=='o' || words[i][0]=='u') && (words[i][words[i].length()-1]=='a' || words[i][words[i].length()-1]=='e' || words[i][words[i].length()-1]=='i' || words[i][words[i].length()-1]=='o' || words[i][words[i].length()-1]=='u')){
                v[i+1]=v[i]+1;
            }
            else{
                v[i+1]=v[i];
            }
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(v[queries[i][1]+1]-v[queries[i][0]]);
        }
        return ans;
    }
};