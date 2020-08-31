void printStk(node *stk){
    if(stk){
        cout << stk->data << " ";
        printStk(stk->next);
    }
}