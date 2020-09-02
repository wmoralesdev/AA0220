
//Data structure to be used
typedef struct Program{       //we use typedef to save some space in the file
    unsigned short urgency;    //the urgency of the program
    struct Program* next;     //link to the next program
}Program;

//Additional structure to control the queue
typedef struct Queue{
    Program* head;           //the head of the queue
    Program* tail;           //the tail of the queue
}Queue;

//Function that patches TempleOS
void helpTerry(Queue** Q){
    //We copy the head to not lose the reference
    Program *temp = *Q->head;
    //We prepare a counter initialized in 0
    unsigned short cont = 0;
    //While the queue isn't empty we keep checking
    while(temp !=NULL){
        //If the current program is urgent beyond a certain limit, we increase
        //the counter by 1. We assume we have defined a constant for this
        //limit value
        if(temp->urgency > LIMIT_URGENCY) cont++;
        //We move to the next program
        temp = temp->next;
    }
    //We check whether we have more than 10 urgent programs or not
    if(cont > 10) cout << "CRISIS!!!!!!!!!!!!!\n";
}
