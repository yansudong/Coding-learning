/**
 * #141 Linked List Cycle
 * 【2021-3-5】
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// 方法一 哈希表
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        while (head != nullptr) {
            if (seen.count(head)) {
                return true;
            }
            seen.insert(head);
            head = head->next;
        }
        return false;
    }
};


//方法二 标记法
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* p = head;
        // using INT_MAX as the mark could be a bug!
        while( p &&  p->val != INT_MAX ) {
            p->val = INT_MAX;
            p = p -> next;
        }
        return p != NULL;
    }
}


//方法三 快慢指针
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
