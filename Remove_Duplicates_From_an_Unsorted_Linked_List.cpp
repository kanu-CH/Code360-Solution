#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{
    if(head==NULL){
        return NULL;
    }
    
    unordered_map<int, bool> m;
    
    Node* curr=head;
    Node* prev=NULL;
    
    while(curr!=NULL){
        
        if(m[curr->data]==true){
            Node* nxt= curr->next;
            Node* NodeToDel = prev->next;
            
            delete(NodeToDel);
            prev->next=nxt;
        }
        
        else
        {
            m[curr->data]=true;
            prev=curr;
     
        }
           curr=curr->next;
    }
    
    return head;
}
