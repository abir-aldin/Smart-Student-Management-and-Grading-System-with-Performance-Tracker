#include<iostream>
using namespace std;

class subject
{
public:
    string name;
    float marks;
};

struct person
{
    string name;
    int age;
};
class student : public person
{
public:
    string id;
    subject subInfo[10];
    float cgpa;
    int subject_count=0;


    float calculateGPA(float avg)
    {
        if(avg>=90 && avg<=100)
        {
            cgpa=4.00;
            return cgpa;
        }
        else if(avg>=85 && avg<90)
        {
            cgpa = 3.75;
            return cgpa;
        }
        else if(avg>=80 && avg<85)
        {
            cgpa = 3.50;
            return cgpa;
        }
        else if(avg>=75 && avg<80)
        {
            cgpa=3.25;
            return cgpa;
        }
        else if(avg>=70 && avg<75)
        {
            cgpa=3.00;
            return cgpa;
        }
        else if(avg>=65 && avg<70)
        {
            cgpa=2.75;
            return cgpa;
        }
        else if(avg>=60 && avg<65)
        {
            cgpa=2.50;
            return cgpa;
        }
        else if(avg>=50 && avg<60)
        {
            cgpa=2.25;
            return cgpa;
        }
        else if(avg<50)
        {
            cgpa=0;
            return cgpa;
        }

    }



    void displayPerformance(int subject_number)
    {
        bool status=true;
        for(int k=0; k<subject_number; k++)
        {
            if(subInfo[k].marks<50)
            {
                status=false;
                break;
            }
            else
            {
                status=true;
            }
        }
        if(status)
        {
            cout<<"\nStatus: Pass"<<endl;
        }
        else if(!status)
        {
            cout<<"\nStatus: Fail"<<endl;
        }

        bool suggestion=false;

        for(int k=0; k<subject_number; k++)
        {
            if(subInfo[k].marks<75)
            {
                suggestion=true;
            }
        }

        if(suggestion)
        {

            cout<<"Suggestion: Improve your ";

            for(int k=0; k<subject_number; k++)
            {
                if(subInfo[k].marks<75)
                {
                    cout<<subInfo[k].name<<", ";
                }
            }
            cout<<"for better CGPA"<<endl;


        }

        if(!suggestion)
        {
            for(int k=0; k<subject_number; k++)
            {
                if(subInfo[k].marks>=75)
                {
                    cout<<"Suggestion: Keep up the good work"<<endl;
                    break;
                }
            }
        }


    }

};

class department
{
public:
    string departName;
    student stuInfo[4];
    int student_count=0;

    void inputDetails(department d[],int num_department)
    {

        cin.ignore();
        for(int i=0; i<num_department; i++)
        {
            cout<<"Enter name for Department "<<i+1<<" : ";

            getline(cin,d[i].departName);

        }
        cout<<"Department added successfully!"<<endl;
    }
    void addStudent(int num_student,int select_department,department d[])
    {
        for(int i=0; i<num_student; i++)
        {
            cout<<"\n***** Student "<<i+1<<" *****"<<endl;
            cout<<"Enter name: ";
            cin>>d[select_department-1].stuInfo[i].name;
            cout<<"Enter age: ";
            cin>>d[select_department-1].stuInfo[i].age;
            cout<<"Enter Student ID: ";
            cin>>d[select_department-1].stuInfo[i].id;
        }
        cout<<"Students added successfully to "<<d[select_department-1].departName<<" Department!"<<endl;

    }

    void displayTopper()
    {
        cout<<"\n****** Topper of the Department of "<<departName<<" ******"<<endl;
        float max=INT_MIN;
        int store;
        for(int i=0; i<student_count; i++)
        {
            if(max<stuInfo[i].cgpa)
            {
                max=stuInfo[i].cgpa;
                store=i;
            }
        }
        cout<<"Topper: "<<stuInfo[store].name<<" ("<<stuInfo[store].id<<")"<<endl;
        cout<<"CGPA: "<<max<<endl;

    }

    void subjectWiseTopper(department d[],string search,int num_department)
    {

        float max=INT_MIN;

        for(int i=0; i<num_department; i++)
        {
            for(int j=0; j< d[i].student_count ; j++  )
            {
                for(int k=0; k< d[i].stuInfo[j].subject_count; k++ )
                {
                    if(search==d[i].stuInfo[j].subInfo[k].name)
                    {
                        if(max< d[i].stuInfo[j].subInfo[k].marks  )
                        {
                            max= d[i].stuInfo[j].subInfo[k].marks;
                        }
                    }
                }
            }
        }

        bool found=false;


        for(int i=0; i<num_department; i++)
        {
            for(int j=0; j< d[i].student_count ; j++  )
            {
                for(int k=0; k< d[i].stuInfo[j].subject_count; k++ )
                {
                    if(search==d[i].stuInfo[j].subInfo[k].name)
                    {

                        if(max== d[i].stuInfo[j].subInfo[k].marks )
                        {
                            found=true;

                            cout<<"\n****** Topper in "<<search<<" ******"<<endl;
                            cout<<"Department: "<<d[i].departName<<endl;
                            cout<<"Topper: "<<d[i].stuInfo[j].name<<" ("<<d[i].stuInfo[j].id<<")"<<endl;
                            cout<<"Marks: "<<max<<endl;
                            break;
                        }

                    }

                }
            }
        }

        if(!found)
        {
            cout<<"\n!!! SORRY NOT FOUND. PLEASE TRY AGAIN OPTION 6 !!!"<<endl;
        }

    }

};

int main()
{
    int option,num_department=0,select_department,num_student=0,num_subject=0;
    bool performance=false;

    department d[10];
    cout<<"Please Choose an option";

    do
    {
        cout<<endl<<"[1]. Add Department"<<endl;
        cout<<"[2]. Add students to Department"<<endl;
        cout<<"[3]. Enter Marks for Students"<<endl;
        cout<<"[4]. Display student Performances"<<endl;
        cout<<"[5]. Display Department Topper"<<endl;
        cout<<"[6]. Display Subject-wise Topper"<<endl;
        cout<<"[7]. Exit"<<endl;

        cout<<"\nEnter your choice: ";
        cin>>option;
        if(option==1)
        {
            cout<<"Enter number of Department: ";
            cin>>num_department;
            d[0].inputDetails(d,num_department);


        }
        else if(option==2)
        {
            if(num_department==0)
            {
                cout<<"\nPlease add Department first"<<endl;
                continue;
            }

            cout<<"Available Departments"<<endl;
            for(int i=0; i<num_department; i++)
            {
                cout<<"["<<i+1<<"] "<<d[i].departName<<endl;
            }
            cout<<"Input serial number of Department: ";
            cin>>select_department;
            cout<<"Enter number of students to add in "<<d[select_department-1].departName<<" : ";
            cin>>num_student;

            d[0].addStudent(num_student,select_department,d);
            d[select_department-1].student_count=num_student;

        }
        else if(option==3)
        {
            if(num_student==0 || num_department==0)
            {
                cout<<"\nYou did not add department or student. Please check ...."<<endl;
                continue;
            }

            cout<<"Select Department"<<endl;
            for(int i=0; i<num_department; i++)
            {
                cout<<"["<<i+1<<"] "<<d[i].departName<<endl;
            }
            cout<<"Input serial number of Department for Entering marks: ";
            cin>>select_department;
            cout<<"\nYou have selected Department of "<<d[select_department-1].departName<<endl<<endl;
            for(int i=0; i<d[select_department-1].student_count; i++)
            {
                cout<<"*****Entering marks for student: "<<d[select_department-1].stuInfo[i].name<<"("<<d[select_department-1].stuInfo[i].id<<")*****";
                cout<<"\nHow many subject? = ";
                cin>>num_subject;
                cout<<"\nEntering marks for "<<num_subject<<" subjects: "<<endl;
                for(int j=0; j<num_subject; j++)
                {
                    cout<<"Subject "<<j+1<<" name: ";
                    cin>>d[select_department-1].stuInfo[i].subInfo[j].name;
                    cout<<"Marks: ";
                    cin>>d[select_department-1].stuInfo[i].subInfo[j].marks;
                    cout<<endl;
                }
                d[select_department-1].stuInfo[i].subject_count=num_subject;
            }

        }
        else if(option==4)
        {
            if(num_department==0)
            {
                cout<<"\nPlease add Department first..."<<endl;
                continue;
            }
            if(num_student==0)
            {
                cout<<"\nPlease add student first..."<<endl;
                continue;
            }
            if(num_subject==0)
            {
                cout<<"\nPlease add subject and marks first..."<<endl;
                continue;
            }

            for(int i=0; i<num_department; i++)
            {
                if(d[i].student_count!=0)
                {
                    cout<<"\n******* Student Performances for the Department: "<<d[i].departName<<" *******";
                    for(int j=0; j<d[i].student_count; j++)
                    {
                        cout<<"\n\nStudent: "<<d[i].stuInfo[j].name<<"("<<d[i].stuInfo[j].id<<")"<<endl;
                        cout<<"Age: "<<d[i].stuInfo[j].age<<endl;
                        float total = 0;


                        for(int k=0; k<d[i].stuInfo[j].subject_count; k++)
                        {
                            if(d[i].stuInfo[j].subject_count!=0)
                            {
                                cout<<"Subject "<<k+1<<" : "<<d[i].stuInfo[j].subInfo[k].name<<" = "<<d[i].stuInfo[j].subInfo[k].marks <<endl;
                                total=total+d[i].stuInfo[j].subInfo[k].marks;
                            }

                        }
                        float avg = total/d[i].stuInfo[j].subject_count;
                        cout<<"CGPA: "<<d[i].stuInfo[j].calculateGPA(avg);
                        d[i].stuInfo[j].displayPerformance( d[i].stuInfo[j].subject_count );

                    }

                }


            }

            performance=true;

        }


        else if(option==5)
        {
            if(num_department==0)
            {
                cout<<"\nPlease add Department first..."<<endl;
                continue;
            }
            if(num_student==0)
            {
                cout<<"\nPlease add student first..."<<endl;
                continue;
            }
            if(num_subject==0)
            {
                cout<<"\nPlease add subject and marks first..."<<endl;
                continue;
            }
            if(!performance)
            {
                cout<<"\nYou did not calculate CGPA!!! For calculate please choose option 4 before choosing 5"<<endl;
            }

            for(int i=0; i<num_department; i++)
            {
                if(d[i].student_count!=0)
                {
                    d[i].displayTopper();
                }
            }
        }

        else if(option==6)
        {
            if(num_department==0)
            {
                cout<<"\nPlease add Department first..."<<endl;
                continue;
            }
            if(num_student==0)
            {
                cout<<"\nPlease add student first..."<<endl;
                continue;
            }
            if(num_subject==0)
            {
                cout<<"\nPlease add subject and marks first..."<<endl;
                continue;
            }
            if(!performance)
            {
                cout<<"\nYou did not calculate CGPA!!! For calculate please choose option 4 before choosing 6"<<endl;
            }


            cout<<"Enter subject name to find topper (subject name must be case-sensitive): ";
            string search;
            cin>>search;
            for(int i=0; i<search.length(); i++)
            {
                search[i]=toupper(search[i]);
            }
            for(int i=0; i<num_department; i++)
            {
                for(int j=0; j< d[i].student_count ; j++ )
                {
                    for(int k=0; k< d[i].stuInfo[j].subject_count; k++ )
                    {
                        for(int l=0; l< d[i].stuInfo[j].subInfo[k].name.length(); l++)
                        {
                            d[i].stuInfo[j].subInfo[k].name[l]=toupper(d[i].stuInfo[j].subInfo[k].name[l]);
                        }
                    }



                }


            }

            d[0].subjectWiseTopper(d,search,num_department);
        }


        else if(option==7)
        {
            cout<<"\nThank you for using the student Performance system!"<<endl;
        }
        else
        {
            cout<<"\n!!! INVALID Option !!! Please Try Again"<<endl;
        }


    }
    while(option!=7);

    return 0;
}


