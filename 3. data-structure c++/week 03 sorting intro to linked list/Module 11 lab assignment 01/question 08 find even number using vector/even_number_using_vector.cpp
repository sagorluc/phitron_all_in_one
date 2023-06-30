#include<bits/stdc++.h>
using namespace std;
vector<int> even_generator(vector<int> a)
{
    vector<int> even;

    for(int i=0; i<a.size(); i++)
    {
        if(a[i] % 2 == 0)
            even.push_back(a[i]);

    }
    return even;


}
int main()
{
   vector<int> a = {1,2,3,4,5};

   vector<int> res = even_generator(a);

      for(int i=0; i<res.size(); i++)
            cout<< res[i] << " ";


    return 0;
}
