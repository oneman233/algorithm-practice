class Solution {
public:
    ListNode* MergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(0);
        ListNode* p=ans;
        while(l1!=NULL&&l2!=NULL) {
			ListNode* q=new ListNode(0);
			if(l1->val>=l2->val) {
				q->val=l1->val;
				l1=l1->next;
			} else {
				q->val=l2->val;
				l2=l2->next;
			}
			p->next=q;
			p=p->next;
		}
		while(l1!=NULL) {
			ListNode* q=new ListNode(0);
			q->val=l1->val;
			l1=l1->next;
			p->next=q;
			p=p->next;
		}
		while(l2!=NULL) {
			ListNode* q=new ListNode(0);
			q->val=l2->val;
			l2=l2->next;
			p->next=q;
			p=p->next;
		}
        return ans->next;
    }
};
