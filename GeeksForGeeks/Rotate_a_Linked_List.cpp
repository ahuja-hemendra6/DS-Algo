Node* rotate(Node* head, int k)
{
    // Your code here
    int count=1;
    Node *newHead, *oldHead=head;
    while(count!=k)
    {
        head=head->next;
        count++;
    }
    newHead=head->next;
    if(!newHead)
        return oldHead;
    head->next=NULL;
    
    head=newHead;
    while(head->next)
        head=head->next;
    head->next=oldHead;
    
    return newHead;
}