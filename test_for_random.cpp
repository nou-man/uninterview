#include <bits/stdc++.h>

using namespace std;

int main()
{

    // create an array named array3 of size 5 and store random numbers in it
    int array3[5];
    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        array3[i] = rand() % 10;
    }
    
    int arraysize = sizeof(array3)/sizeof(array3[0]);
    
    for(int i=0; i<arraysize; i++){
        cout << array3[i] << " ";
    }

    return 0;
}