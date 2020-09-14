
//Data structure to be used
typedef struct Player{       //we use typedef to save some space in the file
    unsigned short points;   //the number of points the player has earned
    struct Player* next;     //link to the next player
} Player;

//Auxiliar function to calculate the length of a player list
unsigned short length(Player **L){
    //We copy the head to avoid losing the reference
    Player *temp = *L;
    //We initialize a counter
    unsigned short cont = 0;
    //While the list isn't empty, we add 1 to the counter and move to the next
    //player
    while(temp !=NULL){
        temp = temp->next;
        cont++;
    }
    //We return the total amount of players
    return cont;
}
//Main function that helps Marissa with her career
//L is the list of players she will play against
void trainFirst(Player **L){
    //We calculate the numbers of players
    unsigned short depth = length(L);
    //We need at least for players to be able to move one of them three spaces
    //down on the list, otherwise we have nothing we can do
    if(depth < 4) return;

    //We copy the head of the list to not lose the reference
    //We also prepare a dad, initialized in NULL since the head doesn't have a dad
    Player* temp = *L;
    Player* dad = NULL;
    
    //We do the process while it is possible to move forward three spaces, which means,
    //while it is possible to move 3 spaces down on the list
    while(depth >= 4){
        //We check if the player has 20 points or more, which is to say, whether
        //or not the player is a top player
        if(temp->points >= 20){
            //We keep apart a pointer to the next player after the current one
            Player *cpy = temp->next;
            //We say that the next player after the current one is located 4
            //spaces down
            temp->next = cpy->next->next->next;
            //We now say that the current player will be 3 spaces after the one
            //that was previously after it
            cpy->next->next = temp;
            //Now we check the dad, if it exists, now its successor must be
            //the one previously after his next player
            //If it doesn't exists, it means that what we have in cpy is now
            //the head of the list, so we maintain the dad in NULL
            if(dad != NULL) dad->next = cpy;
            //Whatever the case with the dad, the next player to be evaluated is
            //what we have in cpy
            temp = cpy;
            //We don't alter depth since it has not changed
        }else{
            //In this case, we don't need to change anything
            //We just move the dad to the current player, and the latter to its
            //successor
            dad = temp;
            temp = temp->next;
            //In this case, we have to decrease the depth by one due to the
            //advancement forward
            depth--;
        }
    }
}
