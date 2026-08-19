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
#define ppi pair<int,int>
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ppi,vector<ppi>,greater<ppi>> minh;

        ListNode* dummy=new ListNode(-1);
        ListNode* ans=dummy;
        for(int i=0;i<lists.size();i++){
           if(lists[i] != nullptr){
            minh.push({lists[i]->val, i});         
            }
         }
         while(!minh.empty()){
          int index=minh.top().second;
          ans->next=new ListNode(lists[index]->val);
          ans = ans->next;
          minh.pop();
          lists[index] = lists[index]->next;
          if(lists[index]!=nullptr) minh.push({lists[index]->val,index});
         }
  return dummy->next;
    }
};