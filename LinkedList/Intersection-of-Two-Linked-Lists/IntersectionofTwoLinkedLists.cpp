/**
 * #160 Intersection of Two Linked Lists
 * 【2021-3-1】
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto a = headA, b = headB;

        if (!a || !b) return NULL;      //判空

        while (a != b)
        {
            if (!a) a = headB;          //当a走到末尾，则从b的开头继续走
            else a = a->next;           //还没走到末尾

            if (!b) b = headA;
            else b = b->next;
        }

        return a;
    }
};

class Solution2 {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

            //caculate the length of each List
            int lenA = getListLength(headA);
            int lenB = getListLength(headB);

            if (lenA<=0 || lenB<=0 ) return NULL;

            //let List A is the longest List;
            if (lenA < lenB){
                swap(headA, headB);
            }

            //move head of List A, make both of Lists are same length 
            for (int i=0; i<abs(lenA-lenB); i++){
                headA = headA->next;
            }

            //synced travel both of Lists and check their nodes are same or not 
            while (headA != headB){
                headA = headA->next;
                headB = headB->next;
            }

            return headA;
        }
    private:    
        inline int getListLength(ListNode *head){
            int len=0;
            while(head!=NULL){
                head = head->next;
                len++;
            }
            return len;
        }
};
