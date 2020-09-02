
//Data structure to be used
typedef struct Person{       //we use typedef to save some space in the file
    float distance;          //the distance of the person when it arrives
    float temperature;       //the temperature of the person
    float ticket = -1;      //the fee that must be paid. -1 means there is no payment
    struct Person* next;     //link to the next person
}Person;

//Additional structure to control the queue
typedef struct Queue{
    Person* head;           //the head of the queue
    Person* tail;           //the tail of the queue
}Queue;

//Function that represents when a new person arrives
void ArriveAtPark(Queue** Q){
    //A new person is created
    Person* p = new Person;
    //We assume we have a function to generate random float numbers between two
    //given values. We also assume we have some defined constantes to determine
    //the limits for these values
    p->distance = random(MIN_DIST, MAX_DIST);  //random distance
    p->temperature = random(MIN_T, MAX_T);    //random temperature
    p->next=NULL;
    //We add the new person to the queue
    *Q->tail->next = p;
    *Q->tail = p;
}

//Function that represents when a person's turn arrives
void turn(Queue** Q){
    //We take the person out of the queue
    Person* p = *Q->head;
    *Q->head = *Q->head->next;
    //We check whether the person can enter the park or not
    //If the person can't enter, we generate a random fee value
    if(p->temperature >= 40.0 || p->distance <= 2.0) p->ticket = random(MIN_FEE, MAX_FEE);
    else cout << "Enter please.\n";
}

//Function that control the overall process
void helpPolice(Queue** Q){
    //We work while there are people on the queue
    while(*Q->head != NULL){
        //We simulate a random chance of a new person arriving
        float chance = random(0,100);
        if(chance >=25 && chance <=55) ArriveAtPark(Q);
        //We check one person
        turn();
    }
}
