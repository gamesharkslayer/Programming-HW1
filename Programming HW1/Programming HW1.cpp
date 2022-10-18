// Programming HW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <fstream>
#include<iomanip>

class student
{
public:
    // Constructors
    student();
    student(int number_of_data);
    // Access writes file data to class data
    void accessfile(char filename[20], int& number_of_data, student* file, course& filecour);
    // Prints out the list of classes
    void classlist(student x, int number_of_data, course& filecou);
    //functions for finding students with the highest scores
    friend void topscores(student file, int number_of_data, course cour);
    //Function for finding students that taken two classes
    friend void twoclass(student x, int number_of_data);
    friend void twoclass(student x, student x2, int number_of_data, int number_of_data2);
    friend void twoclass(student x, student x2, student x3, int number_of_data, int number_of_data2, int number_of_data3);
    //Function for finding students that have taken all classes
    friend void allclass(student file, int number_of_data);
    friend void allclass(student file, student file2, int number_of_data, int number_of_data2);
    friend void allclass(student file, student file2, student file3, int number_of_data, int number_of_data2, int number_of_data3);
private:
    //Only one student per class
    int id;
    string name;
    int score;
   
};

struct course {
    int size;
    string courname;
};

student* accessfile(char filename[20], int number_of_data);
int allcourselist();
int twocourse();
int topscore();


int main()
{
    // Initalises the needed variables
    int numberofcourses, number_of_data, number_of_data2, number_of_data3;
    int name;
    // Creates objects for files
    student* file1, *file2, *file3;
    course courfile1, courfile2, courfile3;
    // Enter the number of courses
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
        student* file1 = new student[number_of_data];
        file1->accessfile(filename, number_of_data, file1, courfile1);
        infile.close();
    }
    else if (numberofcourses == 2)
    {
        char filename[20];
        cout << "Enter filename : ";
        cin >> filename;
       
     
        infile.open(filename);
        infile >> name >> number_of_data;
        student* file1 = new student[number_of_data];
        file1->accessfile(filename, number_of_data, file1, courfile1);
        infile.close();

        char filename2[20];
        cout << "Enter filename : ";
        cin >> filename2;
        
        infile.open(filename2);
        infile >> name >> number_of_data2;
        student* file2 = new student[number_of_data2];
        file2->accessfile(filename2, number_of_data2, file2, courfile2);
        infile.close();
    }
    else if (numberofcourses == 3)
    {
        char filename[20];
        cout << "Enter filename : ";
        cin >> filename;
      
       
        infile.open(filename);
        infile >> name >> number_of_data;
        student* file1 = new student[number_of_data];
        file1->accessfile(filename, number_of_data, file1, courfile1);
        infile.close();

        char filename2[20];
        cout << "Enter filename : ";
        cin >> filename2;
       
        infile.open(filename2);
        infile >> name >> number_of_data2;
        student* file2 = new student[number_of_data2];
        file2->accessfile(filename2, number_of_data2, file2, courfile2);
        infile.close();

        char filename3[20];
        cout << "Enter filename : ";
        cin >> filename3;
        
        infile.open(filename3);
        infile >> name >> number_of_data3;
        student* file3 = new student[number_of_data3];
        file3->accessfile(filename3, number_of_data3, file3, courfile3);
        infile.close();
    }
    else 
    {
        cout << "Please Enter A valid filename or number of classes";
        return 0;
    }
   
    int menunum = 1;
    while (menunum > 0)
    {
        cout << "===== Menu ========" << endl;
        cout << "1. Show all course lists" << endl;
        cout << "2. list of students who take all courses" << endl;
        cout << "3. list of student who take two courses" << endl;
        cout << "4. Print out top three scores for each course" << endl;
        cout << "5. Exit program" << endl;
        cout << "---> select: ";
        cin >> menunum;

        if (menunum == 1)
        {
            if (numberofcourses == 1)
            {
                file1->classlist(file1, number_of_data, courfile1);
            }
            else if (numberofcourses == 2)
            {
                file1->classlist(file1, number_of_data, courfile1);
                file2.classlist(file2, number_of_data2, courfile2);
            }
            else if (numberofcourses == 3)
            {
                file1.classlist(file1, number_of_data, courfile1);
                file2.classlist(file2, number_of_data2, courfile2);
                file3.classlist(file3, number_of_data3, courfile3);
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
            if (numberofcourses == 2)
            {
               // topscores();
            }
            if (numberofcourses == 3)
            {
                topscores(file1, number_of_data);
            }
        }
    }
  
    
    return 0;
}
student::student() 
{
    id = 0;
    score = 0;
    name = "";
  
}


void topscores(student* file, int number_of_data, course cour)
{
    for (int step = 0; step < number_of_data; ++step) {

        // compare array elements
        for (int* i = 0; i < number_of_data - step; ++i) {

            // comparing the two adjacent elements
            if (file[i].score < file[i+1].score) {

                // swap
                int temp = file[i].score;
                file[i].score = file[i + 1].score;
                file[i + 1].score = temp;
            }
        }
        
    }
    cout << "[ " << cour.courname << " Top Three Scores ]";
    for (int count = 0; count < 3; count++)
    {
        int i = 0;
        cout << count << ". " << file[i].score << endl;
        cout << "      " << file[i].id << "     " << file[i].name;
        i++;
    }
}

void allclass(student* file, student* file2, student* file3, int number_of_data, int number_of_data2, int number_of_data3)
{
     
    int samestudent = 0;
    int biggestclass = number_of_data;
    if (number_of_data < number_of_data2)
    {
        biggestclass = number_of_data2;
    }
    else if (number_of_data2 < number_of_data3)
    {
        biggestclass = number_of_data3;
    }
    student* same = new student[biggestclass];
    //boolean values to check if there is an student that is the same
    bool file2nd, file3rd;
    for (int i = 0; i < number_of_data; i++)
    {
        // checks 2nd array for students
        for (int j = 0; j < number_of_data2; j++)
        {
            if (file[i].name == file2[j].name)
            {
                file2nd = true;
            }
        }
        // checks third array
        for (int k = 0; k < number_of_data3; k++)
        {
            if(file[i].name == file2[k].name)
            {
                file3rd = true;
            }
        }
        if ((file2nd = true) && (file3rd = true))
        {
            same[i].name = file[i].name;
            same[i].id = file[i].id;
            samestudent++;
        }
    }
    //Displays all sutdents
    cout << "There are " << samestudent << " students who take all courses" << endl;
    cout << "---------------------------------------------------------";
    for (int i = 0; i < samestudent; i++)
    {
        cout << same[i].id << "  " << same[i].name << endl;
    }
}

void student::classlist(student* file,int number_of_data,course& filecou)
{
    cout << "Course:" << filecou.courname << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < number_of_data; i++)
    {
        cout << file[i].id << "    " << file[i].name << "        " << file[i].score << endl;
    }
    cout << "======================" << endl;
    
}
void student::accessfile(char filename[20], int& number_of_data, student* file, course& filecour)
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
    filecour.courname = tempclass;
    
    int i = 0;
    int idfile, scorefile;
    string namefile;
    while (!infile.eof())
    {
        infile >> idfile >> namefile >> scorefile; //inputs variables from file
        file[i].id = idfile;
        file[i].name = namefile;
        file[i].score = scorefile;
        i++;
    }
    number_of_data = i;
}
