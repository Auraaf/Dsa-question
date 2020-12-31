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
    ListNode* middleNode(ListNode* head) {
        ListNode* sl , *fas;
        sl = head ;
        fas= head ;
        
        while (fas != NULL && fas -> next != NULL)
        {
            sl = sl->next ;
            fas = fas ->next ->next ;
        }
        
        return sl ;
    }
};
