// Given the head of a singly linked list and two integers left and right where left <= right,
// reverse the nodes of the list from position left to position right, and return the reversed list.
//example {1->2->3->4->5} left =1, right = 4 ,, ans = {1->4->3->2->5}

ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right){
            return head;
        }
        ListNode * prev = nullptr;
        ListNode * curr = head;
        for(int i =1 ;curr!=nullptr && i<left ; i++){
            prev = curr;
            curr = curr->next;
        }
        ListNode * nxt = curr->next;
        ListNode * newEnd = curr;
        ListNode * last = prev;
        for(int i =left; i<= right; i++){ //simply reversing nodes;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if(nxt!= nullptr){
                nxt = nxt->next;
            }
        }
        if (last != nullptr){  //if last != nullptr it means some node are not reversed in linked list so we have to link them with
            last->next = prev;  // last reversed node;
        }else{
            head = prev;    // if last node is nullptr it means linked list is reversed with head, so we have to make last reversed node head;
        }
        newEnd->next = curr;   // make first reversed node->next to the node which is not reversed
        return head;    //return head;
    }