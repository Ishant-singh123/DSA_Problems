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
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>parent(isConnected.size());
        vector<int>rank(isConnected.size(),0);
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
        for(int i=0;i<parent.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1){
                    unite(parent,rank,i,j);
                }
            }
        }
        unordered_set<int>unique;
        for(int i=0;i<parent.size();i++){
            unique.insert(find(parent,i));
        }
        return unique.size();
    }
};