//You are given the head of a singly linked-list. The list can be represented as:
//L0 → L1 → … → Ln - 1 → Ln

//Reorder the list to be on the following form:

//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …


void reorderList(ListNode* head) {
        ListNode * s = head;
        ListNode * f = head;
        while(f and f->next){
            s = s->next;
            f = f->next->next;
        }
        ListNode * prev = nullptr;
        ListNode * curr = s;
        ListNode * nxt = s->next;
        while(curr){        //reverse the list from its middle;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if(nxt){
                nxt = nxt->next;
            }
        }
        s = head;
        f = prev;
     
        while(s and f){   //now alternativle make list from main list and reversed list
            nxt = s->next;
            s->next = f;
            s = nxt;
            
            nxt = f->next;
            f->next = s;
            f = nxt;
        }
        if(s){
            s->next = nullptr;
        } 
    }