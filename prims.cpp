#include <bits/stdc++.h>
using namespace std;

int findIndex(vector<string> &city, string cn)
{
    for (int i = 0; i < city.size(); i++)
    {
        if (city[i] == cn)
        {
            return i;
        }
    }

    return -1;
}

void printMst(vector<vector<pair<int, int>>> &adj, vector<string> &city)
{
    // pair<int, pair<int,int>> weight, index, parent
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> mh;
    cout << "Enter the starting city : ";
    string city_name;
    cin >> city_name;

    int index = findIndex(city, city_name);

    if (index != -1)
    {
        mh.push({0, {index, -1}});
        vector<bool> visited(adj.size(), false);
        int mstw = 0;

        while (!mh.empty())
        {
            int w = mh.top().first;
            int c = mh.top().second.first;
            int p = mh.top().second.second;

            mh.pop();

            if (!visited[c])
            {
                visited[c] = true;

                for (auto it : adj[c])
                {
                    if (!visited[it.first])
                    {
                        mh.push({it.second, {it.first, c}});
                    }
                }

                if (p != -1)
                {
                    cout << city[p] << "->" << city[c] << " : " << w;
                    mstw += w;
                }
            }
        }

        cout << "MST Weight : " << mstw;
    }
    else
    {
        cout << "Please enter the valid city !!";
        return;
    }
}

int main()
{
    vector<string> city;
    cout << "Enter the total number of cities : ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the city " << (i + 1) << " : ";
        string city_name;
        cin >> city_name;
        city.push_back(city_name);
    }

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the number of adjacent cities to " << city[i] << " : ";
        int e;
        cin >> e;

        for (int j = 0; j < e; j++)
        {
            cout << "Enter the adjacent city " << (j + 1) << " to " << city[i] << " : ";
            string city_name;
            cin >> city_name;
            int index = findIndex(city, city_name);

            if (index != -1)
            {
                cout << "Enter the distance of " << city_name << " from " << city[i] << " : ";
                int w = 0;
                cin >> w;
                adj[i].push_back(make_pair(index, w));
            }
            else
            {
                cout << "Please enter the valid city !!";
                return 0;
            }
        }

        cout << endl;
    }

    printMst(adj, city);
}
