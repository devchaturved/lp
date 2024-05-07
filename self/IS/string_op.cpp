#include<bits/stdc++.h>
using namespace std;

int main(){
    string input;
    cout<< " enter the string: " ;
    cin>>input;

    string p="";

    cout<<" -------> XOR <-------" << endl<< endl ;

    for(auto it:input){
        p.push_back(it^127);
    }
    cout<< p << endl ;

    cout<<"------> OR <------"<< endl;
     p = " " ;
    for(auto it : input){
        p.push_back(it | 127);
    }
    cout<< p<< endl;



    cout<< "------> AND <------" <<endl ;
    p = " "; 
    for(auto it: input){
        p.push_back(it & 127 );
    }
    cout<< p;
}