#include <iostream>
#include <list>
using namespace std;

class Stack
{
   int v,*arr,top = -1;

  public:
   Stack(int n){
      v = n;
      arr = new int[v];
   }

   void push(int k)
   {
      top++;
      arr[top] = k;
   }

   int pop()
   {
      int p = arr[top];
      top--;
      return p;
   }

   bool isempty(){
      if(top == -1)
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

	Stack st(V);
	st.push(s);

	while(!st.isempty())
	{
	  int t = st.pop();

	  if(!visited[t])
	  {
	    cout<<t<<" ";
	    visited[t] = true;
	  }

	  list<int>::iterator it;
	  for(it = adj[t].begin(); it != adj[t].end(); ++it)
	     if(!visited[*it])
	        st.push(*it);
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
