//KRUSKAL
// int find_parent (int parent[], int u)
// {
//     int temp=u;
//     // if(u!=parent[u])
//     //     parent[u]=find_parent(parent, parent[u]);
//     // return parent[u];
//     while(u!=parent[u])
//         u=parent[u];
    
//     parent[temp]=u;
//     return u;
// }

// void merge (int px, int py, int rank[], int parent[])
// {
//     // int px=find_parent(parent, x), py=find_parent(parent, y);
    
//     if(rank[px]>rank[py])
//         parent[py]=px;
//     else
//         parent[px]=py;
    
//     if(rank[px]==rank[py])
//         rank[py]++;
// }

// int spanningTree(int V, int E, vector<vector<int>> &graph) {
//     // code here
//     vector<pair<int, pair<int,int>>> v;
    
//     for (int i=0; i<V; i++)
//     {
//         for (int j=0; j<V; j++)
//         {
//             if(graph[i][j]!=INT_MAX)
//                 v.push_back(make_pair(graph[i][j], make_pair(i,j)));
//         }
//     }
//     sort(v.begin(), v.end());
//     int count=0;
//     int parent[V], rank[V];
//     for (int i=0; i<V; i++)
//     {
//         parent[i]=i;
//         rank[i]=0;
//     }
    
//     int sum=0;  
//     vector<pair<int, pair<int,int>>>::iterator it;
//     for (it=v.begin(); it!=v.end(); it++)
//     {
//         int u=it->second.first;
//         int v=it->second.second;
        
//         int par_u=find_parent(parent, u);
//         int par_v=find_parent(parent, v);
        
//         if(par_u!=par_v)
//         {
//             sum+=graph[u][v];
//             merge(par_u,par_v,rank,parent);
//             count++;
//         }
//         if(count==V-1)
//             break;
//     }
//     // cout<<count<<endl;
//     return sum;
// }


//PRIM'S
int find_min(int key[], bool mst[], int V)
{
    int min=INT_MAX, min_ind;
    for (int i=0; i<V; i++)
        if(mst[i]==false && key[i]<min)
        {
            min=key[i];
            min_ind=i;
        }
    return min_ind;
}

int spanningTree(int V, int E, vector<vector<int>> &graph)
{
    int key[V];
    bool mst[V];
    int sum=0;
    
    for (int i=0; i<V; i++)
    {
        key[i]=INT_MAX;
        mst[i]=false;
    }
    
    key[0]=0;
    for (int count=0; count<V-1; count++)
    {
        int vertex=find_min(key, mst, V);
        
        mst[vertex]=true;
        
        sum+=key[vertex];
        // cout<<sum<<" ";
        
        for (int i=0; i<V; i++)
            if(graph[vertex][i]!=INT_MAX && !mst[i] && graph[vertex][i]<key[i])
            {
                key[i]=graph[vertex][i];
            }
    }
    int last_v=find_min(key, mst, V);
    return sum+key[last_v];
}