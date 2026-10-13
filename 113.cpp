#include<iostream>
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
    ListNode* merge(ListNode* node1,ListNode* node2){
        ListNode* res = new ListNode();
        ListNode* mid = res;
        while(node1!=nullptr&&node2!=nullptr){
            if(node1->val<node2->val){
                mid->next = node1;
                node1 = node1->next;
            }else{
                mid->next = node2;
                node2 = node2->next;
            }
            mid = mid->next;
        }
        while(node1!=nullptr){
            mid->next = node1;
            mid = mid->next;
            node1 = node1->next;
        }
        while(node2!=nullptr){
            mid->next = node2;
            mid = mid->next;
            node2 = node2->next;
        }
        return res->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr){
            if(fast->next!=nullptr){
                if(fast->next->next!=nullptr){
                    fast = fast->next->next;
                    slow = slow->next;
                }else{
                    break;
                }
            }else{
                break;
            }
        }
        ListNode* right = slow->next;
        slow->next = nullptr;
        ListNode* left = head;
        right = sortList(right);
        left = sortList(left);
        return merge(left,right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        ListNode* mid = dummy;
        for(int i = 0;i<lists.size();i++){
            ListNode* list = lists[i];
            while(list!=nullptr){
                mid->next = list;
                mid = mid->next;
                list = list->next;
            }
        }
        if(dummy->next==nullptr){
            return nullptr;
        }
        return sortList(dummy->next);
    }
};