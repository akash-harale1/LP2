#include <bits/stdc++.h>
using namespace std;

class disjoint_set
{
    vector<int> size;
    vector<int> parent;

public:
    disjoint_set(int v)
    {
        size.resize(v);
        parent.resize(v);
        for (int i = 0; i < v; i++)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (size[pu] < size[pv])
        {
            parent[pu] = parent[pv];
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = parent[pu];
            size[pu] += size[pv];
        }
    }
};

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

void print_mst(vector<pair<int, pair<int, int>>> &ans, vector<string> &city, int mstw)
{
    for (auto it : ans)
    {
        cout << city[it.second.first] << "->" << city[it.second.second] << " : " << it.first << " " << endl;
    }
    cout << "cost of mst : " << mstw;
}

void kruskal(vector<vector<pair<int, int>>> &adj, vector<string> &city)
{
    vector<pair<int, pair<int, int>>> ans;
    vector<pair<int, pair<int, int>>> elist;

    for (int i = 0; i < adj.size(); i++)
    {
        for (auto it : adj[i])
        {
            elist.push_back({it.second, {i, it.first}});
        }
    }

    sort(elist.begin(), elist.end());
    int mstw = 0;
    disjoint_set ds(adj.size());

    for (int i = 0; i < elist.size(); i++)
    {
        int w = elist[i].first;
        int u = elist[i].second.first;
        int v = elist[i].second.second;

        if (ds.findParent(u) != ds.findParent(v))
        {
            ans.push_back({w, {u, v}});
            ds.unionBySize(u, v);
            mstw += w;
        }
    }

    print_mst(ans, city, mstw);
}

int main()
{
    vector<string> city;
    cout << "Enter total number of cities : ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter city " << (i + 1) << " : ";
        string cn;
        cin >> cn;
        city.push_back(cn);
    }

    vector<vector<pair<int, int>>> adj(n);

    cout << "Enter total number of edges : ";
    int e;
    cin >> e;

    for (int i = 0; i < e; i++)
    {
        string ss, ds;
        int si, di, w;

        cout << "Enter source city : ";
        cin >> ss;

        si = findIndex(city, ss);

        cout << "Enter destination city : ";
        cin >> ds;

        di = findIndex(city, ds);

        cout << "Enter the distance between them : ";
        cin >> w;

        adj[si].push_back(make_pair(di, w));
        adj[di].push_back(make_pair(si, w));
    }

    kruskal(adj, city);
}