#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int>* adj, int u, int v)
{
	adj[u].push_back(v);
}
void dfs(vector<int>* adj, int s,  int v, bool*visited)
{
	visited[s] = true;
	
	for (auto i : adj[s])
	{
		cout << i<< " ";
		if (!visited[i])
		{
			dfs(adj, i, v, visited);
		}
	}
}

void bfs(vector<int>* adj, int s, int V)
{
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	queue<int>q;
	visited[s] = true;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		cout << u << " ";
		for (int el : adj[u])
		{
			if (!visited[el])
			{
				visited[el]=true;
				q.push(el);
			}
		}
	}
}

int main()
{

	

	cin.get();
	return 0;
}