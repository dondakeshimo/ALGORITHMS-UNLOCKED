#include <cstdio>
#include <string>
#include <iostream>
#include <utility>
using namespace std;


string* Selection_Sort(string* A, int n);
string* Insertion_Sort(string* A, int n);
string* Merge_Sort(string* A, int p, int r);
string* Merge(string* A, int p, int q, int r);
string* Quick_Sort(string* A, int p, int r);
int Partition(string* A, int p, int r);
int* Really_Simple_Sort(int* A, int n);
int* Count_Keys_Equal(int* A, int n, int m);
int* Count_Keys_Less(int* equal_array, int m);
int* Rearrange(int* A, int* less, int n, int m);
int* Counting_Sort(int* A, int n, int m);


int main()
{
    int n = 5;
    string A[n] = {"Alex", "Bob", "Xhris", "Dave", "Eathern"};
    string x = "Alex";
    string* answer;

    answer = Quick_Sort(A, 0, 4);
    for (int i = 0; i < n; i++) {
        cout << answer[i] << endl;
    }

    cout << "-------------" << endl;

    int B[n] = {2, 1, 2, 1, 2};
    int* answer_2 = Really_Simple_Sort(B, n);
    for (int i = 0; i < n; i++) {
        cout << answer_2[i] << endl;
    }

    cout << "-------------" << endl;

    int C[n] = {2, 0, 2, 1, 2};
    int* answer_3 = Counting_Sort(C, n, 3);
    for (int i = 0; i < n; i++) {
        cout << answer_3[i] << endl;
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


string* Merge_Sort(string* A, int p, int r)
{
    if (p >= r) return A;
    else {
        int q = (p + r) / 2;
        Merge_Sort(A, p, q);
        Merge_Sort(A, q + 1, r);
        Merge(A, p, q, r);
    }

    return A;
}


string* Merge(string* A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    string B[n1 + 1], C[n2 + 1];
    const string inf = "ZZZZZZZZZZ";

    for (int i = 0; i < n1; i++) {
        B[i] = A[p + i];
    }

    for (int i = 0; i < n2; i++) {
        C[i] = A[q + 1 + i];
    }

    B[n1] = inf;
    C[n2] = inf;

    int i = 0, j = 0;

    for (int k = p; k < r + 1; k++) {
        if (B[i] <= C[j]) {
            A[k] = B[i];
            i++;
        } else {
            A[k] = C[j];
            j++;
        }
    }

    return A;
}


string* Quick_Sort(string* A, int p, int r)
{
    if (p >= r) return A;
    else {
        int q = Partition(A, p, r);
        Quick_Sort(A, p, q - 1);
        Quick_Sort(A, q + 1, r);
    }

    return A;
}


int Partition(string* A, int p, int r)
{
    int q = p;

    for (int u = p; u < r; u++) {
        if (A[u] <= A[r]) {
            swap(A[q], A[u]);
            q++;
        }
    }

    swap(A[q], A[r]);
    return q;
}


int* Really_Simple_Sort(int* A, int n)
{
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] == 1) k++;
    }

    for (int i = 0; i < n; i++) {
        if (i < k) A[i] = 1;
        else A[i] = 2;
    }

    return A;
}


int* Count_Keys_Equal(int* A, int n, int m)
{
    int equal_array[m] = {0};
    int key;

    for (int i = 0; i < n; i++) {
        key = A[i];
        equal_array[key]++;
    }

    return equal_array;
}


int* Count_Keys_Less(int* equal_array, int m)
{
    cout << 11 << endl;
    int less[m] = {0};

    cout << "kokokara" << endl;

    for (int i = 0; i < m; i++) {
        cout << equal_array[i] << endl;
    }

    cout << 12 << endl;
    for (int j = 1; j < m; j++) {
        cout << j << endl;
        cout << less[j] << endl;
        cout << less[j - 1] << endl;
        cout << equal_array[j - 1] << endl;
        less[j] = less[j - 1] + equal_array[j - 1];
        cout << j << endl;
    }

    cout << 14 << endl;
    return less;
}


int* Rearrange(int* A, int* less, int n, int m)
{
    int B[n], next[m], key, index;

    for (int j = 0; j < m; j++) {
        next[j] = less[j] + 1;
    }

    for (int i = 0; i < n; i++) {
        key = A[i];
        index = next[key];
        B[index] = A[i];
        next[key]++;
    }

    return B;
}


int* Counting_Sort(int* A, int n, int m)
{
    int* equal_array = Count_Keys_Equal(A, n, m);
    int* less = Count_Keys_Less(equal_array, m);
    int* B = Rearrange(A, less, n, m);

    return B;
}
