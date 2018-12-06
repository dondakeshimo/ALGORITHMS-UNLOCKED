#include <cstdio>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <limits>
using namespace std;


vector<int> Topological_Sort(vector<vector<int>>& G);
void Relax(vector<int>& shortest, vector<int>& pred,
           vector<vector<int>>& weight, int u, int v);
vector<int> Dag_Shortest_Paths(vector<vector<int>>& G,
                               vector<vector<int>>& weight, int n, int s);


int main()
{
    int n = 14;
    vector<vector<int>> G{
        { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    };
    vector<int> answer;

    cout << "-------------" << endl;
    cout << "Topological sort" << endl;
    cout << "-------------" << endl;

    answer = Topological_Sort(G);
    for (int i = 0; i < n; i++) {
        cout << answer[i] << endl;
    }
}


vector<int> Topological_Sort(vector<vector<int>>& G)
{
    vector<int> in_degree(G.size(), 0);
    vector<int> next;
    vector<int> linear_order;

    for (int u = 0; u < G.size(); u++) {
        for (int v = 0; v < G.size(); v++) {
            if (G[u][v] == 1) in_degree[v]++;
        }
    }

    for (int u = 0; u < G.size(); u++) {
        if (in_degree[u] == 0) next.push_back(u);
    }

    int u;
    while (!next.empty()) {
        u = next.back();
        next.pop_back();
        linear_order.push_back(u);

        for (int v = 0; v < G.size(); v++) {
            if (G[u][v] == 1) {
                in_degree[v]--;
                if (in_degree[v] == 0) next.push_back(v);
            }
        }
    }

    // this process is to linear order same as book number
    for (int i = 0; i < G.size(); i++) {
        linear_order[i]++;
    }

    return linear_order;
}


void Relax(vector<int>& shortest, vector<int>& pred,
           vector<vector<int>>& weight, int u, int v)
{
    if (shortest[u] + weight[u][v] < shortest[v]) {
        shortest[v] = shortest[u] + weight[u][v];
        pred[v] = u;
    }
}


vector<int> Dag_Shortest_Paths(vector<vector<int>>& G,
                               vector<vector<int>>& weight, int n, int s)
{
    vector<int> l = Topological_Sort(G);
    vector<int> shortest(n, numeric_limits<int>::max());
    vector<int> pred(n, numeric_limits<int>::max());

    shortest[s] = 0;

    int u;
    for (int i = 0; i < l.size(); i++) {
        u = l[i];
        for (int v = 0; v < n; v++) {
            if (G[u][v] == 1) Relax(shortest, pred, weight, u, v);
        }
    }
}
