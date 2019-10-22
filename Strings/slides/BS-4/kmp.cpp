#include <bits/stdc++.h>

using namespace std;

vector<int> strong_borders(const string& P)
{
    int m = P.size(), t = -1;
    vector<int> bs(m + 1, -1);

    for (int j = 1; j <= m; ++j)
    {
        while (t > -1 and P[t] != P[j - 1])
            t = bs[t];

        ++t;

        bs[j] = (j == m or P[t] != P[j]) ? t : bs[t];
    }

    return bs;
}

int KMP(const string& S, const string& P)
{
    int n = S.size(), m = P.size();
    int i = 0, j = 0, occ = 0;

    vector<int> bs = strong_borders(P);

    while (i <= n - m)
    {
        while (j < m and P[j] == S[i + j])
            ++j;

        if (j == m) ++occ;

        int shift = j - bs[j];
        i += shift;
        j = max(0, j - shift);
    } 

    return occ;
}

int main()
{
    string S = "abaabbabaabaaba", P = "abaaba";
    auto bs = strong_borders(P);

    cout << "i\tsubs\t\tborder\tshift\n";

    for (size_t i = 0; i <= P.size(); ++i)
    {
        cout << i << '\t' << P.substr(0, i) << '\t';

        if (i < 8)
            cout << '\t';

        cout << bs[i] << '\t' << i - bs[i] << '\n';
    }

    cout << '\n' << KMP(S, P) << '\n';

    return 0;
}
