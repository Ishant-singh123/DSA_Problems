/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>v;
        ListNode *temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int minD=INT_MAX;
        int maxD=INT_MIN;
        vector<int>indx;
        for(int i=1;i<v.size()-1;i++){
            if(v[i]>v[i-1] && v[i]>v[i+1]){
                indx.push_back(i);
            }
            if(v[i]<v[i-1] && v[i]<v[i+1]){
                indx.push_back(i);
            }
        }
        if(indx.size()==0){
            return {-1,-1};
        }
        for(int i=0;i<indx.size()-1;i++){
            minD=min(minD,indx[i+1]-indx[i]);
        }
        if(indx.size()>1){
            maxD=indx[indx.size()-1]-indx[0];
        }
        if(minD==INT_MAX){
            minD=-1;
        }
        if(maxD==INT_MIN){
            maxD=-1;
        }
        return {minD,maxD};
    }
};