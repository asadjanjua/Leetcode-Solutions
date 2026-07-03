/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
    //  unordered_set<ListNode*> visited;
    //  while(head!=NULL){
    //     if(visited.count(head))
    //     return true;
    //     visited.insert(head);

    //     head=head->next;
    //  }
    //  return false;

    ListNode* slow=head;
    ListNode* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
        return true;
    }
    return false;

    }
};