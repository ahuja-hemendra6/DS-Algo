//https://practice.geeksforgeeks.org/problems/alien-dictionary/1

int graph[26][26];
string ans="";

void dfs (int K, int vis[], int v, stack <int> &s)
{
    if(vis[v])
        return;
    
    vis[v]=1;
    
    for (int i=0; i<K; i++)
    {
        if(graph[v][i])
            dfs(K, vis, i, s);
    }
    s.push(v);
}

void topoSort(int K)
{
    int vis[K]={};
    stack<int> s;
    
    for (int i=0; i<K; i++)
        if(!vis[i])
            dfs(K, vis, i, s);
            
    while(!s.empty())
    {
        char c=s.top()+'a';
        ans.push_back(c);
        s.pop();
    }
}

string findOrder(string dict[], int N, int K) {
    // Your code here
    string s1, s2;
    // int len=sizeof(dict)/sizeof(dict[0]);
    for (int i=0; i<K; i++)
        for (int j=0; j<K; j++)
            graph[i][j]=0;
            
    ans="";
    for (int i=1; i<N; i++)
    {
        s1=dict[i-1];
        s2=dict[i];
        
        for (int j=0; j<s1.length() && j<s2.length(); j++)
        {
            if(s1[j]!=s2[j])
            {
                graph[s1[j]-'a'][s2[j]-'a']=1;
                break;
            }
        }
    }
        
    topoSort(K);
    return ans;
}