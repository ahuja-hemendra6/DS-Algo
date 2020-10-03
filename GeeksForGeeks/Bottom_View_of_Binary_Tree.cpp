vector <int> bottomView(Node *root)
{
    // Your Code Here
    map<int, int> m;
   
    queue<pair<Node*,int>> q;
    q.push(make_pair(root, 0));
   
    while(!q.empty())
    {
        Node* temp=q.front().first;
        int bal=q.front().second;
        q.pop();
        m[bal]=temp->data;
        
        if(temp->left)
            q.push(make_pair(temp->left, bal-1));
            
        if(temp->right)
            q.push(make_pair(temp->right, bal+1));
    }
   
    map<int,int>::iterator it;
    vector<int> v;
    for (it=m.begin(); it!=m.end(); it++)
        v.push_back(it->second);
    return v;
}