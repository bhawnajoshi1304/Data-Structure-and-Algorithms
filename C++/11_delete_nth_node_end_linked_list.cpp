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

//Leeetcode Problem: "https://leetcode.com/problems/remove-nth-node-from-end-of-list/"
//GeeksForGeeks Link: "https://www.geeksforgeeks.org/delete-nth-node-from-the-end-of-the-given-linked-list/"
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
            2 Methods
            1. Reverse the list and then remove nth element
                1.1 Reverse the list (O(N))
                1.2 Remove nth element(O(N))
                Two passes
            2. Two pointer method
                2.1 Two pointers p1 and o2, move p2 n steps
                2.2 move p1 and p2 both one step until p2 reaches null
                One pass
            2 is optimized, as it involves only one pass
        */
        
        
        //Method 2
        if(head==NULL)
            return head;
        int jump=n;
        //take two pointers both pointing to head initially
        ListNode *p1=head,*p2=head;
        
        //first, move p2 n distance apart, and then move p1 and p2 both on step,
        //until, p2 is null
        //p1 will be at nth postion from the end now, as p1 and p2 are 'n' steps             //apart
        while(p2&&jump--)
            p2=p2->next;
        
        //if p2 reaches null, head itself is the node to be removed
        if(!p2)
            return head->next;
        //else, move p2 and p1 until p2->next is not null, since one step before 
        //to change pointers
        while(p2->next)
        {
            p2=p2->next;
            p1=p1->next;
        }
        ListNode *temp=p1->next;
        p1->next=p1->next->next;
       
        return head;     
        
    }
};