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

//approach 1
/*
Node* sortList(Node *head){
    int zeroCnt = 0;
    int oneCnt = 0;
    int twoCnt = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == 0){
            zeroCnt++;
        }
        else if(temp -> data == 1){
            oneCnt++;
        } 
        else{
            twoCnt++;
        }
        temp = temp -> next;
    }
    temp = head;
    while(temp != NULL){
        while(zeroCnt--){
            temp -> data = 0;
            temp = temp -> next;
        }
        while(oneCnt--){
            temp -> data = 1;
            temp = temp -> next;
        }
        while(twoCnt--){
            temp -> data = 2;
            temp = temp -> next;
        }
    }
    return head;
}
*/

//approach 2
void insertAtTail(Node* &tail, Node* curr ) {
    tail -> next = curr;
    tail = curr;
}

Node* sortList(Node *head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    // create separate list 0s, 1s and 2s
    while(curr != NULL) {
        
        int value = curr -> data;
        
        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }       
        curr = curr -> next;
    }
    
    //merge 3 sublist
    
    // 1s list not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else {
        //1s list -> empty
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
	//setup head 
    head = zeroHead -> next;
    
    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}
