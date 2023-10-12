//Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
// example = {1->2->2->1} true ,,, {1->2} false;;
 

//approach == we have to give algo that take O(n) time and O(1) space 
//first we find the middle for the linked list with help of two pointers fast and slow, then we reverse the linked list from the middle node 
// then we check nodes from head and middle because if list is palindrom then it will same if we reverse it from middle {1,2,2,1}= {1,2}{1,2}

bool isPalindrome(ListNode* head) {
        if(head==nullptr or head->next==nullptr){
            return true;
        }
        ListNode * s = head;
        ListNode * f =head;
        while(f and f->next){
            s = s->next;
            f = f->next->next;
        }
        ListNode * prev = nullptr;
        ListNode * curr = s;
        ListNode * nxt = curr->next;
        while(curr){
            curr->next = prev;
            prev = curr;
            curr=nxt;
            if(nxt){
                nxt=nxt->next;
            }
        }
        s = prev;
        f = head;
        while(s and f){
            if(f->val!=s->val) return false;
            f = f->next;
            s = s->next;
        }
        return true;
    }