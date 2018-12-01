#include <cstdio>
#include <string>
#include <iostream>
using namespace std;


string* Selection_Sort(string* A, int n);


int main()
{
    int n = 5;
    string A[n] = {"Alex", "Bob", "Xhris", "Dave", "Eathern"};
    string x = "Alex";
    string* answer;

    answer = Selection_Sort(A, n);
    for (int i = 0; i < n; i++) {
        cout << answer[i] << endl;
    }
    return 0;
}


string* Selection_Sort(string* A, int n)
{
    int smallest;
    string temp;

    for (int i = 0; i < n; i++) {
        smallest = i;

        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[smallest]) smallest = j;
        }

        temp = A[i];
        A[i] = A[smallest];
        A[smallest] = temp;
    }

    return A;
}
