class Solution {
public:
    // dsu extra yaha prr is liye liya kyu ki dfs ke through branches aapas mai overlap karke extra again count leti h 
    int find(vector<int>&parent,int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent,parent[x]);
    }

    void unite(vector<int>&parent,vector<int>&size,int a,int b){
        a=find(parent,a);
        b=find(parent,b);

        if(a==b){
            return ;
        }
        if(size[a]>=size[b]){
            size[a]=size[a]+size[b];
            parent[b]=a;
        }
        else{
            size[b]=size[a]+size[b];
            parent[a]=b;
        }
    }
    void dfs(vector<vector<int>>&grid,int i,int j,int last,vector<int>&parent,vector<int>&size){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            return ;
        }
        if(grid[i][j]==0 || grid[i][j]==-1){
            return ;
        }
        unite(parent,size,last,i*grid.size()+j);
        grid[i][j]=-1;
        dfs(grid,i+1,j,i*grid.size()+j,parent,size);
        dfs(grid,i-1,j,i*grid.size()+j,parent,size);
        dfs(grid,i,j+1,i*grid.size()+j,parent,size);
        dfs(grid,i,j-1,i*grid.size()+j,parent,size);
    }
    int largestIsland(vector<vector<int>>& grid) {
        vector<int>parent(grid.size()*grid.size());
        vector<int>size(grid.size()*grid.size(),1);
        for(int i=0;i<grid.size()*grid.size();i++){
            parent[i]=i;
        }
        int n=grid.size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,i*n+j,parent,size);
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    int temp=0;
                    unordered_set<int>st;
                    if(i-1>=0 && grid[i-1][j]==-1){
                        st.insert(find(parent,(i-1)*n+j));
                    }
                    if(i+1<n && grid[i+1][j]==-1){
                        st.insert(find(parent,(i+1)*n+j));
                    }
                    if(j+1<n && grid[i][j+1]==-1){
                        st.insert(find(parent,i*n+j+1));
                    }
                    if(j-1>=0 && grid[i][j-1]==-1){
                        st.insert(find(parent,i*n+j-1));
                    }
                    for(auto p:st){
                        temp=temp+size[p];
                    }
                    ans=max(ans,1+temp);
                }
            }
        }
        if(ans==INT_MIN){
            return n*n;
        }
        return ans;
    }
};