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

int Bellman_Ford(vector<vector<int>>& V, int s, int goal);


int main()
{
    cout << "-------------" << endl;
    cout << "Dijkstra array" << endl;
    cout << "-------------" << endl;

    vector<vector<int>> V{
        { 0, 6, 0, 4, 0 },  // s
        { 0, 0, 3, 2, 0 },  // t
        { 0, 0, 0, 0, 4 },  // x
        { 0, 1, 9, 0, 3 },  // y
        { 7, 0, 5, 0, 0 },  // z
    //    s, t, x, y, z
    };
    int answer;

    answer = Dijkstra_array(V, 0, 4);
    cout << answer << endl;


    cout << "-------------" << endl;
    cout << "Bellman Ford" << endl;
    cout << "-------------" << endl;

    answer = Bellman_Ford(V, 0, 4);
    cout << answer << endl;
}


void Insert_array(vector<int>& Q, vector<vector<int>>& V)
{
    for (int i = 0; i < V.size(); i++) {
        Q[i] = i;
    }
}


int Extract_Min_array(vector<int> &Q, vector<int>& shortest)
{
    int q;
    int u;
    int del_idx;
    int min = numeric_limits<int>::max();

    for (int i = 0; i < Q.size(); i++) {
        q = Q[i];
        if (shortest[q] < min) {
            min = shortest[q];
            del_idx = i;
            u = q;
        }
    }

    Q.erase(Q.begin() + del_idx);

    return u;

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
    vector<int> Q(V.size());

    shortest[s] = 0;

    Insert_array(Q, V);

    int u;

    while (!Q.empty()) {
        u = Extract_Min_array(Q, shortest);

        for (int v = 0; v < V.size(); v++) {
            if (V[u][v] != 0) Relax(shortest, pred, V, u, v);
        }
    }

    // show all shortest time
    for (int i = 0; i < shortest.size(); i++) {
        cout << i << ": " << shortest[i] << endl;
    }

    return shortest[goal];
}


int Bellman_Ford(vector<vector<int>> &V, int s, int goal)
{
    vector<int> shortest(V.size(), numeric_limits<int>::max());
    vector<int> pred(V.size(), numeric_limits<int>::max());

    shortest[s] = 0;

    for (int i = 0; i < V.size(); i++) {
        for (int u = 0; u < V.size(); u++) {
            for (int v = 0; v < V.size(); v++) {
                if (V[u][v] != 0) Relax(shortest, pred, V, u, v);
            }
        }
    }

    // show all shortest time
    for (int i = 0; i < shortest.size(); i++) {
        cout << i << ": " << shortest[i] << endl;
    }

    return shortest[goal];
}
