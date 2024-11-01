#include <bits/stdc++.h>
using namespace std;

void perm(int n,string s, vector<char>& v,int fre[]) {
    if (v.size() == n) {
        for (char x : v) {
            cout << x;
        }
        cout << endl;
        return;
    } else {
        for (int i = 0; i < n; ++i) {
            if (!fre[i]) {
                // To avoid generating duplicates, check if the character is the same as the previous one
                v.push_back(s[i]);
                fre[i] = 1;
                perm(n, s, v, fre);
                v.pop_back();
                fre[i] = 0;
            }
        }
    }
}

int main() {
    string s;
    cin >> s;
    // Sort the string to ensure lexicographical order
    vector<char> v;
    int n = s.length();
    int fre[n]={0};
    perm(n, s, v, fre);
    return 0;
}
