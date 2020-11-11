//
// Created by minhh on 10/29/2020.
//
#include "school.h"


int main() {
    cout << "Nguyen Minh Huy Duong\n";
    cout << "014701349\n";
    bool valid = true;
    do
    {
        cout << "\nWhich page do you want to access?\n";
        cout << "(1) Professor.\n(2) Student.\n(3) Exit.\n";
        cout << "Your choice: ";
        string choice;
        getline(cin, choice);
        if(choice == "1" && valid)
        {
            teacher professor;
            valid = professor.login();
        }
        else if(choice == "1" && !valid)
            cout << "Professor page have been locked.\n";
        else if(choice == "2")
        {
            access stu;
            stu.student_command();
        }
        else if(choice == "3")
        {
            return 0;
        }
        else
            cout << "Invalid input. Please try again.\n\n";
    }
    while(true);
}