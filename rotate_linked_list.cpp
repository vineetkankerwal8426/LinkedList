//Given the head of a linked list, rotate the list to the right by k places.

//Input: head = [1,2,3,4,5], k = 2  ,, Output: [4,5,1,2,3]



ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k <=0){
            return head;
        }
        ListNode * last = head;
        int l = 1;
        while(last->next){     //find the number of nodes in list and point last pointer to the tail;
            last = last->next;
            l++;
        }
        last->next = head;
        ListNode * newLast = head;
        for(int i =0;i<l-(k%l)-1;i++){   // number of rotations will be k%length;
            newLast = newLast->next;
        }
        head = newLast->next ;
        newLast->next = nullptr;
        return head;
    }