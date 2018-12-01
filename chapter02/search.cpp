#include <cstdio>
#include <string>
#include <iostream>
using namespace std;


int Linear_Search(string* A, int n, string x);
int Better_Linear_Search(string* A, int n, string x);


int main()
{
    int n = 3;
    string A[n] = {"Alex", "Bob", "Chris"};
    string x = "Bob";

    return Better_Linear_Search(A, n, x);
}


int Linear_Search(string* A, int n, string x)
{
    int answer = -1;

    for (int i = 0; i < n; i++) {
        if (x == A[i]) answer = i;
    }

    cout <<  answer << endl;

    return answer;
}


int Better_Linear_Search(string* A, int n, string x)
{
    int answer = -1;

    for (int i = 0; i < n; i++) {
        if (x == A[i]) {
            cout << "answer = " <<  i << endl;
            return i;
        }
    }

    cout <<  "answer = " << -1 << endl;

    return -1;
}
