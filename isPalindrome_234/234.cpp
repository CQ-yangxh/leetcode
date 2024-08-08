
#include <vector>
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
    bool isPalindrome(ListNode* head) {
        if(head->next == nullptr) return true;
        int count = 1;
        vector<int> nums;
        nums.push_back(head->val);
        ListNode *cur = head->next;
        ListNode *pre = head;
        ListNode *tmp = cur->next;
        head->next = nullptr;
        while(tmp != nullptr){
            count++;
            nums.push_back(cur->val);
            cur->next = pre;
            pre = cur;
            cur = tmp;
            tmp = cur->next;
        }
        count++;
        nums.push_back(cur->val);
        cur->next = pre;
        for(int i = 0; i < count/2; i++){
            if(nums[i] != cur->val) return false;
            cur = cur->next;
        }
        return true;
    }
};

int main(){
    ListNode *node4 = new ListNode(1, nullptr);
    ListNode *node3 = new ListNode(2, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *head = new ListNode(1, node2);
    Solution sol;
    bool res = sol.isPalindrome(head);
    return 0;
}