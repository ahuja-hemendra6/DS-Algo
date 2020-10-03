//1st way
// void deleteNode(Node *node)
// {
//     // Your code here
//     *node=*(node->next);
// }

//2nd way
void deleteNode(Node *node)
{
    // Your code here
    Node* temp = node->next;
    if(!temp)
        node=NULL;
    else
    {
        node->data=temp->data;
        node->next=temp->next;
    }
    free(temp);
}