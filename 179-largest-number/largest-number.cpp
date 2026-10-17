bool cmp(int a,int b){
    string x=to_string(a);
    string y=to_string(b);
    return x+y>y+x;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
       sort(nums.begin(),nums.end(),cmp);
       bool check=false;
       for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                check=true;
                break;
            }
       }
       if(check==false){
            return "0";
       }
       string ans="";
       for(int i=0;i<nums.size();i++){
        ans=ans+to_string(nums[i]);
       } 
       return ans;
    }
};