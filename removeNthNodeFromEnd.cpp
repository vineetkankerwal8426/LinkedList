//Remove Nth Node From End of List
//Given the head of a linked list, remove the nth node from the end of the list and return its head.

ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode * temp = new ListNode(0);
        temp->next = head;
        ListNode * fast = temp;
        ListNode * slow = temp;
        for(int i =0;i<=n;i++){
            fast = fast->next;
        }
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return temp->next;;
    }