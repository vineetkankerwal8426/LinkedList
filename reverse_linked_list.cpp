#include<iostream>
using namespace std;

// iterative method for reversing a singly linked list

node * reverse(node * head){
    node * prev = nullptr;   // making three pointer one is prev to current node;
    node * present = head;   // second is current node;
    node * nxt = head->next;  // third is next node;
    while(present != nullptr){
        present->next = prev;    // make current node next pointer to prev node;
        prev = present;         // make prev node to current node;
        present = nxt;        // change present node to next node;
        if(nxt != nullptr){  // check the nullpointer exception;
            nxt = nxt->next;
        }
    }
    return prev;  //return the prev value beacause curr pointer in last iteration will become null;
}


// recursive method

node * reverse(node * head){   // this function will call main recursive fuction
    return reverse(head,nullptr);  //there will be only head provided to us;
}

node * reverse(node *head,node * prev){  //making main recursive fucntion
    if (head == nullptr){
        return prev;
    }
    node * nxt = head->next;
    head->next = prev;  //pointing current node next's pointer to previous one
    return reverse(nxt,head);  // calling for next node and its prev will become current- head node;
}