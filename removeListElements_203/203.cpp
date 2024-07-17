/*
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummynode = new ListNode(0);
        dummynode->next = head;
        ListNode* curnode = dummynode;
        while (curnode->next != NULL){
            if (curnode->next->val == val) {
                ListNode* temp = curnode->next;
                curnode->next = temp->next;
                delete  temp;
            }
            else curnode = curnode->next;
        }
        head = dummynode->next;
        delete dummynode;
        return head;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    head->next = second;
    ListNode* third = new ListNode(6);
    second->next = third;
    ListNode* fourth = new ListNode(3);
    third->next = fourth;
    ListNode* fifth = new ListNode(4);
    fourth->next = fifth;
    ListNode* sixth = new ListNode(5);
    fifth->next = sixth;
    ListNode* seventh = new ListNode(6);
    sixth->next = NULL;
    Solution sol;
    ListNode* res = sol.removeElements(head, 6);

    return 0;
}
