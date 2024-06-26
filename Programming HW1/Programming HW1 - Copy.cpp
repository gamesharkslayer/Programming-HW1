// Programming HW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <fstream>
#include<iomanip>

class student
{
public:
    student();
    student(int number_of_data);
    void classlist(student x, int number_of_data);
    void classlist(student x, student x2);
    void classlist(student x, student x2, student x3);
    void accessfile(char filename[20], int& number_of_data, student x);
    friend void topscores(student x, int number_of_data);
    friend void topscores(student x, student x2, int number_of_data, int number_of_data2);
    friend void topscores(student x, student x2, student x3, int number_of_data, int number_of_data2, int number_of_data3);
    friend void twoclass();
    friend void allclass();
private:
    int* id;
    string* name;
    int* score;
    string* course;
};

struct course {
    string cpp;
    int cppsize;
    string java;
    int javasize;
    string python;
    int pythonsize;
};
/*
struct student
{
    string name;
    int id;
    int score;
};
*/
student* accessfile(char filename[20], int number_of_data);
int allcourselist();
int twocourse();
int topscore();


int main()
{
    int numberofcourses, number_of_data, number_of_data2, number_of_data3;
    int name;
    student file1, file2, file3;
    cout << "Enter the number of courses: ";
    cin >> numberofcourses;
    cout << endl;
    ifstream infile;
    if (numberofcourses == 1)
    {
        char filename[20];
        cout << "Enter filename : ";
        cin >> filename;
        
       
        infile.open(filename);
        infile >> name >> number_of_data;
        file1.accessfile(filename, number_of_data, file1);
        infile.close();
    }
    else if (numberofcourses == 2)
    {
        char filename[20];
        cout << "Enter filename : ";
        cin >> filename;
       
     
        infile.open(filename);
        infile >> name >> number_of_data;
        file1.accessfile(filename, number_of_data, file1);
        infile.close();

        char filename2[20];
        cout << "Enter filename : ";
        cin >> filename2;
        
        infile.open(filename2);
        infile >> name >> number_of_data2;
        file2.accessfile(filename2, number_of_data2, file2);
        infile.close();
    }
    else if (numberofcourses == 3)
    {
        char filename[20];
        cout << "Enter filename : ";
        cin >> filename;
      
       
        infile.open(filename);
        infile >> name >> number_of_data;
        file1.accessfile(filename, number_of_data, file1);
        infile.close();

        char filename2[20];
        cout << "Enter filename : ";
        cin >> filename2;
       
        infile.open(filename2);
        infile >> name >> number_of_data2;
        file2.accessfile(filename2, number_of_data2, file2);
        infile.close();

        char filename3[20];
        cout << "Enter filename : ";
        cin >> filename3;
        
        infile.open(filename3);
        infile >> name >> number_of_data3;
        file3.accessfile(filename3, number_of_data3, file3);
        infile.close();
    }
    else 
    {
        cout << "Please Enter A valid filename or number of classes";
    }
   
    int menunum = 1;
    while (menunum > 0)
    {
        cout << "===== Menu ========" << endl;
        cout << "1. Show all course lists" << endl;
        cout << "2. list of students who take all courses" << endl;
        cout << "3. list of student who take two courses" << endl;
        cout << "4. Print out top three scores for each course" << endl;
        cout << "9. Exit program" << endl;
        cout << "---> select: ";
        cin >> menunum;

        if (menunum == 1)
        {
            if (numberofcourses == 1)
            {
                file1.classlist(file1, number_of_data);
            }
            else if (numberofcourses == 2)
            {
                file1.classlist(file1, number_of_data);
                file2.classlist(file2, number_of_data2);
            }
            else if (numberofcourses == 3)
            {
                file1.classlist(file1, number_of_data);
                file2.classlist(file2, number_of_data2);
                file3.classlist(file3, number_of_data3);
            }
        }

        if (menunum == 2)
        {

        }

        if (menunum == 3)
        {

        }
        if (menunum == 4)
        {
            if (numberofcourses == 1)
            {
                topscores(file1, number_of_data);
            }
        }
    }
  
    
    return 0;
}
student::student() 
{
    id = new int[100];
    score = new int[100];
    name = new string[100];
    course = new string[1];
}
student::student(int number_of_data)
{
    id = new int[number_of_data];
    score = new int[number_of_data];
    name = new string[number_of_data];
    course = new string[1];
   
}

void topscores(student x,int number_of_data)
{
  
}

void student::classlist(student x,int number_of_data)
{
    cout << "Course:" << x.course[0] << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < number_of_data; i++)
    {
        cout << x.id[i] << "    " << x.name[i] << "        " << x.score[i] << endl;
    }
    cout << "======================" << endl;
    
}

void student::accessfile(char filename[20], int& number_of_data, student x)
{


    ifstream infile;
    infile.open(filename);
    if (infile.fail()) { // checks for file opening
        cout << "Input file opening filed." << endl;
        exit(1);
    }

    string tempclass;
    int temp;

    infile >> tempclass >> temp;
    x.course[0] = tempclass;
    
    int i = 0;
    int idfile, scorefile;
    string namefile;
    while (!infile.eof())
    {
        infile >> idfile >> namefile >> scorefile; //inputs variables from file
        x.id[i] = idfile;
        x.name[i] = namefile;
        x.score[i] = scorefile;
        i++;
    }
    number_of_data = i;
}
/*
student* accessfile(char filename[20], int* number_of_data)
{
    ifstream infile;
    infile.open("text.txt");
    if (infile.fail()) { // checks for file opening
        cout << "Input file opening filed." << endl;
        exit(1);
    }

    student* current;
    current = new struct student[20];

    int count, id, score;
    string name;
    count = 0;
    while (!infile.eof())
    {

        infile >> id >> name >> score; //inputs variables from file
        current[count].id = id;
        current[count].name = name;
        current[count].score = score;
        count++;

    }
    *number_of_data = count;
    return current;
}
int topscore()
{
    // Decalres max variable and checks it
    int max = 0;
    for (int j = 0; j < i; j++)
    {
        if (list[j].scores > max)
        {
            max = list[j].scores;
        }
    }

    cout << "The max score is: " << max << endl;
    cout << "------------------" << endl;
    // Goes through the array and looks for the students with max scores
    for (int y = 0; y < i; y++)
    {
        if (max == list[y].scores)
        {
            cout << list[y].id << "  " << list[y].name << " " << list[y].scores << endl;
        }
    }

}
*/