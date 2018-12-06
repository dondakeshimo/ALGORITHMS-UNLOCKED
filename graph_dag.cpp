#include <cstdio>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <limits>
using namespace std;


vector<int> Topological_Sort(vector<vector<int>>& G, int n);
void Rerax(vector<int>& shortest, vector<int>& pred,
           vector<vector<int>>& weight, int u, int v);
vector<int> Dag_Shortest_Paths(vector<vector<int>>& G, int n, int s);


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

    answer = Topological_Sort(G, n);
    for (int i = 0; i < n; i++) {
        cout << answer[i] << endl;
    }
}


vector<int> Topological_Sort(vector<vector<int>>& G, int n)
{
    vector<int> in_degree(n, 0);
    vector<int> next;
    vector<int> linear_order;

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (G[u][v] == 1) in_degree[v]++;
        }
    }

    for (int u = 0; u < n; u++) {
        if (in_degree[u] == 0) next.push_back(u);
    }

    int u;
    while (!next.empty()) {
        u = next.back();
        next.pop_back();
        linear_order.push_back(u);

        for (int v = 0; v < n; v++) {
            if (G[u][v] == 1) {
                in_degree[v]--;
                if (in_degree[v] == 0) next.push_back(v);
            }
        }
    }

    // this process is to linear order same as book number
    for (int i = 0; i < n; i++) {
        linear_order[i]++;
    }

    return linear_order;
}


void Rerax(vector<int>& shortest, vector<int>& pred,
           vector<vector<int>>& weight, int u, int v)
{
    if (shortest[u] + weithg[u][v] < shortest[v]) {
        shortest[v] = shortest[u] + weight[u][v];
        pred[v] = u;
    }
}


vector<int> Dag_Shortest_Paths(vector<vector<int>>& G, int n, int s)
{
    vector<int> l = Topological_Sort(G, n);
    vector<int> shortest(n, numeric_limits<int>::max());
    vector<int> pred(n, NULL);

    shortest[s] = 0;

    int u;
    for (int i = 0; i < l.size(); i++) {
        u = l[i];
        for (int v = 0; v < n; v++) {
            if (G[u][v] == 1) Relax(shortest, pred, weight, u, v);
        }
    }
}
