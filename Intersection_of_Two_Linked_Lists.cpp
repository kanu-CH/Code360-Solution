/****************************************************************

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

*****************************************************************/
int getLength(Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    // Get lengths of both lists
    int length1 = getLength(firstHead);
    int length2 = getLength(secondHead);
    
    // Align start pointers of both lists
    Node* head1 = firstHead;
    Node* head2 = secondHead;
    
    if (length1 > length2) {
        int diff = length1 - length2;
        for (int i = 0; i < diff; i++) {
            head1 = head1->next;
        }
    } else {
        int diff = length2 - length1;
        for (int i = 0; i < diff; i++) {
            head2 = head2->next;
        }
    }
    
    // Traverse both lists together to find the intersection point
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    // If no intersection
    return NULL;
}
