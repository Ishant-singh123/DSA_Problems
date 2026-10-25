class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>start;
        vector<int>end;
        for(int i=0;i<intervals.size();i++){
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i=0;
        int j=0;
        int ans=INT_MIN;
        int room=0;
        while(i<start.size() && j<end.size()){
            if(start[i]<=end[j]){
                room++;
                ans=max(ans,room);
                i++;
            }
            else{
                room--;
                j++;
            }
        }
        return ans;
    }
};