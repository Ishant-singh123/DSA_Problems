class Solution {
public:
    // generally matrix ke graph ke quesiton mai reverse mai sochna hota h 
    void solver(queue<pair<int,int>>&q,vector<vector<char>>&board){
        while(q.size()>0){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x+1>=0 && x+1<board.size() && board[x+1][y]=='O'){
                board[x+1][y]='E';
                q.push({x+1,y});
            }
            if(x-1>=0 && x-1<board.size() && board[x-1][y]=='O'){
                board[x-1][y]='E';
                q.push({x-1,y});
            }
            if(y+1>=0 && y+1<board[0].size() && board[x][y+1]=='O'){
                board[x][y+1]='E';
                q.push({x,y+1});
            }
            if(y-1>=0 && y-1<board[0].size() && board[x][y-1]=='O'){
                board[x][y-1]='E';
                q.push({x,y-1});
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>>q;
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){
                q.push({i,0});
            }
            if(board[i][board[0].size()-1]=='O'){
                q.push({i,board[0].size()-1});
            }
        }
        for(int j=1;j<board[0].size()-1;j++){
            if(board[0][j]=='O'){
                q.push({0,j});
            }
            if(board[board.size()-1][j]=='O'){
                q.push({board.size()-1,j});
            }
        }
        solver(q,board);
        for(int i=1;i<board.size()-1;i++){
            for(int j=1;j<board[0].size()-1;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='E'){
                    board[i][j]='O';
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='E'){
                    board[i][j]='O';
                }
            }
        }
    }
};