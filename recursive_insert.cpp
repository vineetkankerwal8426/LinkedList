#include <iostream>
using namespace std;

// it will insert a node in a linked list using recursive approach
node* insertRec(int value,int index, node *nod){
    if(index ==0){ //when index will be 0 then it will add new node 
        node * newNode = new node(value);
        newNode->next = nod; // make new node next to perticular *this* node;
        size++;
        return newNode; //when new node will be inserted then it will return that perticular  new node;
    }
    nod->next = insertRec(value,index-1,nod->next); 
    return nod; 
}

//it will be the function that will call insertRec function
void insertR(int value,int index){
    head = insertRec(value,index,head); // insertRec will return to head, so that head should be updated;
}