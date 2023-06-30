#include<bits/stdc++.h>
using namespace std;

bool flag = 0;
int cnt = 0;
int n,k;

vector<int> merge_sort(vector<int>a)
{
    //base case
    if(a.size() == 0)
        return a;
    if(a.size() == 1)
        return a;

    //array ke divide kora holo
    int mid = a.size()/2;

    //array er divided tow part declare kora holo
    vector<int>b;
    vector<int>c;

    for(int i=0; i<mid; i++)
        b.push_back(a[i]);

    for(int i=mid; i<a.size(); i++)
        c.push_back(a[i]);

    //tow chilled ke coll kora holo recursivly call kora holo
    vector<int> sorted_b = merge_sort(b);
    vector<int> sorted_c = merge_sort(c);

    // array a[] ke conquer/merge korte hobe

    vector<int> sorted_a;
    int index1 = 0;
    int index2 = 0;

    int sz = a.size();
    for(int i=0; i<sz; i++)
    {
        //index1 ses hole index2 theke nebe
        if(index1 == sorted_b.size())
        {
            sorted_a.push_back(sorted_c[index2]);
            index2++;
        }
        //index2 ses hole index1 theke nebe
        else if(index2 == sorted_c.size())
        {
            sorted_a.push_back(sorted_b[index1]);
            index1++;
        }
        //sorted_b index1 choto hole sorted_b index1 er value sorted_a te joma korte
        //and index1++ ek kore barbe.
        else if(sorted_b[index1] < sorted_c[index2])
        {
            sorted_a.push_back(sorted_b[index1]);
            index1++;
        }
        //sorted_c index2 boro hole sorted_a te joma korbe and index2++
        // ek kore barbe.
        else
        {
            sorted_a.push_back(sorted_c[index2]);
            index2++;
        }
    }

    for(int i=0; i<sorted_a.size()-1; i++)
    {
        for(int j=i+1; j<sorted_a.size()-1; j++)
        {
            if(a[i] + a[j] == k )
            {
                 cnt++;
                 flag = 1;
            }


        }

    }
 //ei code tuku O(nlogn) e onek try korlam.then give up.

    return sorted_a;
}

int main()
{

    cin >> n;

    vector<int>a;
    for(int i=0; i<n; i++)
    {
        int input;

        cin>> input;
        a.push_back(input);
    }

    cin >> k;

    vector<int> ans = merge_sort(a);

    if(flag==1)
        cout<<cnt<<"\n";
    else
       cout<<cnt<<"\n";


   return 0;
}

/*

    if(sorted_a.size() == n)
    {
        int i = 0, j = n  - 1;
        while(i<j)
        {
            if((sorted_a[i] + sorted_a[j]) == k)
            {
                j--;

            }

            else if ((sorted_a[i] + sorted_a[j]) == k)
            {

                i++;

            }
            else
            {
               flag = 1;
               break;
            }
        }
    }
*/
