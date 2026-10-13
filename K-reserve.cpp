

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* dummy = head;
        while(dummy!=nullptr){
            len ++;
            dummy = dummy->next;
        }
        dummy = new ListNode();
        dummy->next = head;
        ListNode* mid = dummy;
        int start = 0;
        while(start + k <=len){
            start+=k;
            ListNode* starter = mid->next;
            ListNode* node = starter;
            for(int i = 0;i<k;i++){
                mid->next = starter->next;
                starter->next = mid->next->next;
                mid->next->next = node;
                node = mid->next;
            }
            mid = starter;
        }
        return dummy->next;
    }
};