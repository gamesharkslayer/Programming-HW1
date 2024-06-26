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
  
private:
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
void allclass(student* file, student* file2, int number_of_data, int number_of_data2, course cour1, course cour2);
void twoclass(student* file, student* file2, student* file3, int number_of_data, int number_of_data2, int number_of_data3, course cour1, course cour2, course cour3);
void twoclass(student* file, student* file2, int number_of_data, int number_of_data2, course cour1, course cour2);
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
    //Decision based on the number of courses
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
    // Menu loop
    int menunum = 0;
    while (!(menunum == 5))
    {
        cout << "===== Menu ========" << endl;
        cout << "1. Show all course lists" << endl;
        cout << "2. list of students who take all courses" << endl;
        cout << "3. list of student who take two courses" << endl;
        cout << "4. Print out top three scores for each course" << endl;
        cout << "5. Exit program" << endl;
        cout << "---> select: ";
        cin >> menunum;
        // A decision tree that selects which menu to open
        //show all courses
        if (menunum == 1)
        {
            //Additional decision for different amount of courses
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
        // list of students who take all courses
        if (menunum == 2)
        {
            if (numberofcourses == 1)
            {
                classlist(file1, number_of_data, courfile1);
            }
            if (numberofcourses == 2)
            {
                allclass(file1, file2, number_of_data, number_of_data2, courfile1, courfile2);
            }
            if (numberofcourses == 3) 
            {
               allclass(file1, file2, file3, number_of_data, number_of_data2, number_of_data3, courfile1, courfile2, courfile3);
            }
        }
        // list of students who only take two courses
        if (menunum == 3)
        {
            if (numberofcourses == 1)
            {
                classlist(file1, number_of_data, courfile1);
            }
            if (numberofcourses == 2)
            {
                twoclass(file1, file2, number_of_data, number_of_data2, courfile1, courfile2);
            }
            if (numberofcourses == 3)
            {
              twoclass(file1, file2, file3, number_of_data, number_of_data2, number_of_data3, courfile1, courfile2, courfile3);
            }
        }
        // displays top three scores for each classes
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
/*
* default Constructor that constructs a empty space for a student
*/
student::student()
{
    id = 100;
    score = 100;
    name = "empty";
  
}
/*
* Constructor that constructs a student class
*/
student::student(int i, string n, int s)
{
    id = i;
    score = s;
    name = n;
}
//Sets the score based on parameter
void student::setscore(int s)
{
    score = s;
}
//Sets the Student ID based on parameter
void student::setId(int i)
{
    id = i;
}
//Sets the Student Name based on parameter
void student::setname(string n)
{
    name = n;
}
//Returns the value of the Student ID
int student::getId()
{
    return id;
}
//Returns the string student name
string student::getName()
{
    return name;
}
//Returns the test score
int student::getscore()
{
    return score;
}
/*
* Parses through the student class to find the top three scores and prints out the students names id and scores
*/
void topscores(student* file, int number_of_data, course cour)
{
    
    int first=3, second=2, third=1;
    //For loop that searches for the highest score in the class
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
/*
* Displays students that have taken all classes
*/
void allclass(student* file, student* file2, student* file3, int number_of_data, int number_of_data2, int number_of_data3, course cour1, course cour2, course cour3)
{
     
    int samestudent = 0;
    //boolean values to check if there is an student that is the same
    bool file2nd = false;
    bool file3rd = false;
   
    for (int i = 0; i < number_of_data; i++)
    {
        // checks 2nd array for students
        for (int j = 0; j < number_of_data2; j++)
        {
            if ((file[i].getName() == file2[j].getName()) && (file[i].getId() == file2[j].getId()))
            {
                file2nd = true;
                for (int k = 0; k < number_of_data3; k++)
                {
                    if ((file[i].getName() == file3[k].getName()) && (file[i].getId() == file3[k].getId()))
                    {
                        file3rd = true;
                        samestudent++;
                    }
                }
            }
            
        }
      
    }
    cout << "There are " << samestudent << " students who take all courses" << endl;
    cout << "---------------------------------------------------------" << endl;
    for (int i = 0; i < number_of_data; i++)
    {
        // checks 2nd array for students
        for (int j = 0; j < number_of_data2; j++)
        {
            if ((file[i].getName() == file2[j].getName()) && (file[i].getId() == file2[j].getId()))
            {
                file2nd = true;
                for (int k = 0; k < number_of_data3; k++)
                {
                    if ((file[i].getName() == file3[k].getName()) && (file[i].getId() == file3[k].getId()))
                    {
                        
                        cout << file[i].getId() << "  " << file[i].getName() <<" " << cour1.courname << "(" << file[i].getscore() << ") " << cour2.courname << "(" << file2[j].getscore() << ") " <<cour3.courname << "(" << file3[k].getscore() << ")" << endl;
                    }
                }
            }

        }
    }
    
}
/*
* Displays students that have taken all classes for 2 courses
*/
void allclass(student* file, student* file2, int number_of_data, int number_of_data2, course cour1, course cour2)
{
    // Counter for the amount of students
    int samestudent = 0;
   
    
    //boolean values to check if there is an student that is the same
    bool file2nd = false;
    bool file3rd = false;
    //Counts for the number of same students
    for (int i = 0; i < number_of_data; i++)
    {
        // checks 2nd array for students
        for (int j = 0; j < number_of_data2; j++)
        {
            if ((file[i].getName() == file2[j].getName()) && (file[i].getId() == file2[j].getId()))
            {
                file2nd = true;
                file3rd = true;
                samestudent++;
                    
            }
            

        }

    }
    //Outputs the students that take all courses
    cout << "There are " << samestudent << " students who take all courses" << endl;
    cout << "---------------------------------------------------------" << endl;
    for (int i = 0; i < number_of_data; i++)
    {
        // checks 2nd array for students
        for (int j = 0; j < number_of_data2; j++)
        {
            if ((file[i].getName() == file2[j].getName()) && (file[i].getId() == file2[j].getId()))
            {
                file2nd = true;
                cout << file[i].getId() << "  " << file[i].getName() << " " << cour1.courname << "(" << file[i].getscore() << ") " << cour2.courname << "(" << file2[j].getscore() << ") " << endl;
                    
                
            }

        }
    }

}


void twoclass(student* file, student* file2, student* file3, int number_of_data, int number_of_data2, int number_of_data3, course cour1, course cour2, course cour3)
{

    //counts the students take two classes
    int samestudent = 0;
    // use the biggest class
    int biggestclass = number_of_data;
    
    //boolean values to check if there is an student that is the same
    bool stucheck = false;
    bool stucheck2 = false;
    bool stucheck3 = false;
    //Checks for students that take two classes for course 1 and 2
    for (int i = 0; i < number_of_data; i++)
    {
        // checks 2nd array for students
        for (int j = 0; j < number_of_data2; j++)
        {
            if ((file[i].getName() == file2[j].getName()) && (file[i].getId() == file2[j].getId()))
            {
                stucheck = false;
                for (int k = 0; k < number_of_data3; k++)
                {
                    if (file[i].getId() == file3[k].getId())
                    {
                        stucheck = true;
                    }
                }
                if (stucheck == false)
                {
                    samestudent++;
                }
            }

        }

    }
    //checks for students that take two classes
    bool exist = false;
    // outputs the two students for course 1 and 2
    cout << "There are " << samestudent << " students who take "<< cour1.courname << " and " << cour2.courname << endl;
    cout << "---------------------------------------------------------" << endl;
    for (int i = 0; i < number_of_data; i++)
    {
        // checks 2nd array for students
        for (int j = 0; j < number_of_data2; j++)
        {
            if ((file[i].getName() == file2[j].getName()) && (file[i].getId() == file2[j].getId()))
            {
                exist = false;
                for (int k = 0; k < number_of_data3; k++)
                {
                    if ((file[i].getId() == file3[k].getId()) && (file[i].getName() == file3[k].getName()))
                    {
                        exist = true;
                        
                    }
                 
                }
                
                if (exist == false)
                {
                    cout << file[i].getId() << "  " << file[i].getName() << " " << cour1.courname << "(" << file[i].getscore() << ") " << cour2.courname << "(" << file2[j].getscore() << ") " << endl;

                }

            }

        }
    }
    //Checks for students that takes two classes for courses 1 and 3
    int samestudent2 = 0;
    for (int i = 0; i < number_of_data; i++)
    {
        // checks 2nd array for students
        for (int j = 0; j < number_of_data3; j++)
        {
            if ((file[i].getName() == file3[j].getName()) && (file[i].getId() == file3[j].getId()))
            {
                stucheck2 = false;
                for (int k = 0; k < number_of_data2; k++)
                {
                    if (file[i].getId() == file2[k].getId())
                    {

                        stucheck2 = true;
                    }
                }
                if (stucheck2 == false)
                {
                    samestudent2++;
                }
            }
        }
    }
    // outputs the students that take course 1 and 3
    cout << "There are " << samestudent2 << " students who take " << cour1.courname << " and " << cour3.courname << endl;
    cout << "---------------------------------------------------------" << endl;
    for (int i = 0; i < number_of_data; i++)
    {
        // checks 2nd array for students
        for (int j = 0; j < number_of_data3; j++)
        {
            exist = false;
            if ((file[i].getName() == file3[j].getName()) && (file[i].getId() == file3[j].getId()))
            {
                exist = false;
                for (int k = 0; k < number_of_data2 ; k++)
                {
                if ((file[i].getId() == file2[k].getId()) && (file[i].getName() == file2[k].getName()))
                {
                    exist = true;

                }
                }
                if (exist == false)
                {
                    cout << file[i].getId() << "  " << file[i].getName() << " " << cour1.courname << "(" << file[i].getscore() << ") " << cour3.courname << "(" << file3[j].getscore() << ") " << endl;

                }
            }

        }
    }
    //Checks for students take courses 2 and three
    int samestudent3 = 0;
    for (int i = 0; i < number_of_data2; i++)
    {
        // checks 2nd array for students
        for (int j = 0; j < number_of_data3; j++)
        {
            if ((file2[i].getName() == file3[j].getName()) && (file2[i].getId() == file3[j].getId()))
            {
                stucheck3 = false;
                for (int k = 0; k < number_of_data3; k++)
                {
                    if (file2[i].getId() == file[k].getId())
                    {
                        stucheck3 = true;
                    }
                }
                if (stucheck3 == false)
                {
                    samestudent3++;
                }
            }
        }
    }
    // Outputs the students that takes courses 2 and 3
    cout << "There are " << samestudent3 << " students who take " << cour2.courname << " and " << cour3.courname << endl;
    cout << "---------------------------------------------------------" << endl;
    for (int i = 0; i < number_of_data2; i++)
    {
        // checks 2nd array for students
        for (int j = 0; j < number_of_data3; j++)
        {
            if ((file2[i].getName() == file3[j].getName()) && (file2[i].getId() == file3[j].getId()))
            {
                exist = false;
                for (int k = 0; k < number_of_data; k++)
                {
                    if (file2[i].getId() == file[k].getId())
                    {
                        exist = true;

                    }
                }
                if (exist == false)
                {
                    cout << file2[i].getId() << "  " << file2[i].getName() << " " << cour2.courname << "(" << file2[i].getscore() << ") " << cour3.courname << "(" << file3[j].getscore() << ") " << endl;

                }
            }
           

        }
        
    }
    
}
//Checks for students takes two classes overload for two number of courses
void twoclass(student* file, student* file2, int number_of_data, int number_of_data2, course cour1, course cour2)
{
    // checks for students that take only twoclasses
    int samestudent = 0;
    // Checks for the amount of students that take the same class
    for (int i = 0; i < number_of_data; i++)
    {
        // checks 2nd array for students
        for (int j = 0; j < number_of_data2; j++)
        {
            if ((file[i].getName() == file2[j].getName()) && (file[i].getId() == file2[j].getId()))
            {
            samestudent++;
                
            }

        }

    }
    bool exist = false;

    //Outputs the students that take the same class
    cout << "There are " << samestudent << " students who take " << cour1.courname << " and " << cour2.courname << endl;
    cout << "---------------------------------------------------------" << endl;
    for (int i = 0; i < number_of_data; i++)
    {
        // checks 2nd array for students
        for (int j = 0; j < number_of_data2; j++)
        {
            if ((file[i].getName() == file2[j].getName()) && (file[i].getId() == file2[j].getId()))
            {
                if (exist == false)
                {
                    cout << file[i].getId() << "  " << file[i].getName() << " " << cour1.courname << "(" << file[i].getscore() << ") " << cour2.courname << "(" << file2[j].getscore() << ") " << endl;

                }

            }

        }
    }
}
//Displays the students that take the course from the file
void classlist(student* file, int number_of_data, course& filecou)
{
    //Outputs the list of students from the student array
    cout << "Course:" << filecou.courname << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < number_of_data; i++)
    {
            cout << file[i].getId() << "    " << file[i].getName() << "        " << file[i].getscore() << endl;
    }
    cout << "======================" << endl;
    
}
// Access the file and inputs data into the array
student* accessfile(char filename[20], int& number_of_data, course& filecour)
{
    //creates a new array
    student* file;
    // creates a array size from the number of data 
    file = new student[number_of_data];
    //checks if the file is opened
    ifstream infile;
    infile.open(filename);
    if (infile.fail()) { // checks for file opening
        cout << "Input file opening filed." << endl;
        exit(1);
    }
    // creates temp variables
    string tempclass;
    int temp;

    infile >> tempclass >> temp;
    // assigns the course name
    filecour.courname = tempclass;
    // keeps track of the number of loops
    int i = 0;
    // varibles to hold the id and score as well as name
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
    
    // returns the new file array
    return file;
}

