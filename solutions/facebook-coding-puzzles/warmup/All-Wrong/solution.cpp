#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

string getWrongAnswers(int N, string C) {
    for (int i = 0; i < N; i++)
           C[i] = C[i] == 'A' ? 'B' : 'A';
    return C;
}
