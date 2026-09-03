class Solution {
public:
    void dist(vector<vector<int>>& mat,queue<pair<int,int>>&q){
        while(q.size()>0){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x+1>=0 && x+1<mat.size() && mat[x+1][y]==INT_MAX){
                mat[x+1][y]=min(mat[x+1][y],mat[x][y]+1);
                q.push({x+1,y});
            }
            if(x-1>=0 && x-1<mat.size() && mat[x-1][y]==INT_MAX){
                mat[x-1][y]=min(mat[x-1][y],mat[x][y]+1);
                q.push({x-1,y});
            }
            if(y+1>=0 && y+1<mat[0].size() && mat[x][y+1]==INT_MAX){
                mat[x][y+1]=min(mat[x][y+1],mat[x][y]+1);
                q.push({x,y+1});
            }
            if(y-1>=0 && y-1<mat[0].size() && mat[x][y-1]==INT_MAX){
                mat[x][y-1]=min(mat[x][y-1],mat[x][y]+1);
                q.push({x,y-1});
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                if(mat[i][j]==1){
                    mat[i][j]=INT_MAX;
                }
            }
        }
        dist(mat,q);
        return mat;
    }
};