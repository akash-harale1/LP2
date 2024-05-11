#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<string>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isPossible(int i, int j, vector<vector<string>> &board)
{
    for (int k = i; k >= 0; k--)
    {
        if (board[k][j] == "Q")
            return false;
    }

    int di = i;
    int dj = j;

    while (di >= 0 && dj >= 0)
    {
        if (board[di][dj] == "Q")
        {
            return false;
        }

        di = di - 1;
        dj = dj - 1;
    }

    di = i;
    dj = j;

    while (di >= 0 && dj < board.size())
    {
        if (board[di][dj] == "Q")
        {
            return false;
        }

        di = di - 1;
        dj = dj + 1;
    }

    return true;
}

bool branch(vector<vector<string>> &board, vector<int> &col, vector<int> &ndigo, vector<int> &rdigo, int i)
{
    if (i == board.size())
    {
        cout << "Solution found " << endl;
        printBoard(board);
        return true;
    }

    int n = board.size();

    for (int j = 0; j < board.size(); j++)
    {
        if (col[j] == 0 && ndigo[i + j] == 0 && rdigo[(i - j) + (n - 1)] == 0)
        {
            board[i][j] = "Q";
            col[j] = 1;
            ndigo[i + j] = 1;
            rdigo[(i - j + (n - 1))] = 1;

            printBoard(board);
            if (branch(board, col, ndigo, rdigo, i + 1))
            {
                return true;
            }

            board[i][j] = "_";
            col[j] = 0;
            ndigo[i + j] = 0;
            rdigo[(i - j + (n - 1))] = 0;
        }
    }

    return false;
}

bool backTracking(vector<vector<string>> &board, int i)
{
    if (i == board.size())
    {
        cout << "Solution found " << endl;
        printBoard(board);
        return true;
    }

    for (int j = 0; j < board.size(); j++)
    {
        if (isPossible(i, j, board))
        {
            board[i][j] = "Q";
            printBoard(board);
            if (backTracking(board, i + 1))
                return true;
            board[i][j] = "_";
        }
    }

    return false;
}

int main()
{

    cout << "Enter the number of queens : ";
    int n;
    cin >> n;

    vector<vector<string>> board(n, vector<string>(n, "_"));

    // backTracking(board, 0);

    vector<int> col(n, 0);
    vector<int> ndigo(n * 2 - 1, 0);
    vector<int> rdigo(n * 2 - 1, 0);

    branch(board, col, ndigo, rdigo, 0);
}