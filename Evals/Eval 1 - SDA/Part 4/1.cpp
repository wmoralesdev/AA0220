
//Data structure to be used
typedef struct Node{       //we use typedef to save some space in the file
    unsigned short data;   //the integer data of a node
    struct Node* next;     //link to the next node
} Node;

//Additional structure to be used to store the control variables
//of a queue
typedef struct QueueData{
    Node *head;      //the head of the queue
    Node *tail;      //the tail of the queue
}QueueData;

//Main function to save Timmy
QueueData** Stack2Queue(Node **top){
    //We prepare the answer package
    QueueData *ans = newQueueData;
    //We prepare the queue with its control variables
    //initialized in NULL
    ans->head = NULL;
    ans->tail = NULL;
    
    //We move through the stack until it is empty
    //We don't need to avoid losing the reference and therefore we can work
    //directly on the stack because we want it destroyed in favor of the queue
    while(*top != NULL){
        //We store aside the next data in the stack
        Node *temp = *top->next;
        //The current tail of the queue must point to the current data
        //if it is not NULL
        if(ans->tail != NULL) ans->tail->next = *top;
        //The current data becomes the new tail
        ans->tail = *top;
        //When the queue is empty the current data will be its head
        if(ans->head == NULL) ans->head = *top;
        //We disconnect the current data from the stack
        ans->tail->next = NULL;
        //We update the new top for the stack
        *top = temp;
    }
    //We return the data for the queue
    return &ans;
}
