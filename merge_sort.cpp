#include<iostream>
using namespace std;


node* merge(node* head1,node* head2){  //funtion for merge two sorted list;
        node * ans = new node();
        node * temp = ans;
        while(head1 and head2){
            if(head1->value < head2->value){
                temp->next = head1;
                temp = temp->next;
                head1= head1->next;
            }
            else{
                temp->next = head2;
                temp = temp->next;
                head2= head2->next;
            }
        }
        while(head1){
            temp->next = head1;
            head1 = head1->next;
            temp = temp->next;
        }
        while(head2){
            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;
        }
        return ans->next;  //we have to return ans->next because value of ans->value = null/0 ;
    }
    node* sortList(node* head) {
        if(head == nullptr or head->next == nullptr){  //base condition;
            return head;
        }
        node * f = head;
        node * s = head;
        while(f->next and f->next->next){  //finding middle of the linked list using fast and slow pointer;
            f= f->next->next;
            s = s->next;
        }
        node * mid = s->next;
        s->next = nullptr;  //we have to make middle->next == null so that it will break into two list;
        node * left = sortList(head);
        node * right = sortList(mid);
        return merge(left,right);
    }