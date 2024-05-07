#include <bits/stdc++.h>

using namespace std;

bool is_safe(vector<vector<int>> &arr, int x, int y, int n)
{
    for (int row = 0; row < x; row++){
        if (arr[row][y] == 1){
            return false;
        }
    }

    // upper left daigoanl
    int row = x;
    int col = y;

    while (row >= 0 && col >= 0){

        if (arr[row][col] == 1){
            return false;
        }

        row--;
        col--;
    }

    row = x;
    col = y;
    // upper right daigonal
    while (row >= 0 && col < n){
        if (arr[row][col] == 1){
            return false;
        }

        row--;
        col++;
    }
    return true;
}


bool nqueen(vector<vector<int>> &arr, int x, int n) 
{

    // x is the current row where the algorithm is trying to place a queen.
    if (x >= n){ // base    // comes out of the board
        return true;
    }


    for (int col = 0; col < n; col++){
        if (is_safe(arr, x, col, n)){
            arr[x][col] = 1; //if safe put the queen at that x location

            if (nqueen(arr, x + 1, n)){
                return true;   // again check for x+1;
            }
            arr[x][col] = 0; // back trac
        }
    }
    return false;
}


int main()
{

    cout << " Enter the value of n";
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n, 0));
    
    if (nqueen(arr, 0, n)){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
