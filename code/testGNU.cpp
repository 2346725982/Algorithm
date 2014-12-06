#include <iostream>
using namespace std;

struct ListNode {
int val;
ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *fakehead = new ListNode(0);
        fakehead->next = head;
        
        int n = 0;

        ListNode *walker = fakehead;
        while(walker->next != NULL){
            cout << "the next element, " << ++n << endl;
            int value = walker->next->val;
            cout << value << endl;:
            ListNode *tmp = walker->next->next;
            
            while(tmp != NULL && tmp->val == value)
                tmp = tmp->next;
                
            walker->next = tmp;

            //ListNode *test = fakehead;

           // while(test != NULL)
        }

        return fakehead->next;
    };

    int a;
    for(int i = 0; I )
};

int main(){
    ListNode *a = new ListNode(1);
    a->next = new ListNode(2);

    Solution s;

    s.deleteDuplicates(a);

    int a 0


        itn 0jd0

        for(int i =0 0)
            int a;
    int a;
    int allllll

    for(int i = 0; i < n; i++){

    }
    int a;
    for(int i = 0; )
        int a;
    for(int i; i < )
        int a 0
            int a0
            int a;
    :conf q

        int a;
    
    int a;
    for(int i = 0; i < 0; i ++):
        int a;

    int a;
    for(int i = i; ;);


    int a;
    {
        {
            {
            }
            }
        }
}llllll


;
:int a; int a 888888


int a;
int a;

int a;



int a;

int ;
i
int a;
for(int i = 0; i < 0; i++){
    int a;
    :wq

}
int a;
for(int i; i < n; i++){
    int a;

}
