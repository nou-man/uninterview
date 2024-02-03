#include <bits/stdc++.h>
using namespace std;

class uni_linkedList
{
private:
    // creating private variables
    list <int> list1;
    list <int> list2;
    int size1;
    int size2;

    // I created an ordered map insted of unordered map
    map <int, int> umap;

    // creating unordered map
    // unordered_map<int, int> umap;

public:
    // constructor
    uni_linkedList() {}

    // Method to find the soulutio i.e operations on the list
    void findSolution()
    {
        // for loop which itereates through the list1 to initialize each unique key to 0
        for (auto i = list1.begin(); i != list1.end(); i++)
        {
            umap[*i] = 0;
        }
        // for loop to check for the presence of the target element from list2 and validate in the map we created
        for (auto i = list2.begin(); i != list2.end(); i++)
        {
            if (umap.find(*i) != umap.end())
            {
                umap[*i]++; // incrementing the key's value
            }
        }
    }

    // Method to print the result
    void printResult()
    {
        // printing the output by iteratin to each elements from the map we created
        // here the auto i is an iterator which reads the each positional values in the unordermap
        for (auto i = umap.begin(); i != umap.end(); ++i)
        {
            cout << i->first << " : " << i->second << endl;
        }
    }

    // Method to take input for list1 and list2
    void takeInput()
    {

        size1 = 0, size2 = 0;
        srand(time(0));
        for (int i = 0; i < 500000; i++)
        {
            list1.push_back(rand() % 100);
            size1++;
        
        }
        for (int j = 0; j < 500000; j++)
        {
            list2.push_back(rand() % 100);
            size2++;
        }



        // taking input from a file in which each line contains element of list1
        //  ifstream file1; //we declare a variable to store the file data
        //  size1 = 0; //initializing the size1 variable to 0 so that we can track list size parallelly
        //  file1.open("list1.txt"); //opening the list1.txt which has the values of the list
        //  while (file1 >> list1[size1]) //pushing values into the respective positions inside list
        //  {
        //      size1++;
        //  }

        // //taking input from a file in which each line contains element of list2
        // //rest same as above
        // ifstream file2;
        // size2 = 0;
        // file2.open("list2.txt");
        // while (file2 >> list2[size2])
        // {
        //     size2++;
        // }

        // cout << "Enter the size of input for list1 ";
        // cin >> size1;
        // cout << "Enter the elements for list1: ";
        // for (int i = 0; i < size1; i++)
        // {
        //     cin >> list1[i];
        // }
        // cout << "Enter the size of input for list2 ";
        // cin >> size2;
        // cout << "Enter the elements for list2: ";
        // for (int i = 0; i < size2; i++)
        // {
        //     cin >> list2[i];
        // }
    }
};

int main()
{
    // variable to store the current time and end time
    time_t start_time, end_time;

    // creating object of class
    uni_linkedList nobject;

    // store the current time
    time(&start_time);
    
    // creating object for taking input
    nobject.takeInput();


    // creating object for finding solution
    nobject.findSolution();

    // creating object for printing result
    nobject.printResult();

    // store the end time
    time(&end_time);

    // calculate the total time taken
    double time_taken = double(end_time - start_time);

    // print the total time taken
    cout << "The total time taken: " << fixed << time_taken << setprecision(5);
    // cout << "The total time taken: " << time_taken << " seconds" << endl;

    return 0;
}
