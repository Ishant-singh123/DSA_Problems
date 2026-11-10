class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int>v;
        for(int i=0;i<weights.size()-1;i++){
            v.push_back(weights[i]+weights[i+1]);
        }
        sort(v.begin(),v.end());
        long long sum_min=0;
        long long sum_max=0;
        for(int i=0;i<k-1;i++){
            sum_min=sum_min+v[i];
            sum_max=sum_max+v[v.size()-i-1];
        }
        return sum_max-sum_min;
    }
};