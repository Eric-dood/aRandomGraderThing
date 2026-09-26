//COMSC-210 | Lab 13 | Eric-Giulio Hedes
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 150;

struct Student
{
    int id;
    double grade;
};

void selectionSort(Student *s, int size);

int main()
{
    int arrSize = 0;
    int i = 0; //Stores id
    double g = 0; //Stores grade
    Student list[SIZE];
    
    ifstream fin;
    ofstream fout;

    fin.open("210-lab-13-grades.txt");
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

    selectionSort(list, SIZE);
}

void selectionSort(Student *s, int size)
{
    for (int i = 0; i < SIZE-1; i++)
    {
        int smallest = 0;
        for (int j = i + 1; j < SIZE; j++)
        {
            if (s[j].id < s[smallest].id)
                smallest = j;
        }

        swap(s[i], s[smallest]);
    }
}