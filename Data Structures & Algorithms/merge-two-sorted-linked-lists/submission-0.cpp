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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *newh=new ListNode(0),*head=newh;
        while(list1 && list2)
        {
            if(list1->val<=list2->val)
            {
                newh->next=list1;
                list1=list1->next;
            }
            else 
            {
                newh->next=list2;
                list2=list2->next;
            }
            newh=newh->next;
        }
        if(list1)
        newh->next=list1;
        if(list2)
        newh->next=list2;
        ListNode *del =head;
        head=head->next;
        delete(del);

        return head;
    }
};
