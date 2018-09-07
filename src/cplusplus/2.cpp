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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* node_head = NULL;
        ListNode* node_tail = NULL;
        
        int val_l1 = 0;
        ListNode* node_l1 = l1;
        
        int val_l2 = 0;
        ListNode* node_l2 = l2;
        
        int v_l1, v_l2, v_sum_bit = 0;
        int v_bit_last = 0;
        
        while (node_l1 || node_l2)
        {
            v_l1 = v_l2 = 0;
            
            if (node_l1)
                v_l1 = node_l1->val;
            
            if (node_l2)
                v_l2 = node_l2->val;
            
            v_sum_bit = v_l1 + v_l2 + v_bit_last; 
            int v_add = v_sum_bit % 10;         
            v_bit_last = v_sum_bit / 10;
            
            ListNode* node_new = new ListNode(v_add);
            if (!node_head)
            {
                node_head = node_new;
                node_tail = node_head;
            }                            
            else
            {
                node_tail->next = node_new;
                node_tail = node_new;
            }
                         
            if (node_l1)
                node_l1 = node_l1->next;
            
            if (node_l2)
                node_l2 = node_l2->next;
        }
        
        if (v_bit_last)
            node_tail->next = new ListNode(1);
        
        return node_head;
        
    }
};
