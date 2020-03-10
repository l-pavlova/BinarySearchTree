#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void addEdge(vector<int>* adj, int u, int v)
{
	adj[u].push_back(v);
}
bool DFSUtil(vector<int>* adj, int u, int color[])
{
	color[u] = 1;
	for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i;
		if (color[v] == 1)
			return true;
		if (color[v] == 0 && DFSUtil(adj, v, color))
			return true;
	}
	color[u] = 2;
	return false;
}
void Test()
{
	vector<int>graph[1000000];
	int V, E;
	cin >> V >> E;
	for (int j = 0; j < E; j++) {
		int xi, yi, wi;
		cin >> xi >> yi >> wi;
		addEdge(graph, xi - 1, yi - 1);
	}
	int* visited = new int[V];
	for (int p = 0; p < V; p++)
	{
		visited[p] = 0;
	}
	for (int q = 0; q < V; q++)
	{
		if (visited[q] == 0) {
			if (DFSUtil(graph, q, visited) == true)
			{
				cout << "true ";
				return;
			}
		}
	}
	cout << "false ";
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Test();
	}
	return 0;
}
