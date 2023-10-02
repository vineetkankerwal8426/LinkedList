#include<iostream>
using namespace std;

//cycle in a linked list means next of tail is not null by pointing to someone in the linked list making it cycle
//fast and slow pointer approach for cycle detecting in linked list;

bool cycle(LinkedList * head){
    LinkedList * slow = head;
    LinkedList * fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}


//detect at which node, tail is pointing and making it cycle

 ListNode *detectCycle(ListNode *head) {
        if( head == nullptr or !head->next){
            return NULL;  //if their is only one or no node and it is not making cycle it will return null;
        }
        ListNode * f = head;
        ListNode *s = head;
        int length=0;
        while(f!=nullptr and f->next){  //first we will find length of the cycle;
            f = f->next->next;
            s = s->next;
            if(s == f){ //if therir is length then stop fast pointer and run slow->next and l+=1;
                s=s->next;
                length+=1;
                while(s!=f){
                    length+=1;
                    s=s->next;
                }
                break;
            }
        }
        if(length==0){  //if length of the cycle is 0 , then their is no cycle thus return null;
            return NULL;
        }
        f = head;  //make two pointer first and second
        s = head;
        for(int i =0;i<length;i++){ //make second pointer ahead of length of the cycle;
            s= s->next;
        }
        while(s!=f){    //then run both pointer one by one ;
            f=f->next;  //where they both will met, that will be the node from where the cycle is starting, tail is pointing ;
            s=s->next;
        }
        return s;  //return the node from where cycle is starting ;
    }
    
