/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

int getLength(Node * head){
    int len=0;
    while(head != NULL){
        len++;
        head = head -> next;
    }
    return len;
}

Node *findMiddle(Node *head) {
    //approach 1
    int len = getLength(head);
    int ans = (len/2);
    Node* temp = head;
    int cnt = 0;
    while(cnt<ans){
        temp = temp-> next;
        cnt++;
    }
    return temp;

    //approach 2
    // if(head==NULL) 
    //     return  head;

    // Node* fast=head;
    // Node* slow=head;

    // while(fast!=NULL and fast->next!=NULL){
    //     fast=fast->next->next;
    //     slow=slow->next;
    // }
    // return slow;
}
