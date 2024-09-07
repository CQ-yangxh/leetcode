#include <vector>
using namespace std;
struct ListNode{
    int _val;
    ListNode* _next;
    ListNode() : _val(0), _next(nullptr){}
    ListNode(int x) : _val(x), _next(nullptr){}
    ListNode(int x, ListNode* next) : _val(x), _next(next){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyhead;
        ListNode* curnode = dummyhead;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->_val > list2->_val){
                curnode->_next = list2;
                curnode = curnode->_next;
                list2 = list2->_next;
            }
            else{
                curnode->_next = list1;
                curnode = curnode->_next;
                list1 = list1->_next;
            }
        }

        while(list1 != nullptr){
            curnode->_next = list1;
            curnode = curnode->_next;
            list1 = list1->_next;
        }

        while(list2 != nullptr){
            curnode->_next = list2;
            curnode = curnode->_next;
            list2 = list2->_next;
        }
        return dummyhead->_next;
    }
};

ListNode* construct(vector<int> nums, int index){
    if(index == nums.size()) return nullptr;
    ListNode* node = new ListNode(nums[index], construct(nums, index+1));
    return node;
}

int main(){
    vector<int> nums1 = {1,2,4};
    vector<int> nums2 = {1,3,4};
    ListNode* list1 = construct(nums1, 0);
    ListNode* list2 = construct(nums2, 0);
    Solution sol;
    ListNode* res = sol.mergeTwoLists(list1, list2);
    return 0;
}