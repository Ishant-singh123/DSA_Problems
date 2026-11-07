class Solution {
public:
    bool check(vector<vector<int>>&pref,int r1,int c1,int r2,int c2,int thresh){
        int sum=pref[r2+1][c2+1]-pref[r1][c2+1]-pref[r2+1][c1]+pref[r1][c1];
        if(sum<=thresh){
            return true;
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        vector<vector<int>>pref(mat.size()+1,vector<int>(mat[0].size()+1,0));
        for(int i=1;i<pref.size();i++){
            for(int j=1;j<pref[0].size();j++){
                pref[i][j]=mat[i-1][j-1]+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
            }
        }
        // for(int i=0;i<pref.size();i++){
        //     for(int j=0;j<pref[0].size();j++){
        //         cout<<pref[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int maxlen=INT_MIN;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){

                for(int offset=0;offset<min(mat.size()-i,mat[0].size()-j);offset++){
                    if(check(pref,i,j,i+offset,j+offset,threshold)){
                        maxlen=max(maxlen,offset+1);
                    }
                }
            }
        }
        if(maxlen==INT_MIN){
            return 0;
        }
        return maxlen;
    }
};