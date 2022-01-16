#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    int V, s;
    list<int> *arr;
    list<int> queue;
    bool *visited;

    graph(int v)
    {
        this->V = v;
        arr = new list<int>[v];
        visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
        }
    }
    void addEdge(int x, int y)
    {
        arr[x].push_back(y);
    }
    void DisplayGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Adjacency List of vartex " << i << " : ";
            for (auto it : arr[i])
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }
    void BFS(int s)
    {
        visited[s] = 1;
        queue.push_back(s);
        while (!queue.empty())
        {
            s = queue.front();
            cout << s << " ";
            queue.pop_front();
            list<int> :: iterator i;
            for (i = arr[s].begin(); i != arr[s].end(); i++)
            {
                if (!visited[*i])
                {
                    visited[*i] = 1;
                    queue.push_back(*i);
                }
            }
        }
    }

};
int main()
{
    graph g(4);
    int s, e, v, p, q;
    int choose;
    cout << "Enter number of vertex: " << endl;
    cin >> v;
    cout << "Enter number of edges: " << endl;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> p >> q;
        g.addEdge(p, q);
    }
    g.DisplayGraph();
    cout<<"Enter the starting vertex: ";
    cin>>s;
    g.BFS(s);
    return 0;
}