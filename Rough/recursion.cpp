#include <iostream>
#include <string>
using namespace std;

// aaabbcddeee

bool rat_in_maze(int **arr, int **ans, int size, int x, int y)
{
    if (x == size - 1 && y == size - 1)
    {
        ans[x][y] = 1;
        return true;
    }

    if (arr[x][y] == 1 && x < size && y < size)
    {
        ans[x][y] = 1;

        if (rat_in_maze(arr, ans, size, x, y + 1))
            return true;

        else if (rat_in_maze(arr, ans, size, x + 1, y))
            return true;

        else
        {
            ans[x][y] = 0;
            return false;
        }
    }
    return false;
}

int main()
{
    int **arr = new int *[5];
    for (int i = 0; i < 5; i++)
        arr[i] = new int[5];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];

    int **ans = new int *[5];
    for (int i = 0; i < 5; i++)
        ans[i] = new int[5];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            ans[i][j] = 0;

    int x = 0, y = 0;
    rat_in_maze(arr, ans, 5, x, y);

    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << ans[i][j] << " ";

        cout << endl;
    }
}