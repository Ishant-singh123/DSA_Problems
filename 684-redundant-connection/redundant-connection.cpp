class Solution {
public:
    // here edges list is give and edges list is give then DSU should be click 
    int find(vector<int>&parent,int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent,parent[x]);
    }

    bool unite(vector<int>&parent,vector<int>&rank,int a,int b){
         a=find(parent,a);
         b=find(parent,b);

        if(a==b){
            return true;
        }

        if(rank[a]>=rank[b]){
            parent[b]=a;
            rank[a]++;
        }
        else{
            parent[a]=b;
            rank[b]++;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>parent(edges.size()+1);
        vector<int>rank(edges.size()+1,0);
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
        for(int i=0;i<edges.size();i++){
            if(unite(parent,rank,edges[i][0],edges[i][1])){
                return edges[i];
            }
        }
        return {-1};
    }
};