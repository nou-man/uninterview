#include<bits/stdc++.h>

using namespace std;

int main(){

    int array1[] = {1,2,3,1,5};
    int array2[] = {1,1,1,2,2};
    unordered_map <int, int> umap;

    int size1 = sizeof(array1)/sizeof(array1[0]);
    int size2 = sizeof(array2)/sizeof(array2[0]);

    for(int i = 0; i<size1;i++){
        umap[array1[i]] = 0;
    }
    for(int i=0;i<size2;i++){
        if(umap.find(array2[i]) != umap.end()){
            umap[array2[i]]++;
        }
    }

    for (auto i = umap.begin(); i != umap.end(); i++)
    {
        cout << i->first << " : " << i->second << endl;
    }
    


    return 0;
}