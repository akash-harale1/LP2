#include <bits/stdc++.h>
using namespace std;

class PuzzleState
{
public:
    vector<vector<int>> board;
    int cost;
    int heu;

    PuzzleState(int cost, int heu, vector<vector<int>> board)
    {
        this->cost = cost;
        this->heu = heu;
        this->board = board;
    }

    bool operator<(const PuzzleState &o) const
    {
        return cost + heu > o.cost + o.heu;
    }
};

int inversionCount(vector<vector<int>> &s)
{
    int c = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int curr = s[i][j];

            if (curr == 0)
                continue;

            for (int k = i; k < 3; k++)
            {
                for (int l = (k == i ? j + 1 : 0); l < 3; l++)
                {
                    int nextEle = s[k][l];
                    if (nextEle != 0 && curr > nextEle)
                    {
                        c++;
                    }
                }
            }
        }
    }

    return c;
}

pair<int, int> findIndex(vector<vector<int>> &s, int val)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (s[i][j] == val)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int heuristic(vector<vector<int>> &s, vector<vector<int>> &g)
{
    int d = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            pair<int, int> goalp = findIndex(g, s[i][j]);
            d += abs(i - goalp.first) + abs(j - goalp.second);
        }
    }

    return d;
}

bool isGoalState(vector<vector<int>> &s, vector<vector<int>> &g)
{
    return s == g;
}

void printState(PuzzleState &ps)
{
    cout << "f(n) : " << ps.cost + ps.heu << " g(n) : " << ps.cost << " h(n) : " << ps.heu<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ps.board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<PuzzleState> generateSuccessor(PuzzleState &s, vector<vector<int>> &g)
{
    vector<PuzzleState> ps;
    int di[] = {1, 0, -1, 0};
    int dj[] = {0, 1, 0, -1};

    pair<int, int> temp = findIndex(s.board, 0);
    for (int k = 0; k < 4; k++)
    {
        int mi = temp.first + di[k];
        int mj = temp.second + dj[k];

        if ((mi >= 0 && mi < 3) && (mj >= 0 && mj < 3))
        {
            vector<vector<int>> ns = s.board;
            swap(ns[temp.first][temp.second], ns[mi][mj]);
            int h = heuristic(ns, g);
            int c = s.cost + 1;

            ps.push_back(PuzzleState(c, h, ns));
        }
    }

    return ps;
}

void astar(vector<vector<int>> &s, vector<vector<int>> &g)
{
    priority_queue<PuzzleState> q;
    int c = 0;
    int h = heuristic(s, g);
    q.push(PuzzleState(c, h, s));

    while (!q.empty())
    {
        PuzzleState ps = q.top();
        q.pop();
        printState(ps);
        if (isGoalState(ps.board, g))
        {
            break;
        }

        vector<PuzzleState> ns = generateSuccessor(ps, g);

        for (auto it : ns)
        {
            q.push(it);
        }
    }
}

int main()
{

    vector<vector<int>> s(3, vector<int>(3, 0));
    vector<vector<int>> g(3, vector<int>(3, 0));

    cout << "Enter initial state : ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> s[i][j];
        }
    }

    cout << " Enter goal state : ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> g[i][j];
        }
    }

    int gc = inversionCount(s);
    int lc = inversionCount(g);
    

    if ((gc % 2 == 0) && (lc % 2 == 0))
    {
        astar(s, g);
    }
    else
    {
        cout << "The problem is not solvable";
    }
}