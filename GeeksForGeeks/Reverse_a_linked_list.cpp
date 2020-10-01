//iterative
// struct Node* reverseList(struct Node *head)
// {
//     // code here
//     // return head of reversed list
//     if(!head)
//         return head;
        
//     Node* rev_head;
//     Node *prev=NULL, *cur=head, *next;
        
//     while(cur)
//     {
//         next=cur->next;
//         cur->next=prev;
//         prev=cur;
//         cur=next;
//     }
//     rev_head=prev;
// }

//recursive
// Node *rev_head;
// struct Node* revListUtil(struct Node *head)
// {
//     if(!head)
//         return NULL;
    
//     if(!head->next)
//     {
//         rev_head=head;
//         return head;
//     }
        
//     Node *temp=revListUtil(head->next);
//     temp->next=head;
//     head->next=NULL;
    
//     return head;
// }

// struct Node* reverseList(struct Node *head)
// {
//     revListUtil(head);
//     return rev_head;
// }

//hashmap
#include<bits/stdc++.h>
struct Node* reverseList(struct Node *head)
{
    if(!head)
        return NULL;
    
    unordered_map <int, Node*> m;
    int len=-1;
    while(head)
    {
        m[++len]=head;
        head=head->next;
    }
    
    Node* rev=m[len];
    while(len>0)
        m[len]->next=m[--len];
    m[len]->next=NULL;
    return rev;
}