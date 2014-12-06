#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode *tmp = head;
        int n = count(tmp);
        cout << "n :" << n << endl;
        
        if (n == 1 || n == 0) return head;
        
        ListNode *a = head;
        ListNode *b = middle(head, n);
        
       // cout << "mid->val :" << b->val << endl;

        sortList(a);
        sortList(b);
        head = mergeTwoLists(a,b);
        
        return head;
    }
    
    int count(ListNode *n){
        int tmp = 0;
        while(n){
            n = n->next;
            tmp++;
        }
        
        return tmp;
    }
    
    ListNode *middle(ListNode *head, const int n){
        int tmp = 0;
        ListNode *mid = head;
        
        while(tmp < n / 2){
            mid = mid->next;
            tmp++;
        }
        
        return mid;
        
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val > l2->val){
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        else{
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        
    }
};

int main(){
    ListNode *head = new ListNode(2);
    head->next = new ListNode(1);

    Solution s;

    s.sortList(head);
}
