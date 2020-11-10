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
        int choice;
        cin >> choice;
        cin.ignore();
        switch(choice)
        {
            case 1:
            {
                teacher professor;
                professor.login();
                break;
            }
            case 2:
            {
                access stu;
                stu.student_command();
                break;
            }
            case 3:
            {
                return 0;
            }
            default:
                cout << "Invalid input. Please try again.\n\n";
                continue;
        }
    }
    while(true);
}