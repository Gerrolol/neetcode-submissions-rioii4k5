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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* dumhead= new ListNode(0);
    dumhead->next=head;
    ListNode* pre=dumhead;
    for(int i=0;i<left-1;i++)
        pre=pre->next;
    ListNode* cur = pre->next;
    for(int i=0;i<right-left;i++){
        ListNode* temp = cur->next;
        cur->next=temp->next;
        temp->next=pre->next;
        pre->next=temp;
    }
    ListNode* res = dumhead->next;
    return res;
    }
};
