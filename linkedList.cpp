#include<bits/stdc++.h>

using namespace std;

int main(){

    
    list <int> l1;
  
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);

    for(auto i = l1.begin(); i != l1.end(); i++){
        cout << *i << " ";
    }

    return 0;
}