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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        // Find middle (slow/fast pointer)
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse second half
        ListNode *secondHalf = reverseList(slow->next);
        slow->next = nullptr; // Split lists
        
        // Merge alternately
        mergeLists(head, secondHalf);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void mergeLists(ListNode* l1, ListNode* l2) {
        while (l2) {
            ListNode *next1 = l1->next;
            ListNode *next2 = l2->next;
            
            l1->next = l2;
            l2->next = next1;
            
            l1 = next1;
            l2 = next2;
        } 
    }
};
