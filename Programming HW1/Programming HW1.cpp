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
    student(int i, string n, int s);
    void setscore(int s);
    void setId(int i);
    void setname(string n);
    int getId();
    string getName();
    int getscore();
    /*
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
*/
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

student* accessfile(char filename[20], int& number_of_data, course& filecour);
void classlist(student* file, int number_of_data, course& filecou);
void topscores(student* file, int number_of_data, course cour);
void allclass(student* file, student* file2, student* file3, int number_of_data, int number_of_data2, int number_of_data3,course cour1,course cour2,course cour3);
int main()
{
    // Initalises the needed variables
    int numberofcourses, number_of_data, number_of_data2, number_of_data3;
     string name;
    // Creates objects for files
    student* file1, * file2, * file3;
    file1 = NULL;
    file2 = NULL;
    file3 = NULL;
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
       
        file1 = new student[number_of_data];
        
        file1 = accessfile(filename, number_of_data, courfile1);
        infile.close();
        
    }
    
    else if (numberofcourses == 2)
    {
        char filename[20];
        cout << "Enter filename : ";
        cin >> filename;
       
     
        infile.open(filename);
        infile >> name >> number_of_data;
        file1 = new student[number_of_data];
        file1 = accessfile(filename, number_of_data, courfile1);
        infile.close();

        char filename2[20];
        cout << "Enter filename : ";
        cin >> filename2;
        
        infile.open(filename2);
        infile >> name >> number_of_data2;
        file2 = new student[number_of_data2];
        file2 = accessfile(filename2, number_of_data2, courfile2);
        infile.close();
    }
    else if (numberofcourses == 3)
    {
        char filename[20];
        cout << "Enter filename : ";
        cin >> filename;
      
       
        infile.open(filename);
        infile >> name >> number_of_data;
        file1 = new student[number_of_data];
        file1 = accessfile(filename, number_of_data, courfile1);
        infile.close();

        char filename2[20];
        cout << "Enter filename : ";
        cin >> filename2;
       
        infile.open(filename2);
        infile >> name >> number_of_data2;
        file2 = new student[number_of_data2];
        file2 = accessfile(filename2, number_of_data2, courfile2);
        infile.close();

        char filename3[20];
        cout << "Enter filename : ";
        cin >> filename3;
        
        infile.open(filename3);
        infile >> name >> number_of_data3;
        file3 = new student[number_of_data3];
        file3 = accessfile(filename3, number_of_data3, courfile3);
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
                
                classlist(file1, number_of_data, courfile1);
            }
            else if (numberofcourses == 2)
            {
                classlist(file1, number_of_data, courfile1);
                classlist(file2, number_of_data2, courfile2);
            }
            else if (numberofcourses == 3)
            {
                classlist(file1, number_of_data, courfile1);
                classlist(file2, number_of_data2, courfile2);
                classlist(file3, number_of_data3, courfile3);
            }
        }

        if (menunum == 2)
        {
            if (numberofcourses == 3) {
               allclass(file1, file2, file3, number_of_data, number_of_data2, number_of_data3, courfile1, courfile2, courfile3);
            }
        }

        if (menunum == 3)
        {

        }
        if (menunum == 4)
        {
            if (numberofcourses == 1)
            {
                
                topscores(file1, number_of_data,courfile1);
                
            }
            if (numberofcourses == 2)
            {
                topscores(file1, number_of_data, courfile1);
                topscores(file2, number_of_data2, courfile2);
            }
            if (numberofcourses == 3)
            {
                
                topscores(file1, number_of_data, courfile1);
                topscores(file2, number_of_data2, courfile2);
                topscores(file3, number_of_data3, courfile3);
                
            }
        }
    }
  
    
    return 0;
}
student::student()
{
    id = 100;
    score = 100;
    name = "empty";
  
}
student::student(int i, string n, int s)
{
    id = i;
    score = s;
    name = n;
}

void student::setscore(int s)
{
    score = s;
}
void student::setId(int i)
{
    id = i;
}
void student::setname(string n)
{
    name = n;
}
int student::getId()
{
    return id;
}
string student::getName()
{
    return name;
}
int student::getscore()
{
    return score;
}
void topscores(student* file, int number_of_data, course cour)
{
    
    int first=3, second=2, third=1;
    for (int i = 0; i < number_of_data;i++)
    {
        if (file[i].getscore() > first)
        {
            first = file[i].getscore();
        }
    }
    for (int i = 0; i < number_of_data; i++)
    {
        if ((file[i].getscore() < first) && (file[i].getscore() > second))
        {
            second = file[i].getscore();
        }
    }
    for (int i = 0; i < number_of_data; i++)
    {
        if ((file[i].getscore() < first) && (file[i].getscore() < second) && (file[i].getscore() > third))
        {
            third = file[i].getscore();
        }
    }
    cout << "[ " << cour.courname << " Top Three Scores ]"<< endl;
   
       
        cout << "1. " << first << endl;
        for (int i = 0; i < number_of_data; i++)
        {
            if (first == file[i].getscore())
            {
                cout << "      " << file[i].getId() << "     " << file[i].getName() << endl;
            }
        }
        
        cout << "2. " << second << endl;
        for (int i = 0; i < number_of_data; i++)
        {
            if (second == file[i].getscore())
            {
                cout << "      " << file[i].getId() << "     " << file[i].getName() << endl;
            }
        }
      
        cout << "3. " << third << endl;
        for (int i = 0; i < number_of_data; i++)
        {
            if (third == file[i].getscore())
            {
                cout << "      " << file[i].getId() << "     " << file[i].getName() << endl;
            }
        }
       
    
}

void allclass(student* file, student* file2, student* file3, int number_of_data, int number_of_data2, int number_of_data3, course cour1, course cour2, course cour3)
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
    bool file2nd = false;
    bool file3rd = false;
    for (int i = 0; i < number_of_data; i++)
    {
        // checks 2nd array for students
        for (int j = 0; j < number_of_data2; j++)
        {
            if (file[i].getName() == file2[j].getName())
            {
                file2nd = true;
            }
        }
        // checks third array
        for (int k = 0; k < number_of_data3; k++)
        {
            if(file[i].getName() == file3[k].getName())
            {
                file3rd = true;
            }
        }
        if ((file2nd == true) && (file3rd == true))
        {
            same[i].setname(file[i].getName());
            same[i].setId(file[i].getId());
            samestudent++;
            file2nd = false;
            file3rd = false;
        }
    }
    //Displays all sutdents
    cout << "There are " << samestudent << " students who take all courses" << endl;
    cout << "---------------------------------------------------------";
    for (int i = 0; i < samestudent; i++)
    {
        cout << same[i].getId() << "  " << same[i].getName() << endl;
    }
}

void classlist(student* file, int number_of_data, course& filecou)
{
    cout << "Course:" << filecou.courname << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < number_of_data; i++)
    {
            cout << file[i].getId() << "    " << file[i].getName() << "        " << file[i].getscore() << endl;
    }
    cout << "======================" << endl;
    
}
student* accessfile(char filename[20], int& number_of_data, course& filecour)
{
    student* file;

    file = new student[number_of_data];
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
        
        file[i].setId(idfile);
        file[i].setname(namefile);
        file[i].setscore(scorefile);
        
        i++;
    }
    number_of_data = i;
    

    return file;
}
