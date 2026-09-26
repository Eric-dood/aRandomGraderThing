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
void results(Student s[], int size);

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
        cout << "Read " << arrSize << " student records." << endl;
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
        string outputFile = "210-lab-13-grades-sorted.txt";
        fout.open(outputFile);
        //Sort the output file by Student IDs
        for (int i = 0; i < SIZE; i++)
            fout << list[i].id << " " << list[i].grade << endl;
        cout << "Sorted results written to: '" << outputFile << "'" << endl;
    }

    //Print out the results
    results(list, SIZE);
}
//End of main()

//Define selectionSort()
void selectionSort(Student *s, int size)
{
    //Do a ranged loop based on the size
    for (int i = 0; i < size-1; i++)
    {
        //Temporary variable for storing the smallest variable
        int smallest = i;
        //Do another ranged loop for the smallest value checks
        for (int j = i + 1; j < size; j++)
        {
            //If there is a number smaller than the smallest, set the smallest number
            if (s[j].id < s[smallest].id)
                smallest = j;
        }

        //Sort the struct elements by Student ID manually
        Student temp = s[i];
        s[i] = s[smallest];
        s[smallest] = temp;
    }
}

//Define results()
void results(Student s[], int size = SIZE)
{
    Student smallest = s[0], largest = s[0];
    double mean, medianBase[size];
    int medianNum;
    for (int i = 0; i < size; i++)
    {
        //Find the smallest grade
        if (s[i].grade < smallest.grade) smallest = s[i];
        //Find the largest grade
        if (s[i].grade > largest.grade) largest = s[i];
        //Find the mean
        mean += s[i].grade;
        //Find the median
        for (int i = 0; i < size; i++) medianBase[i] = s[i].grade;
        sort(medianBase.begin(), medianBase.end());
        if ((size % 2) != 0) medianNum = medianBase[size/2];
        else medianNum = (medianBase[size / 2 - 1] + medianBase[size / 2]) / 2;
    }
    //Divide the mean by the size itself
    mean /= size;

    cout << endl << "-------- Summary Statistics --------" << endl;
    cout << "Minimum Score: " << smallest.grade << " (Student ID: " << smallest.id << ")" << endl;
    cout << "Maximum Score: " << largest.grade << " (Student ID: " << largest.id << ")" << endl;
    cout << "Mean Score: " << mean << endl;
    cout << "Median Score: " << s[medianNum].grade << " (Student ID: " << s[medianNum].id << ")" << endl;
}