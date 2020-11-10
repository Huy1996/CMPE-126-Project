//
// Created by minhh on 10/29/2020.
//
#include "school.h"


int main() {
    cout << "Nguyen Minh Huy Duong\n";
    cout << "014701349\n\n";
    do
    {
        cout << "Which page do you want to access?\n";
        cout << "(1) Teacher.\n(2) Student.\n(3) Exit.\n";
        cout << "Your choice: ";
        string choice;
        getline(cin, choice);
        if(choice == "1")
        {
            teacher professor;
            professor.login();
        }
        else if(choice == "2")
        {
            access stu;
            stu.student_command();
        }
        else if(choice == "3")
        {
            return 0;
        }
        cout << "Invalid input. Please try again.\n\n";
    }
    while(true);
}