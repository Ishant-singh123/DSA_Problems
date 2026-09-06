class Solution {
public:
    int find(vector<int>&parent,int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent,parent[x]);
    }

    void unite(vector<int>&parent,vector<int>&rank,int a,int b){
        a=find(parent,a);
        b=find(parent,b);

        if(a==b){
            return ;
        }
        if(rank[a]>=rank[b]){
            parent[b]=a;
            rank[a]++;
        }
        else{
            parent[a]=b;
            rank[b]++;
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<string,int>mp;
        vector<int>parent(strs.size());
        vector<int>rank(strs.size(),0);
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
        for(int i=0;i<strs.size();i++){
            string t=strs[i];
            for(int j=0;j<strs[i].length();j++){
                for(int k=j;k<strs[i].length();k++){
                    swap(strs[i][j],strs[i][k]);
                    if(mp.find(strs[i])!=mp.end()){
                        unite(parent,rank,i,mp[strs[i]]);
                    }
                    swap(strs[i][j],strs[i][k]);
                }
            }
            mp[t]=i;
        }
        unordered_set<int>unique;
        for(int i=0;i<parent.size();i++){
            unique.insert(find(parent,i)); 
        }
        return unique.size();
    }
};