#include <climits>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         ListNode* dummyhead = new ListNode(INT_MIN, head);
//         ListNode* flagnode = nullptr;
//         ListNode* lastnode = dummyhead;
//         ListNode* curnode;
//         ListNode* nextnode;
//         while(dummyhead->next && dummyhead->next->next && flagnode != dummyhead->next->next){
//             curnode = lastnode->next;
//             nextnode = curnode->next;
//             while(lastnode->next->next && lastnode->next->next != flagnode){
//                 if(curnode->val > nextnode->val){
//                     lastnode->next = nextnode;
//                     curnode->next = nextnode->next;
//                     nextnode->next = curnode;
//                 }
//                 lastnode = lastnode->next;
//                 curnode = lastnode->next;
//                 nextnode = curnode->next;
//             }
//             lastnode = dummyhead;
//             flagnode = curnode;
//         }
//         return dummyhead->next;
//     }
// };

class Solution {
public:
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummynode = new ListNode();
        ListNode *node1 = head1, *node2 = head2;
        ListNode* temp = dummynode;
        while(node1 != nullptr && node2 != nullptr){
            if(node1->val > node2->val){
                temp->next = node2;
                node2 = node2->next;
            }else{
                temp->next = node1;
                node1 = node1->next;
            }
            temp = temp->next;
        }

        if(node1 != nullptr)
            temp->next = node1;

        if(node2 != nullptr)
            temp->next = node2;

        return dummynode->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return nullptr;
        int len = 0;
        ListNode* node = head;
        while(node != nullptr){
            node = node->next;;
            len++;
        }
        ListNode* dummynode = new ListNode(0, head);
        for(int sublen = 1; sublen < len; sublen <<= 1){
            ListNode* pre = dummynode, *curr = dummynode->next;
            while(curr != nullptr){
                ListNode* head1 = curr;
                for(int i = 1; i < sublen && curr->next != nullptr; i++){
                    curr = curr->next;
                }

                ListNode* head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for(int i = 1; i < sublen && curr != nullptr && curr->next != nullptr; i++){
                    curr = curr->next;
                }
                ListNode* next = nullptr;
                if(curr != nullptr){
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode* mergenode = merge(head1, head2);
                pre->next = mergenode;
                while (pre->next != nullptr) {
                    pre = pre->next;
                }
                curr = next;
            }
        }
        return dummynode->next;
    }
};

ListNode* constructList(vector<int>& arr, int id){
    if(id == arr.size() - 1) return new ListNode(arr[id]);
    ListNode* head = new ListNode(arr[id], constructList(arr, ++id));
    return head;
}

int main(){
    vector<int> arr = {4,2,3,1};
    ListNode* head = constructList(arr, 0);
    Solution sol;
    ListNode* res = sol.sortList(head);
    return 0;
}