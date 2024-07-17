/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyhead = new ListNode(0, head);
        ListNode* fast = dummyhead;
        ListNode* slow = dummyhead;
        for (int i = 0; i < n; i++) fast = fast->next;
        while (fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;
        head = dummyhead->next;
        delete dummyhead;
        return head;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    head->next = second;
    ListNode* third = new ListNode(3);
    second->next = third;
    ListNode* fourth = new ListNode(4);
    third->next = NULL;
    ListNode* fifth = new ListNode(5);
    fourth->next = fifth;
    fifth->next = NULL;
    Solution sol;
    int n = 3;
    ListNode* res = sol.removeNthFromEnd(head, n);
    return 0;
}