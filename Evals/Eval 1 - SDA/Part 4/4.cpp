
//Data structure to be used
typedef struct Ball{       //we use typedef to save some space in the file
    unsigned short color;    //the urgency of the program
    struct Ball* next;     //link to the next program
}Ball;

//Main function to fix the exhibition
void saveTheMuseum(Ball **top){
    //We see the bag as a stack, and we prepare a second one
    Ball *top2 = NULL;
    //We go through the original stack, storing non-red balls in the new one
    while(*top != NULL){
        if(*top->color != RED){
            //If the top ball isn't red, we store the next ball in the original
            //stack
            Ball *temp = *top->next;
            //We redirect the current ball towards the top of the new stack
            *top->next = top2;
            //We update the new top of the new stack
            top2 = *top;
            //We update the new top of the original stack
            *top = temp;
        }else{
            //If the current ball is red, we just take it out of the original
            //stack and destroy it
            Ball *rball = *top;
            *top = *top->next;
            delete rball;
        }
    }
    //Now, we put back the balls in the original stack in the order they were
    //there, except the red ones of course
    while(top2 != NULL){
        //We store the next ball in the new stack
        Ball *temp = top2->next;
        //We redirect the current ball towards the top of the original stack
        top2->next = *top;
        //We update the new top of the original stack
        *top = top2;
        //We update the new top of the new stack
        top2 = temp;
    }
}
