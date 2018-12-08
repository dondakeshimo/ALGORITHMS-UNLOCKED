#include <cstdio>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <limits>
using namespace std;


void Insert_array(vector<int>& Q, vector<vector<int>>& V);
int Extract_Min_array(vector<int>& shortest);
void Relax(vector<int>& shortest, vector<int>& pred,
           vector<vector<int>>& V, int u, int v);
int Dijkstra_array(vector<vector<int>>& V, int s, int goal);


int main()
{
    cout << "-------------" << endl;
    cout << "Dijkstra array" << endl;
    cout << "-------------" << endl;

    vector<vector<int>> V{
        { 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    };
    int answer;

    answer = Dijkstra_array(V, 0, 14);
    cout << answer << endl;
}


void Insert_array(vector<int>& Q, vector<vector<int>>& V)
{
    for (int i = 0; i < V.size(); i++) {
        queue[i] = i;
    }
}


int Extract_Min_array(vector<int>& shortest)
{
    int min = numeric_limits<int>::max();

    for (int i = 0; i < shortest.size(); i++) {
        if (shortest[i] < min) min = shortest[i];
    }

    return min;

}


void Relax(vector<int>& shortest, vector<int>& pred,
           vector<vector<int>>& V, int u, int v)
{
    if (shortest[u] + V[u][v] < shortest[v]) {
        shortest[v] = shortest[u] + V[u][v];
        pred[v] = u;
    }
}


int Dijkstra_array(vector<vector<int>> &V, int s, int goal)
{
    vector<int> shortest(V.size(), numeric_limits<int>::max());
    vector<int> pred(V.size(), numeric_limits<int>::max());
    vector<int> Q(V.size())

    shortest[s] = 0;

    Insert_array(Q, V)

    int u;

    while (!Q.empty()) {
        u = Extract_Min_array(shortest);

        for (int v = 0; v < G.size(); v++) {
            if (G[u][v] != 1) Relax(shortest, pred, V, u, v);
        }
    }

    return shortest[goal];
}
