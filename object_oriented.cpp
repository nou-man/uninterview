//create TXT files as array1.txt and array2.txt which stores values of the array

#include <bits/stdc++.h>
using namespace std;

class Object_oriented
{
private:
    //creating private variables
    int array1[100];
    int array2[100];
    int size1;
    int size2;

    //creating unordered map
    unordered_map<int, int> umap;

public:
    //constructor 
    Object_oriented() {}

    //Method to find the soulutio i.e operations on the array
    void findSolution()
    {
        //for loop which itereates through the array1 to initialize each unique key to 0
        for (int i = 0; i < size1; i++)
        {
            umap[array1[i]] = 0;
        }
        //for loop to check for the presence of the target element from array2 and validate in the map we created
        for (int i = 0; i < size2; i++)
        {
            if (umap.find(array2[i]) != umap.end())
            {
                umap[array2[i]]++; //incrementing the key's value
            }
        }
    }

    //Method to print the result
    void printResult()
    {   
        //printing the output by iteratin to each elements from the map we created
        //here the auto i is an iterator which reads the each positional values in the unordermap
        for (auto i = umap.begin(); i != umap.end(); ++i)
        {
            cout << i->first << " : " << i->second << endl;
        }
    }

    //Method to take input for array1 and array2
    void takeInput()
    {
        //taking input from a file in which each line contains element of array1
        ifstream file1; //we declare a variable to store the file data
        size1 = 0; //initializing the size1 variable to 0 so that we can track array size parallelly
        file1.open("array1.txt"); //opening the array1.txt which has the values of the array
        while (file1 >> array1[size1]) //pushing values into the respective positions inside array
        {
            size1++;
        }

        //taking input from a file in which each line contains element of array2 
        //rest same as above
        ifstream file2;
        size2 = 0;
        file2.open("array2.txt");
        while (file2 >> array2[size2])
        {
            size2++;
        }
        

        // cout << "Enter the size of input for array1 ";
        // cin >> size1;
        // cout << "Enter the elements for array1: ";
        // for (int i = 0; i < size1; i++)
        // {
        //     cin >> array1[i];
        // }
        // cout << "Enter the size of input for array2 ";
        // cin >> size2;
        // cout << "Enter the elements for array2: ";
        // for (int i = 0; i < size2; i++)
        // {
        //     cin >> array2[i];
        // }
    }
    
};

int main()
{
    //variable to store the current time and end time
    time_t start_time, end_time;


    //creating object of class
    Object_oriented nobject;

    //creating object for taking input
    nobject.takeInput();

    //store the current time
    time(&start_time);

    //creating object for finding solution
    nobject.findSolution();

    //creating object for printing result
    nobject.printResult();

    //store the end time
    time(&end_time);

    //calculate the total time taken
    double time_taken = double(end_time - start_time);

    //print the total time taken
    cout << "The total time taken: " << fixed << time_taken << setprecision(5);
    // cout << "The total time taken: " << time_taken << " seconds" << endl;


    return 0;
}
