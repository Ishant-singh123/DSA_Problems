class Solution {
public:
    void bfs(queue<pair<int,int>>&q,vector<vector<bool>>&can_go,vector<vector<int>>&h){
        while(q.size()>0){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x+1>=0 && x+1<can_go.size() && h[x+1][y]>=h[x][y] && can_go[x+1][y]==false){
                can_go[x+1][y]=true;
                q.push({x+1,y});
            }
            if(y+1>=0 && y+1<can_go[0].size() && h[x][y+1]>=h[x][y] && can_go[x][y+1]==false){
                can_go[x][y+1]=true;
                q.push({x,y+1});
            }
            if(x-1>=0 && x-1<can_go.size() && h[x-1][y]>=h[x][y] && can_go[x-1][y]==false){
                can_go[x-1][y]=true;
                q.push({x-1,y});
            }
            if(y-1>=0 && y-1<can_go[0].size() && h[x][y-1]>=h[x][y] && can_go[x][y-1]==false){
                can_go[x][y-1]=true;
                q.push({x,y-1});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>>pacificbfs(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<bool>>atlanticbfs(heights.size(),vector<bool>(heights[0].size(),false));
        queue<pair<int,int>>qp;
        queue<pair<int,int>>qa;
        for(int i=0;i<heights.size();i++){
            pacificbfs[i][0]=true;
            qp.push({i,0});
            qa.push({i,heights[0].size()-1});
            atlanticbfs[i][heights[0].size()-1]=true;
        }
        for(int j=1;j<heights[0].size();j++){
            pacificbfs[0][j]=true;
            qp.push({0,j});
        }
        for(int j=0;j<heights[0].size()-1;j++){
            qa.push({heights.size()-1,j});
            atlanticbfs[heights.size()-1][j]=true;
        }
        bfs(qp,pacificbfs,heights);
        bfs(qa,atlanticbfs,heights);
        vector<vector<int>>ans;
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(atlanticbfs[i][j]==true && pacificbfs[i][j]==true){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};