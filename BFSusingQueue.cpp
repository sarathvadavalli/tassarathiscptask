#include <iostream>
#include <list>
using namespace std;

class Queue{
    int n,*a,front = -1,rear = -1;
    
  public:
    Queue(int k){
      n = k;
      a = new int[k];
    }
    
    void push(int k){
       if(front == -1 && rear == -1)
         front = rear = 0;
       else 
         rear++;
       
       a[rear] = k;
    }
  
    int pop(){
        int t = a[front];
        if(front < n-1)
           front++;
        else 
           front = rear = -1;
           
        return t;
    }
    
    bool isempty(){
        if(front == -1 && rear == -1)
          return true;
        else 
          return false;
    }
};
  
class Graph
{
  int V;
  list<int> *adj;

 public:
  Graph(int x)
  {
    V = x;
    adj = new list<int>[V];
  }

  void add_edge(int u,int v)
  {
    adj[u].push_back(v);
  }

  void DFS(int s)
  {
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
	   visited[i] = false;

	Queue qu(V);
	qu.push(s);
	
	while(!qu.isempty())
	{
	  int t = qu.pop();
	 
	  if(!visited[t])
	  {
	    cout<<t<<" ";
	    visited[t] = true;
	  }

	  for(auto it: adj[t])
	     if(!visited[it])
	        qu.push(it);
	}
  }
};

int main()
{
   int n,E,i,src;
   cout<<"Enter the total number of vertices and edges in graph \n";
   cin>>n>>E;
   Graph g(n);

   for (i = 0; i < E; i++)
   {
      int u, v;
      cin>>u>>v;
      g.add_edge(u,v);
   }

   cout<<"\nWhich vertex do you want as source vertex?\n";
   cin>>src;

   cout << "\nFollowing is Depth First Traversal\n";
   g.DFS(src);

   return 0;
}