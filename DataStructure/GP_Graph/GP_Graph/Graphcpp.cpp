#include <iostream>
#include<vector>
#include <stack>
#include <queue>

using namespace std;

void DFSMain();
void BFSMain();

vector<int> graph[8];
enum E_gNode
{
	A = 0, B, C, D, E, F, G, H
};

void main()
{
	graph[A].push_back(B);

	graph[B].push_back(D);
	graph[B].push_back(F);

	graph[C].push_back(B);

	graph[D].push_back(H);

	graph[E].push_back(C);
	graph[E].push_back(H);

	graph[F].push_back(D);
	graph[F].push_back(G);
	graph[F].push_back(H);

	graph[G].push_back(E);
	graph[G].push_back(F);
	graph[G].push_back(H);

	for (int i = 0; i < 8; i++)
	{
		cout << i << "'s linked : ";
		for (int j = 0; j < graph[i].size(); j++)
			cout << graph[i][j] << " ";
		cout << endl;
	}

	DFSMain();
	BFSMain();
}

void DFSMain()
{
	//±íÀÌ ¿ì¼± Å½»ö
	stack<int> s;
	bool visited[8] = { false, };
	int current = A;

	cout << "DFS : ";
	while (true)
	{
		if (!visited[current])
		{
			cout << (char)(current + 97) << " ";
			visited[current] = true;
			s.push(current);
		}
		else
		{
			s.pop();
			if (s.empty())
			{
				cout << endl;
				return;
			}
			current = s.top();
		}
		int i = 0;
		int size = graph[current].size();
		for (; i < size; i++)
		{
			if (!visited[graph[current][i]])
			{
				current = graph[current][i];
				break;
			}
		}
	}
}
void BFSMain()
{
	//³Êºñ ¿ì¼± Å½»ö
	queue<int> q;
	bool visited[8] = { false, };
	int current = A;
	q.push(current);
	visited[current] = true;

	cout << "BFS : ";

	while (true)
	{
		cout << (char)(current + 97) << " ";
		int i = 0;
		int size = graph[current].size();
		for (; i < size; i++)
			if (!visited[graph[current][i]])
			{
				q.push(graph[current][i]);
				visited[graph[current][i]] = true;
			}
		q.pop();
		if (q.empty())
		{
			cout << endl;
			return;
		}
		current = q.front();
	}
}