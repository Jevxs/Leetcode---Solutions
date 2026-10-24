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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);    //dummy node local di stack
        ListNode* tail = &dummy; //l1 pointer
        int carry = 0;    //simpan sisa penjumlh

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
                
            }
            // carry baru untuk digit berikut
            carry = sum/10 ;
            // node baru
            tail->next = new ListNode(sum % 10);
            tail = tail->next; //penggeseran pointer
        }
        return dummy.next; //kemabalikan head asli sebelah dummy node
    }
};
