#include<bits/stdc++.h>
using namespace std;

/**
Backtrack(state)
{
    if solution_found(state)
       - add state to answer
       - return

    for all valid candidates
        - add candidate to state
        - backtrack(state)
        - remove candidate from state

}

indx == n
[ , , ] = indx = 0
[1, , ] = indx = 1 [2,3] get_candidates(state)
[1,2, ] = indx = 2 [3] get_candidates(state)
[1,2,3] = indx = 3

*/

vector<vector<int>> ans;
int n;

bool solution_found(int indx, vector<int> state)
{
    if(indx == n)
        return true;
    else
        return false;

}

vector<int> get_candidate(vector<int> state)
{
    map<int, int> taken;

    for(int x : state)
        taken[x] = 1;

    vector<int> candidate;
    for(int i=1; i<=n; i++)
    {
        if(taken.count(i) == 0)
            candidate.push_back(i);

    }

    return candidate;

}


void backtrack(int indx, vector<int> state)
{
    /// base case handleing
    if(solution_found(indx,state))
    {
        ans.push_back(state);
        return;
    }

    /// loop over the candidates
    vector<int> candidate = get_candidate(state);

    for(int candid : candidate)
    {
        /// add candidate to state
        state[indx] = candid;

        /// backtrack(state)
        backtrack(indx + 1,state); /// update index
    }

    /// remove candidate from state
    state[indx] = 0;

}

int main()
{
    cin >> n;

    vector<int> initial_candidate(n);

    backtrack(0,initial_candidate);

//    for(vector<int> permutation : ans)
//    {
//        for(int x : permutation)
//            cout<< x <<" ";
//        cout<< endl;
//    }



    for(int i=0; i<ans.size(); i++)
    {
        for(int j : ans[i])
            cout<< j <<" ";

        cout<< endl;

    }


    return 0;
}
