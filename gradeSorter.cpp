//COMSC-210 | Lab 13 | Eric-Giulio Hedes
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

//Initialize the global size constant
const int SIZE = 150;

//Define the Student struct
struct Student
{
    int id; //Student ID
    double grade; //Grade
};

//Prototype functions
void selectionSort(Student *s, int size);

//Start of main()
int main()
{
    //This is used for further procedures based on file availability
    bool failed = false;

    //Declare the variables
    int arrSize = 0; //The array size used for the input loop
    int i = 0; //Stores id
    double g = 0; //Stores grade
    Student list[SIZE]; //The array itself
    
    //Define both the file input and output
    ifstream fin;
    ofstream fout;

    //Open the input file
    fin.open("210-lab-13-grades.txt");
    //If the input file exists
    if (fin.good())
    {
        while (fin >> i)
        {
            fin.ignore();
            fin >> g;
            list[arrSize].id = i;
            list[arrSize].grade = g;
            arrSize += 1;
        }
    }
    else //Otherwise print a error message and set failed to true
    {
        cout << "Invalid file output..." << endl;
        failed = true;
    }

    //If the file found its output, do the sorting and output processes
    if (!failed)
    {
        //Sort the list by using selectionSort()
        selectionSort(list, SIZE);

        //Open the output file
        fout.open("210-lab-13-grades-sorted.txt");
        //Sort the output file by Student IDs
        for (int i = 0; i < SIZE; i++)
            fout << list[i].id << " " << list[i].grade << endl;
    }
}
//End of main()

//Define selectionSort()
void selectionSort(Student *s, int size)
{
    //Do a ranged loop based on the size
    for (int i = 0; i < size-1; i++)
    {
        //Temporary variable for storing the smallest variable
        int smallest = 0;
        //Do another ranged loop for the smallest value checks
        for (int j = i + 1; j < size; j++)
        {
            //If there is a number smaller than the smallest, set the smallest number
            if (s[j].id < s[smallest].id)
                smallest = j;
        }

        //Use the swap() function for swapping the whole struct (+ less clutter!)
        swap(s[i], s[smallest]);
    }
}