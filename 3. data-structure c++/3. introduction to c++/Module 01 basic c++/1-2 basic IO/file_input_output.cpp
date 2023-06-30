#include<bits/stdc++.h>//everythings got in this header file.
//#include<iostream>
//#include<fstream>
//#include<algorithm>
//#include<vector>
using namespace std;
int main()
{
    double x = 3.55458;
    //printf("%.2lf",x);
    cout<<setprecision(3)<<fixed<<x;

    // input output

    ofstream n; //output file stream.and declare variable.
    n.open("1.txt");

    ofstream n1; //output file stream.and declare variable.
    n1.open("2.txt");

    ifstream n2;//input file stream.and declare variable.
    n2.open("0input.txt");

    n<<"hello world! how are you\n";

    n1<<"hello second person! how are you\n";


//    int x;
//    double y;
//    float z;
//    n2 >> x >> y >> z; //input
//
//    cout<< x << " " << y << " " <<z;//print or output


    // input output.2

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    //cin >> s;
    getline(cin,s);//for read and write data taking from user.

    cout <<s<<"\n";

      n.close();
      n1.close();
      n2.close();

    return 0;
}
