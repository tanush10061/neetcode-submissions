/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* temp3=new ListNode();
        ListNode* head=temp3;
        while(temp1!=NULL&&temp2!=NULL){
            if(temp1->val<temp2->val){
                ListNode* temp=new ListNode(temp1->val);
                temp3->next=temp;
                temp1=temp1->next;
                temp3=temp3->next;
            }
            else if(temp2->val<temp1->val){
                ListNode* temp=new ListNode(temp2->val);
                temp3->next=temp;
                temp2=temp2->next;
                temp3=temp3->next;
            }
            else{
                ListNode* temp31=new ListNode(temp1->val);
                temp3->next=temp31;
                ListNode* temp32=new ListNode(temp1->val);
                temp31->next=temp32;
                temp1=temp1->next;
                temp2=temp2->next;
                temp3=temp3->next;
                temp3=temp3->next;
            }
        }
        while(temp1!=NULL){
            temp3->next=temp1;
            temp1=temp1->next;
            temp3=temp3->next;
        }
        while(temp2!=NULL){
            temp3->next=temp2;
            temp2=temp2->next;
            temp3=temp3->next;
        }
        return head->next;
    }
};
