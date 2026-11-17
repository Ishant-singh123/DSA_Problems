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
            rank[a]++;
            return ;
        }
        if(rank[a]>rank[b]){
            rank[a]=rank[a]+rank[b]+1;
            parent[b]=a;
        }
        else{
            rank[b]=rank[a]+rank[b]+1;
            parent[a]=b;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>rank(n,0);
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<edges.size();i++){
            unite(parent,rank,edges[i][0],edges[i][1]);
        }
        unordered_set<int>st;
        unordered_map<int,int>mp;
        for(int i=0;i<parent.size();i++){
            mp[find(parent,i)]++;
        }
        int cnt=0;
        for(int i=0;i<rank.size();i++){
            cout<<rank[i]<<" ";
        }
        cout<<endl;
        for(auto p:mp){
            cout<<p.first<<" "<<p.second<<endl;
            if(rank[p.first]==(p.second*(p.second-1))/2){
                cout<<rank[p.first]<<" "<<(((p.second)*(p.second-1))/2)<<endl;
                cnt++;
            }
        }
        return cnt;
    }
};