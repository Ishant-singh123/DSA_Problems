class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>v;
        for(int i=0;i<position.size();i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int fleet=0;
        double lastime=0;
        for(int i=0;i<v.size();i++){
            double time=(double)(target-v[i].first)/v[i].second;
            if(time>lastime){
                fleet++;
                lastime=time;
            }
        }
        return fleet;
    }
};