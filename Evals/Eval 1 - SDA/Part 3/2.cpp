
//Data structure to be used
typedef struct Pokemon{       //we use typedef to save some space in the file
    string name;              //the pokemon's name
    unsigned short type_qty;  //the number of types, can be 1 or 2
    struct Pokemon* next;     //link to the next pokemon
} Pokemon;

// Additional data structure to be used to provide an answer
typedef struct Pokemon_Data{
    unsigned short one_type_qty;
    unsigned short p_first_qty;
};

// Main function that helps with Pedro's OCD
// L is the pokemon list
Pokemon_Data OCDHelper(Pokemon **L){
    Pokemon_Data ans;
    // We copy the head of the list to not lose the reference
    Pokemon *temp = *L;
    // We prepare two accumulators for the two counts required
    unsigned short one_type = 0;
    unsigned short p_first = 0;
    // We loop over the pokemon list until it's empty
    while(temp != NULL){
        // If the pokemon has only one type we increse one_type
        if(temp->type_qty == 1) one_type++;
        // If the pokemon's name starts with "p" we increse p_first
        if(temp->name[0] == 'p') p_first++;
        // We move to the next pokemon
        temp = temp->next;
    }
    // We store the answer and return it
    ans.one_type_qty = one_type;
    ans.p_first_qty = p_first;
    return ans;
}
