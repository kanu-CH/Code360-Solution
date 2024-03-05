/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

int getlength(Node*head,int k){
    int c=0;
    while(head!=NULL){
        c++;
        head=head->next;

    }
    return c;

}

Node* kReverse(Node* head, int k) {
    //base case
    if(head==NULL){
        return NULL;

    }

    Node*prev=NULL;
    Node*curent=head;
    Node*forward=NULL;

    int c=0;
    while(curent!=NULL && c<k){
        forward=curent->next;
        curent->next=prev;
        prev=curent;
        curent=forward;
        c++;
    }

    //
    if(forward!=NULL ){
        if(getlength(forward,k)>=k){
            head->next = kReverse(forward, k);

        }
        else{
            head->next=forward;
        }
        
    }

    return prev;
}
