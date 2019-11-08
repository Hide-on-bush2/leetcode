#include<new>
#include<iostream>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* findPrevious(ListNode* head, int val){
        if(!head){return nullptr;}
        ListNode* pos = head;
        if(pos->val > val){return nullptr;}
        while(pos->next != nullptr && pos->next->val < val){pos = pos->next;}
        return pos;
    }
    bool insertion(ListNode* previous, ListNode* pos){
        if(!previous){
            ListNode* nextNode = previous->next;
            previous->next = pos;
            pos->next = nextNode;
            return true;
        }
        return false;
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode* res = nullptr, *pos = head;
        while(pos != nullptr){
            ListNode* previousPos = findPrevious(res, pos->val);
            ListNode* tempNode = new ListNode(pos->val);
            if(!previousPos){
                if(!res){res = tempNode;}
                else{tempNode->next = res;}
            }
            else{
                insertion(previousPos, tempNode);
            }
            pos = pos->next;
        }
        return res;
    }
};