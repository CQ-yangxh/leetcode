/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
输入：head = [1,2,3,4]
输出：[2,1,4,3]
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* cur = dummyhead;
        while (cur->next != NULL && cur->next->next != NULL){
            ListNode* tmp1 = cur->next;
            ListNode* tmp2 = tmp1->next;
            cur->next = tmp2;
            tmp1->next = tmp2->next;
            tmp2->next = tmp1;
            cur = tmp1;
        }
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
    third->next = fourth;
    fourth->next = NULL;
    Solution sol;
    ListNode* res = sol.swapPairs(head);
    return 0;
}