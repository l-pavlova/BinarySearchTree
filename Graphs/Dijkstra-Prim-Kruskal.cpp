#include <iostream>
#include <queue>
using namespace std;
namespace dijkstra
{


#define INF 0x3f3f3f3f 
#define Element pair<int, int>


	void addEdge(vector<pair<int, int>>adj[], int u, int v, int wt)
	{
		adj[u].push_back(make_pair(v, wt));
		adj[v].push_back(make_pair(u, wt));
	}
	vector<int> Dijkstra(vector<pair<int, int>>adj[], int s, int V)
	{
		priority_queue<Element, vector<Element>, greater<Element>> pq;
		pq.push(make_pair(0, s));
		vector<int>dist(V, INF);
		dist[s] = 0;
		while (!pq.empty())
		{
			int v = pq.top().second;
			for (auto i : adj[v])
			{
				int u = (i).first;
				int weight = i.second;
				if (dist[u] > dist[v] + weight)
				{
					dist[u] = dist[v] + weight;
					pq.push(make_pair(dist[u], u));
				}
			}
			pq.pop();
		}
		return dist;
	}

	vector<int>Prim(vector<pair<int, int>>adj[], int V)
	{
		priority_queue<Element, vector<Element>, greater<Element>>pq;
		vector<int> parent(V, -1);
		vector<int>key(V, INF);
		vector<bool>MST(V, false);
		int src = 0;
		pq.push(make_pair(0, src));
		key[src] = 0;
		while (!pq.empty())
		{
			int v = pq.top().second;
			MST[v] = true;
			for (auto i : adj[v])
			{
				int u = i.first;
				int weight = i.second;
				if (!MST[u] && key[u] > weight)
				{
					key[u] = weight;
					pq.push(make_pair(key[u], u));
					parent[u] = v;
				}
			}
			pq.pop();
		}
		return parent;
	}
	struct Edge {
		int from, to, w;
		bool operator < (const Edge& other)
		{
			return w < other.w;
		}
	};
	vector<Edge> edges;
	int parent[10000], depth[10000], q[10000], used, n, m;
	bool hasBoss[100000];
	void init()
	{
		for (int i = 0; i < n; i++)
		{
			parent[i] = i;
			depth[i] = 1;
		}
	}
	int find(int v)
	{
		if (parent[v] == v)
		{
			return v;
		}
		return parent[v] = find(parent[v]);
	}
	int Union(Edge x)
	{
		int r1 = find(x.from);
		int r2 = find(x.to);
		if (r1 == r2)
		{
			return 0;
		}
		else
		{
			if (depth[r1] < depth[r2])
			{
				swap(r1, r2);
			}
			parent[r2] = r1;
			if (depth[r1] == depth[r2])
				depth[r1]++;
			used++;
			return x.w;
		}
	}
	int WeightWithKruskal(vector<Edge> edges, int n, int m)
	{
		int ans = 0;
		init();
		sort(edges.begin(), edges.end());
		for (int i = 0; i < edges.size(); i++)
		{
			ans += Union(edges[i]);
		}
		if (used == n - 1)
		{
			return ans;
		}
		else
		{
			return -1;
		}
	}
	
	int main()
	{
		vector<Element> graph[20];
		addEdge(graph, 0, 1, 4);
		addEdge(graph, 0, 7, 8);
		addEdge(graph, 1, 2, 8);
		addEdge(graph, 1, 7, 11);
		addEdge(graph, 2, 3, 7);
		addEdge(graph, 2, 8, 2);
		addEdge(graph, 2, 5, 4);
		addEdge(graph, 3, 4, 9);
		addEdge(graph, 3, 5, 14);
		addEdge(graph, 4, 5, 10);
		addEdge(graph, 5, 6, 2);
		addEdge(graph, 6, 7, 1);
		addEdge(graph, 6, 8, 6);
		addEdge(graph, 7, 8, 7);

		/*auto res = Prim(graph, 100);
		for (auto i : res)
		{
			cout << i << " ";
		}*/
		vector<Edge>edges;
		int ans = 0;

		edges.push_back({ 0, 1, 2 });
		edges.push_back({ 1, 2, 1 });
		edges.push_back({ 0, 1, 3 });
		edges.push_back({ 0, 4, 1 });
		edges.push_back({ 0, 3, 1 });
		edges.push_back({ 0, 5, 1 });

		cout << WeightWithKruskal(edges, 6, 6);

		cin.get();
		return 0;
	}
}
