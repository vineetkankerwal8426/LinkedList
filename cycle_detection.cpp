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
    
