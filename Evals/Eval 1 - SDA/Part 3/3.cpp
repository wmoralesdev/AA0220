
//Data structure to be used
typedef struct Act{            //we use typedef to save some space in the file
    unsigned short puppet_qty; //the number of puppets used in the act
    struct Act* next;          //link to the next act
} Act;

//Main function that helps Xiomara put her feet on the ground
//L is the act list
void PuppetShow(Act **L){
    //We copy the head of the list to not lose the reference
    Act *temp = *L;
    //If the list is empty, there's nothing to do
    if(temp == NULL) return;
    //There is at least one node, we move forward one space
    //A dad appears, for the new node in evaluation
    Act *dad = temp;
    temp = temp->next;
    //If only the dad is there, there's nothing to do
    if(temp == NULL) return;    
    //There are at least two nodes, we move forward another space
    //A grandparent appears, for the new node in evaluation
    Act *grandpa = dad;
    dad = dad->next;
    temp = temp->next;
    //If there are only two nodes, we can't move two spaces up, so we go back
    if(temp == NULL) return;
    //There are at least three nodes, we move forward another space
    //A greatgrandparent appears, for the new node in evaluation
    Act* ggrandpa = grandpa;
    grandpa = grandpa->next;
    dad = dad->next;
    temp = temp->next;
    //Since we have at least three nodes, and we are currently positioned
    //on the fourth one (that could be NULL), now it has become possible
    //to move two spaces up, so...
    //We loop over the act list until we reach its end
    while(temp != NULL){
        //What we do depends on the number of puppets for the act
        if(temp->puppet_qty == 1){
            //If the act has only 1 puppet, it moves two spaces up
            //The dad moves forward one space (grandpa moves along with it)
            dad->next = temp->next;
            //The current node is placed before its grandparent
            temp->next = grandpa;
            //The greatgrandparent points towards its new successor
            ggrandpa->next = temp;

            //We update the new greatgrandparent
            ggrandpa = temp;
            //We set the new node to be evaluated, the new child for dad
            temp = dad->next;
        }else{
            //If the act has more than one puppet, nothing needs to move
            //So we place our pointers one space forward to continue the evaluation
            ggrandpa = grandpa;
            grandpa = dad;
            dad = temp;
            temp = temp->next;
        }
    }
}
