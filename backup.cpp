#include <bits/stdc++.h>
using namespace std;

class Backup {
private:
    int* array1;
    int* array2;
    int size1;
    int size2;
    unordered_map<int, int> umap;

public:
    Backup(int* arr1, int* arr2, int size1, int size2) : array1(arr1), array2(arr2), size1(size1), size2(size2) {}

    void findSolution() {
        for (int i = 0; i < size1; i++) {
            umap[array1[i]] = 0;
        }
        for (int i = 0; i < size2; i++) {
            if (umap.find(array2[i]) != umap.end()) {
                umap[array2[i]]++;
            }
        }
    }

    void printResult() {
        for (auto i = umap.begin(); i != umap.end(); ++i) {
            cout << i->first << " : " << i->second << endl;
        }
    }

};

int main() {
    int array1[] = {1, 2, 3, 1, 5};
    int array2[] = {1, 1, 1, 2, 2};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    Backup nobject(array1, array2, size1, size2);

    nobject.findSolution();
    nobject.printResult();
    

    return 0;
}
