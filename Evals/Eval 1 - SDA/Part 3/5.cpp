
//Data structure to be used
typedef struct Node{       //we use typedef to save some space in the file
    unsigned short data;   //the integer data of a node
    struct Node* next;     //link to the next node
} Node;

//Main function to save Charlie
Node* Best2Worst(Node **L){
    //We copy the head to not lose the reference
    Node *temp = *L;
    //We prepare a new list
    Node *newL = NULL;
    //We loop over the input until it is empty
    while(temp != NULL){
        //We prepare a new node for the new list
        Node *node = new Node;
        
        //The new node for the new list must contain the current data in the
        //original one
        node->data = temp->data;
        //The new node must be inserted at the beginning of the new list
        //in order to generate the reverse order
        //If the new list is empty, then the new node is its head,
        //otherwise, the new node points to the current head and then 
        //becomes the new head
        if(newL != NULL) node->next = newL;
        newL = node;
        
        //We move forward one space in the original list
        temp = temp->next;
    }
    //We return the new list which is in the opposite order
    return newL;
}
