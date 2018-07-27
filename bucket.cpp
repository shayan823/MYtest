#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector< vector<int> > vvi;

int count(int k)
{
    int dem = 0;
    for (int i = 0; i<10; i++)
    {
        if (k & 1 << i)
        dem++;
    }
    return dem;
}

void bucketSort(int a[], int n, vvi b)
{
    for (int i = 0; i<n; i++)
    {
        b[count(a[i])].push_back(a[i]);
    }
    for (int i = 0; i<10; i++)
    {
        sort(b[i].begin(), b[i].end());
    }
    for (int i = 0; i<10; i++)
    {
        for (int j = 0; j<b[i].size(); j++)
        {
            cout << b[i][j];
            if (j < b[i].size() - 1)
            cout << " ";
        }
        if (i < n - 1)
        cout << endl;
    }
}

int main()
{
    int n;
    int a[1010];
    vvi b;
    b.resize(11);
    cin >> n;
    for (int i = 0; i<n; i++)
    cin >> a[i];
    bucketSort(a, n, b);
    return 0;
}