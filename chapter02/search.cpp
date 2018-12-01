#include <cstdio>
#include <string>
#include <iostream>
using namespace std;


int Linear_Search(string* A, int n, string x);
int Better_Linear_Search(string* A, int n, string x);
int Binary_Search(string* A, int n, string x);


int main()
{
    int n = 5;
    string A[n] = {"Alex", "Bob", "Chris", "Dave", "Eathern"};
    string x = "Dave";

    cout << "answer = " << Binary_Search(A, n, x) << endl;
    return 0;
}


int Linear_Search(string* A, int n, string x)
{
    int answer = -1;

    for (int i = 0; i < n; i++) {
        if (x == A[i]) answer = i;
    }

    return answer;
}


int Better_Linear_Search(string* A, int n, string x)
{
    int answer = -1;

    for (int i = 0; i < n; i++) {
        if (x == A[i]) {
            return i;
        }
    }

    return -1;
}


int Binary_Search(string* A, int n, string x)
{
    int p = 0, r = n - 1;
    int q;

    while (p <= r) {
        q = (p + r) / 2;
        if (A[q] == x) {
            return q;
        } else {
            if (A[q] > x) r = q - 1;
            else p = q + 1;
        }
    }

    return -1;
}
