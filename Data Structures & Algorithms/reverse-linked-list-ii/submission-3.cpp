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
        if(left == right){
            return head;
        }
        int counter = 1;
        ListNode*tracker = head;
        ListNode*tempTrack = head;
        while(counter <= left-1){
            tracker = tracker->next;
            if(counter < left-1){
                tempTrack = tempTrack->next;
            }
            counter++;
        }
        ListNode*before = tracker;
        
        ListNode*previous = nullptr;
        while(counter <= right){
            ListNode*nextNode = tracker->next;
            tracker->next = previous;
            previous = tracker;
            tracker = nextNode;
            counter++;
        }
        // cout << tracker->val << endl;
        // cout << previous->val << endl;
        
        before->next = tracker;
        cout << before->val << endl;
        if(left == 1){
            return previous;
        }
        cout << tempTrack->val;
        tempTrack->next = previous;
        return head;
    }
};

/*
stores the *next of the one before the left index.

3->2->1->null
1->2->3->4->5
   ^
1->null 
2->1
3->2
head = 3

 
*/