
//Data structure to be used
typedef struct Song{    //we use typedef to save some space in the file
    string name;        //song name
    struct Song* next;  //link to the next song
} Song;

//Main function that solves Walter's problem
//L is the song list
void replaceProblematicSongs(Song **L){
    //We copy the head of the list to not lose the reference
    Song *temp = *L;
    //This counter is used to place generic love song names
    unsigned short cont = 1;
    //We loope over the song list until it's empty
    while(temp != NULL){
        //If the name contains the word "virus" we have work to do
        if(temp->name.find("virus") != string::npos){
            //We replace the name with a generic love song name
            temp->name = "Love Song " + to_string(cont++);
        }
        //We move to the next song
        temp = temp->next;
    }
}
