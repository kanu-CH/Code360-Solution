#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
   if(first == NULL && second == NULL){
        return NULL ;
    }
    else if(first == NULL){
        return second ;
    }
    else if (second == NULL) {
        return first;
    }

    Node<int>* temp = first ;
    if(first->data > second->data){
        first = second ;
        second = temp ;
    }
    
    Node<int>* prev = first ;
    Node<int>* curr = first->next ;

    while(second != NULL && curr != NULL){
        if(second->data >= prev->data && second->data <= curr->data){
            prev->next = second ;
            second = second->next ;
            prev->next->next = curr ;
            prev = prev->next ;
        }
        else{
            prev = curr ;
            curr = curr->next ;
        }
    }
    if(second != NULL){
        prev->next = second ;
    }
    return first ;
}
