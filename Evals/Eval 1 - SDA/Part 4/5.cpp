
//Data structure to be used
typedef struct Form{       //we use typedef to save some space in the file
    bool signed = false;    //the signature status of the form
    struct Form* next;     //link to the next form
}Form;

//Main function to do your CEO work
Form** paperwork(Form **top){
    //We see the forms as a stack, and we prepare a second one
    Form *top2 = NULL;
    //We go through the original stack, signing the forms and storing them
    //in the new one
    while(*top != NULL){
        //We store the next form in the original stack
        Form *temp = *top->next;
        //We redirect the current form towards the top of the new stack
        //after signing it
        *top->signed = true;
        *top->next = top2;
        //We update the new top of the new stack
        top2 = *top;
        //We update the new top of the original stack
        *top = temp;
    }
    //We return the new stack of signed forms
    return &top2;
}
