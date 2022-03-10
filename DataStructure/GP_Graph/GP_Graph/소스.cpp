#include <iostream>
#include<vector>

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

	cout << "=======================================" << endl;
	cout << "DFS" << endl;
	DFSMain();

	cout << "=======================================" << endl;
	cout << "BFS" << endl;
	BFSMain();
}

void DFSMain()
{
	//±íÀÌ ¿ì¼± Å½»ö

}

void BFSMain()
{
	//³Êºñ ¿ì¼± Å½»ö

}