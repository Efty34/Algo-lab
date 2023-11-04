#include <bits/stdc++.h>
using namespace std;
int dp[100][100][100];
int wara[100];
int vara[100];
int para[100];
int actVol;

int fun(int i, int w, int v)
{
    if (i <= 0 || w <= 0)
    {
        if (v <= actVol)
            return 0;
        return INT_MIN;
    }
    if (dp[i][w][v] != -1)
        return dp[i][w][v];
    int &dd = dp[i][w][v];
    if (w >= wara[i])
    {
        int one = fun(i - 1, w - wara[i], v + vara[i]);
        if (one != INT_MIN)
            one += para[i];

        int two = fun(i - 1, w, v);
        return dp[i][w][v] = max(one, two);
    }

    return dp[i][w][v] = fun(i - 1, w, v);
}
int main()
{
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> wara[i];
    }
    for (int i = 1; i <= n; i++)
        cin >> para[i];
    for (int i = 1; i <= n; i++)
        cin >> vara[i];
    int W, V;
    cin >> W >> V;
    actVol = V;
    int price = fun(n, W, 0);
    if (price == INT_MIN)
        cout << "NOT Reachable" << endl;
    else
        cout << "PRICE: " << price << endl;
}

/*
4
10 40 5
20 20 15
30 60 10
40 70 20
50 20
output--->100
*/