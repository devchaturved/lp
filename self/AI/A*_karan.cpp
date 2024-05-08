#include <bits/stdc++.h>
using namespace std;
map<vector<vector<int>>, bool> mp;
bool flg = 0;
int diff(vector<vector<int>> &inital_v, vector<vector<int>> &final_v)
{
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans += (inital_v[i][j] != final_v[i][j]);
        }
    }

    return ans;
}

void f(vector<vector<int>> inital_v, vector<vector<int>> final_v, int height)
{

    vector<pair<int, vector<vector<int>>>> all_v;
    if (flg)
        return;

    if (diff(inital_v, final_v) == 0)
    {
        flg = 1;
        cout << height << endl;
        return;
    }

    int ii = 0, jj = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (inital_v[i][j] == 0)
            {
                ii = i;
                jj = j;
                break;
            }
        }
    }

    if (ii - 1 >= 0)
    {
        swap(inital_v[ii][jj], inital_v[ii - 1][jj]);
        if (mp[inital_v] == 0)
        {
            mp[inital_v] = 1;
            all_v.push_back({diff(inital_v, final_v) + height, inital_v});
        }
        swap(inital_v[ii][jj], inital_v[ii - 1][jj]);
    }
    if (jj - 1 >= 0)
    {
        swap(inital_v[ii][jj], inital_v[ii][jj - 1]);
        if (mp[inital_v] == 0)
        {
            mp[inital_v] = 1;
            all_v.push_back({diff(inital_v, final_v) + height, inital_v});
        }
        swap(inital_v[ii][jj], inital_v[ii][jj - 1]);
    }
    if (ii + 1 < 3)
    {
        swap(inital_v[ii][jj], inital_v[ii + 1][jj]);
        if (mp[inital_v] == 0)
        {
            mp[inital_v] = 1;
            all_v.push_back({diff(inital_v, final_v) + height, inital_v});
        }
        swap(inital_v[ii][jj], inital_v[ii + 1][jj]);
    }
    if (jj + 1 >= 0)
    {
        swap(inital_v[ii][jj], inital_v[ii][jj + 1]);
        if (mp[inital_v] == 0)
        {
            mp[inital_v] = 1;
            all_v.push_back({diff(inital_v, final_v) + height, inital_v});
        }
        swap(inital_v[ii][jj], inital_v[ii][jj + 1]);
    }

    sort(all_v.begin(), all_v.end());
    // vector<vector<int>> it1 = all_v.begin().second;
    // for(auto it:it1){
    //     for(auto it2:it){
    //         cout<<it2<<" ";
    //     }
    //     cout<<endl;
    // }
    for (auto it : all_v)
    {
        f(it.second, final_v, height + 1);
    }
}

int main()
{
    vector<vector<int>> inital_v = {
        {1, 0, 2},
        {3, 4, 5},
        {6, 7, 8}};
    vector<vector<int>> final_v = {
        {1, 4, 2},
        {3, 7, 5},
        {6, 8, 0}};

    f(inital_v, final_v, 0);
}
