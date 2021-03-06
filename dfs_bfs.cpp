#include<bits/stdc++.h>
using namespace std;

vector<int> v[100001];
int visited[100001]={0};

void dfs(int start)
{
  cout<<start<<" ";
  visited[start]=1;
  for(int i=0;i<v[start].size();i++)
  {
    if(!visited[v[start][i]])
    {
      dfs(v[start][i]);
    }
  }
}

void bfs(int start)
{
  int current;
  queue<int> q;
  q.push(start);
  while(q.size()!=0)
  {
    current = q.front();
    q.pop();
    if(!visited[current])
    {
      cout<<current<<" ";
      visited[current]=1;
    }
    for(int i=0;i<v[current].size();i++)
    {
      if(!visited[v[current][i]])
      {
        cout<<v[current][i]<<" ";
        visited[v[current][i]]=1;
        q.push(v[current][i]);
      }
    }
  }
}

int main()
{
  int n,i,j,k,node,start;
  cout<<"Enter no of nodes in a graph";
  cin>>n;
  for(i=1;i<=n;i++)
  {
    cout<<"Enter no of adjacent nodes"<<endl;
    cin>>k;
    cout<<"Enter the adjacent nodes"<<endl;
    for(j=0;j<k;j++)
    {
      cin>>node;
      v[i].push_back(node);
    }
  }
  cout<<"Enter the starting node:";
  cin>>start;
  cout<<"DFS Traversal:"<<endl;
  dfs(start);
  cout<<endl;
  /* making all elements of visited array 0 */
  for(i=0;i<100001;i++)
    visited[i]=0;
  cout<<"BFS Traversal:"<<endl;
  bfs(start);
  cout<<endl;
  return 0;
}

//OUTPUT

/*

Enter no of nodes in a graph 5
Enter no of adjacent nodes
 3
Enter the adjacent nodes
 2
 3
 5
Enter no of adjacent nodes
 3
Enter the adjacent nodes
 1
 4
 5
Enter no of adjacent nodes
 1
Enter the adjacent nodes
 1
Enter no of adjacent nodes
 1
Enter the adjacent nodes
 2
Enter no of adjacent nodes
 2
Enter the adjacent nodes
 1
 2
Enter the starting node: 1
DFS Traversal:
1 2 4 5 3 
BFS Traversal:
1 2 3 5 4 

*/
