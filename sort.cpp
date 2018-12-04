#include <cstdio>
#include <string>
#include <iostream>
using namespace std;


string* Selection_Sort(string* A, int n);
string* Insertion_Sort(string* A, int n);


int main()
{
    int n = 5;
    string A[n] = {"Alex", "Bob", "Xhris", "Dave", "Eathern"};
    string x = "Alex";
    string* answer;

    answer = Insertion_Sort(A, n);
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


string* Insertion_Sort(string* A, int n)
{
    int j;
    string key;

    for (int i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;

        while (j > 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = key;
    }

    return A;
}
