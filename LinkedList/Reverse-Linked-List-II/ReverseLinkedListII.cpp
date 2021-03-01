/**
 * #92 Reverse Linked List II
 * 【2021-2-28】
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n) {

    if (head==NULL || m>=n) return head;

    ListNode fake(0);
    fake.next = head;
    ListNode *pBegin=&fake, *pEnd=&fake;

    int distance = n - m ;
    while(pEnd && distance>0){
        pEnd = pEnd->next;
        distance--;
    } 
    while(pBegin && pEnd && m-1>0) {
        pBegin = pBegin->next;
        pEnd = pEnd->next;
        m--;
    }
    if (pBegin==NULL || pEnd==NULL || pEnd->next == NULL){
        return head;
    }
    
    ListNode *p = pBegin->next;
    ListNode *q = pEnd->next->next;
    
    ListNode *pHead = q;
    while(p != q){
        ListNode* node = p->next;
        p->next = pHead;
        pHead = p;
        p = node;
    }
    pBegin->next = pHead;

    return fake.next;
    
}

void printList(ListNode* h)
{
    while(h!=NULL){
        printf("%d ", h->val);
        h = h->next;
    }
    printf("\n");
}

ListNode* createList(int *a, int n)
{
    ListNode *head=NULL, *p=NULL;
    for(int i=0; i<n; i++){
        if (head == NULL){
            head = p = new ListNode(a[i]);
        }else{
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    return head;
}

ListNode* createList(int len) {
    int *a = new int[len];
    for(int i=0; i<len; i++) {
        a[i] = i+1;
    }
    ListNode* h =  createList(a, len);
    delete[] a;
    return h;
}

int main(int argc, char** argv) {
    int l=5;
    int  m=2, n=4;
    
    if (argc>1){
        l = atoi(argv[1]);
    }
    if (argc>2) {
        m = atoi(argv[2]);
    }
    if (argc>3) {
        n = atoi(argv[3]);
    }
    
    ListNode* h = createList(l);
    printList( h );
    printList( reverseBetween(h , m, n) );
    
}

class Solution2 {
public:
    ListNode* successor = NULL; // 后驱节点

    // 反转以 head 为起点的 n 个节点，返回新的头结点
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) { 
            // 记录第 n + 1 个节点
            successor = head->next;
            return head;
        }
        // 以 head.next 为起点，需要反转前 n - 1 个节点
        ListNode* last = reverseN(head->next, n - 1);

        head->next->next = head;
        // 让反转之后的 head 节点和后面的节点连起来
        head->next = successor;
        return last;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // base case
        if (left == 1) {
            return reverseN(head, right);
        }
        // 前进到反转的起点触发 base case
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
};
