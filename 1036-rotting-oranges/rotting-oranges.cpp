class Solution {
public:
    int mintime(queue<pair<int,int>>&q,vector<vector<int>>&grid,int &fresh){
        int time=0;
        while(q.size()>0){
            int n=q.size();
            while(n>0){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x+1>=0 && x+1<grid.size() && grid[x+1][y]==1){
                    grid[x+1][y]=2;
                    q.push({x+1,y});
                    fresh--;
                }
                if(x-1>=0 && x-1<grid.size() && grid[x-1][y]==1){
                    grid[x-1][y]=2;
                    q.push({x-1,y});
                    fresh--;
                }
                if(y+1>=0 && y+1<grid[0].size() && grid[x][y+1]==1){
                    grid[x][y+1]=2;
                    q.push({x,y+1});
                    fresh--;
                }
                if(y-1>=0 && y-1<grid[0].size() && grid[x][y-1]==1){
                    grid[x][y-1]=2;
                    q.push({x,y-1});
                    fresh--;
                }
                n--;
            }
            time++;
        }
        if(fresh==0){
            return time-1;
        }
        return -1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0){
            return 0;
        }
        return mintime(q,grid,fresh);
    }
};