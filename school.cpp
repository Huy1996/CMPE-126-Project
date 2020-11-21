#include "school.h"
//===================Addtional function===========================//
string format_title()
{
    string to_print = "First           Last      ID      HW    Quiz    Mid    Final    Average";
    return to_print;
}

bool isNumber (const string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int getNumber()
{
    string input;
    int to_return;
    do
    {
        getline(cin, input);
        if(isNumber(input))
        {
            to_return = stoi(input);
            break;
        }
        cout << "\nInvalid input. Please enter a number.\n";
        cout << "Please re-enter the number: ";
    }
    while(true);
    return to_return;
}

string choose_semeter()
{
    string file_name;
    bool run = true;
    do
    {
        cout << "\nChoose your semester.\n";
        cout << "(1) Spring.         (2) Summer.           (3) Fall." << endl;
        cout << "Your choice: ";
        int choice;
        choice = getNumber();
        switch (choice)
        {
            case 1:
                file_name = "Spring ";
                run = false;
                break;
            case 2:
                file_name = "Summer ";
                run = false;
                break;
            case 3:
                file_name = "Fall ";
                run = false;
                break;
            default:
                cout << "Invalid input.\n";
        }
    }
    while(run);
    cout << "Enter year: ";
    string choice;
    getline(cin, choice);
    file_name = file_name + choice + ".txt";
    return file_name;
}

//================================================================//
//                      student class                             //
//================================================================//
student::student()
{
    first = "";
    last = "";
    student_id = hw = quiz = midterm = final = average = 0;

}

student::student(string firstname, string lastname, unsigned id)
{
    first = firstname;
    last = lastname;
    student_id = id;
    hw = quiz = midterm = final = average = 0;
}

student::~student() = default;

void student::input_score(unsigned quiz_score, unsigned hw_score, unsigned midterm_score, unsigned final_score)
{
    hw = hw_score;
    quiz = quiz_score;
    midterm = midterm_score;
    final = final_score;
    calculate_average();
}

void student::calculate_average()
{
    average = hw*0.1 + quiz*0.2 + midterm*0.3 + final*0.4;
}

string student::get_first()
{
    return first;
}

string student::get_last()
{
    return last;
}

unsigned student::get_id()
{
    return student_id;
}

void student::input_hw(unsigned score)
{
    hw = score;
    calculate_average();
}

void student::input_quiz(unsigned score)
{
    quiz = score;
    calculate_average();
}

void student::input_midterm(unsigned score)
{
    midterm = score;
    calculate_average();
}

void student::input_final(unsigned score)
{
    final = score;
    calculate_average();
}

ostream &operator << (ostream &stream, const student &RHS)
{
    stream << left
           << setw(16) <<RHS.first
           << setw(10)<< RHS.last
           << setw(8)<< RHS.student_id
           << setw(6)<< RHS.hw
           << setw(8)<< RHS.quiz
           << setw(7)<< RHS.midterm
           << setw(9)<< RHS.final
           << RHS.average << endl;
    return stream;
}
//================================================================//
//                      node class                              //
//================================================================//
node::node(student input)
{
    data = input;
    next = nullptr;
    previous = nullptr;
}

node::~node() = default;



//================================================================//
//                      access class                              //
//================================================================//
access::access()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
    current = nullptr;
}

access::~access()
{
    current = head;
    node *delete_node;
    while(current)
    {
        delete_node = current;
        current = current->next;
        delete delete_node;
    }
    head = nullptr;
    tail = nullptr;
    current = nullptr;
    length = 0;
}

void access::append(node *input)
{
    if(head == nullptr)
    {
        head = input;
        tail = head;
        current = head;
    }
    else
    {
        input->previous = tail;
        tail->next = input;
        tail = input;
    }
    length++;
}

void access::delete_student()
{
    if(head == current && length == 1)
    {
        node *to_delete = head;
        head = nullptr;
        tail = nullptr;
        current = nullptr;
        delete to_delete;
    }
    else if(head == current)
    {
        node *to_delete = current;
        head = head->next;
        head->previous = nullptr;
        current = head;
        delete to_delete;
    }
    else if(current == tail)
    {
        node *to_delete = current;
        tail = tail->previous;
        tail->next = nullptr;
        current = head;
        delete to_delete;
    }
    else
    {
        node *delete_node = current;
        current = current->previous;
        current->next = current->next->next;
        current->next->previous = current;
        delete delete_node;
        current = head;
    }
    length--;
}

void access::clear_list()
{
    current = head;
    while(current)
        delete_student();
}

bool access::find(string first_name, unsigned id)
{
    current = head;
    while(current)
    {
        if(current->data.get_first() == first_name && current->data.get_id() == id)
            return true;
        current= current->next;
    }
    cout << "Cannot find student.\n";
    return false;
}

bool access::find(string first_name, string last_name)
{
    current = head;
    while(current)
    {
        if(current->data.get_first() == first_name && current->data.get_last() == last_name)
            return true;
        current= current->next;
    }
    cout << "Cannot find student.\n";
    return false;
}

int access::get_length()
{
    return length;
}

void access::read_from_file()
{
    string temp;
    ifstream ifs;
    ifs.open(file_name);

    for(int i = 0; i < 5; i++)
        getline(ifs, temp);
    string first, last;
    unsigned id, hw, quiz, mid, final, average;
    while(ifs >> first)
    {
        ifs >> last;
        ifs >> id;
        ifs >> hw;
        ifs >> quiz;
        ifs >> mid;
        ifs >> final;
        ifs >> average;
        student data(first, last, id);
        data.input_score(quiz, hw, mid, final);
        node *input = new node(data);
        append(input);
    }
    ifs.close();
    sort();
}

void access::create_class()
{
    cout << "\nAdd student.\n";
    string first, last;
    unsigned id;
    do
    {
        cout << "\nEnter student first name: ";
        getline(cin, first);
        cout << "Enter student last name: ";
        getline(cin, last);
        cout << "Enter student ID: ";
        cin >> id;
        cin.ignore();
        student data(first, last, id);
        node *input = new node(data);
        append(input);
        cout << "\nAdd another student?\n(1) Yes.\n(Other). No\n";
        string choice;
        cout << "Your choice: ";
        getline(cin, choice);
        if(choice != "1")
            break;
    }
    while(true);
    sort();
}



void access::input_grade()
{
    cout << "Which grade do you want to input?\n";
    cout << "(1)Homeword.     (2)Quiz.      (3)Midterm.     (4)Final.     (other)Exit.\n";
    cout << "Your choice: ";
    int choice;
    choice = getNumber();
    if (choice < 1 || choice > 4)
        return;
    current = head;
    while (current) {
        int grade;
        cout << current->data.get_last() << ", " << current->data.get_first() << ": ";
        cin >> grade;
        cin.ignore();
        switch (choice)
        {
            case 1:
                current->data.input_hw(grade);
                break;
            case 2:
                current->data.input_quiz(grade);
                break;
            case 3:
                current->data.input_midterm(grade);
                break;
            case 4:
                current->data.input_final(grade);
                break;
        }
        current = current->next;
    }
    cout << "\nAll student got their score.\n";
}

void access::edit_grade()
{
    do
    {
        string fn, ln;
        cout << "\nEnter student first name: ";
        getline(cin, fn);
        cout << "Enter student last name: ";
        getline(cin, ln);
        bool found = find(fn, ln);
        if(found)
        {
            int hw, quiz, mid, final;
            cout << current->data << endl;
            cout << "Input student grade. (Enter the same grade if nothing change)\n";
            cout << "Homeword: ";
            hw = getNumber();
            cout << "Quiz: ";
            quiz = getNumber();
            cout << "Midterm: ";
            mid = getNumber();
            cout << "Final: ";
            final = getNumber();
            current->data.input_score(quiz, hw, mid, final);
        }
        cout << "\nDo you want to edit another student? (Enter 1 to exit): ";
        int exit = getNumber();
        if (exit == 1)
            break;
    }
    while(true);
}

void access::drop()
{
    string fn, ln;
    cout << "\nEnter student first name: ";
    getline(cin, fn);
    cout << "Enter student last name: ";
    getline(cin, ln);
    bool found = find(fn, ln);
    if(found)
    {
        delete_student();
        cout << fn << " are being dropped.\n";
    }
}

void access::swap(node *x, node *y)
{
    student temp = x->data;
    x->data = y->data;
    y->data = temp;
}

void access::sort()
{
    node *x, *y;
    x=head;
    while(x->next)
    {
        y = x->next;
        while(y)
        {
            if(strcmp(x->data.get_first().c_str(), y->data.get_first().c_str()) > 0)
                swap(x,y);
            y=y->next;
        }
        x=x->next;
    }
}

void access::access_class() {
    do {
        int choice;
        cout << "\nWhat do you want to do with this class?\n";
        cout << "(1) Input grade. (Input grade for the whole class)\n";
        cout << "(2) Edit grade. (Specific student)\n";
        cout << "(3) Add student.\n";
        cout << "(4) Drop student.\n";
        cout << "(5) Print student list.\n";
        cout << "(6) Exit class.\n";
        cout << "Your choice: ";
        choice = getNumber();
        cout << endl;
        if (choice == 1)
            input_grade();
        else if (choice == 2)
            edit_grade();
        else if (choice == 3)
            create_class();
        else if (choice == 4)
            drop();
        else if (choice == 5)
            {
                print();
                cout<<"\nPress [Enter] to continue . . .";
                getchar();
            }
        else if (choice == 6)
            break;
        else {
            cout << "Invalid input.\n";
            continue;
        }
    } while (true);
    string choose;
    cout << "\nSave before exit?\n(1) Yes.\n(Other). No\n";
    cout << "Your choice: ";
    getline(cin, choose);
    if (choose == "1")
        write_to_file();
    clear_list();
}

void access::teacher_access()
{
    do
    {
        cout << "\nWhat do you want to do?\n";
        cout << "(1) Open exist class.\n";
        cout << "(2) Create class.\n";
        cout << "(3) Back to teacher homepage.\n";
        cout << "Your choice: ";
        int choose = getNumber();
        cout << endl;
        if(choose ==  1)
        {
            file_name = choose_semeter();
            read_from_file();
            access_class();
        }
        else if(choose == 2)
        {
            file_name = choose_semeter();
            create_class();
            access_class();
        }
        else if(choose == 3)
            break;
        else
            cout << "Invalid input. Please try again.\n";
    }
    while(true);
}

void access::write_to_file()
{
    ofstream write(file_name);
    write << "Semeter: " << file_name.substr(0, file_name.find(" ")) << endl;
    write << "Year: " << file_name.substr(file_name.find(" ")+1, 4) << endl;
    write << "________________________________________________________________________\n";
    write << format_title() << endl;
    write << "------------------------------------------------------------------------\n";
    current = head;
    while(current)
    {
        write << current->data;
        current = current->next;
    }
    write.close();
}

void access::student_command()
{
    file_name = choose_semeter();
    read_from_file();
    string fn;
    unsigned id;
    cout << "\nEnter your first name: ";
    getline(cin, fn);
    cout << "Enter your student ID: ";
    id = getNumber();
    bool found = find(fn, id);
    if(!found)
        cout << "Student are not exist.\n";
    else
    {
        cout << endl;
        print_student();
        cout << endl;
    }
}

void access::print()
{
    cout << format_title() << endl;
    current = head;
    while(current)
    {
        cout << current->data;
        current=current->next;
    }
}

void access::print_student()
{
    string to_print = format_title();
    cout << to_print << endl;
    cout << current->data;
}
//================================================================//
//                      teacher_node class                        //
//================================================================//
teacher_node::teacher_node(string name, string pass)
{
    username = name;
    password = pass;
    next = nullptr;
}

teacher_node::~teacher_node() = default;


//================================================================//
//                      teacher class                             //
//================================================================//

teacher::teacher()
{
    head = nullptr;
    tail = nullptr;
    current = nullptr;
    valid = true;
}

teacher::~teacher()
{
    current = head;
    teacher_node *delete_node;
    while(current)
    {
        delete_node = current;
        current = current->next;
        delete delete_node;
    }
    head = nullptr;
    tail = nullptr;
    current = nullptr;
}

void teacher::append(teacher_node *input)
{
    if (head == nullptr){
        head = input;
        current = head;
        tail = input;
    }
    else {
        tail->next = input;
        tail = input;
    }
}

void teacher::create_list()
{
    string user, pass;
    ifstream ifs("admin.txt");
    for(int i = 0; i < 4; i++)
        getline(ifs, user);

    while(ifs >> user)
    {
        ifs >> pass;
        teacher_node *input = new teacher_node(user, pass);
        append(input);
    }
    ifs.close();
}

bool teacher::find(string user, string pass)
{
    current = head;
    while(current)
    {
        if(current->username == user)
        {
            if(current->password == pass)
            {
                cout << "Login successful.\n";
                return true;
            }
            cout << "Incorrect username or password.\n";
            return false;
        }
        current = current->next;
    }
    cout << "Incorrect username or password.\n";
    return false;
}

bool teacher::login()
{
    create_list();
    bool exit = false;
    string username, password;
    static int i = 0;
    do
    {
        for(i; i < 3; i++)
        {
            cout << "\nEnter username: ";
            getline(cin, username);

            cout << "Enter password: ";
            getline(cin, password);

            bool allow_access = find(username, password);
            if (allow_access)
            {
                i = 0;
                teacher_command();
                break;
            }
            else if(i == 2)
            {
                cout << "Professor page are being locked.\n";
                return false;
            }
            
            cout << "\nLog in again? (Enter 1 to retry.): ";
            int choose = getNumber();
            if(choose != 1)
            {
                i++;
                break;
            }
        }
        int choice;
        if(!valid)
            return false;
        cout << "\nDo you want to go back to homepage?\n";
        cout << "(1) Yes.\n(other) No.\n";
        cout << "Your choice is: ";
        choice = getNumber();
        if(choice == 1)
            exit = true;
        cout << endl;
    }
    while(!exit);
    return true;
}

void teacher::change_password()
{
    for(int i = 0; i < 3; i++)
    {
        string current_pass;
        string pass1st;
        string pass2nd;
        cout << "\nEnter your password: ";
        getline(cin, current_pass);
        cout << "Enter new password: ";
        getline(cin, pass1st);
        cout << "Re-enter new password: ";
        getline(cin, pass2nd);
        if(current_pass == current->password)
        {
            if(pass1st == pass2nd)
            {
                current->password = pass1st;
                save();
                cout << "Password changed successful.\n";
                return;
            }
            else
            {
                cout << "New password should be the same.\n";
                i--;
                continue;
            }
        }
        else if(i != 2)
            cout << "Wrong password.\n";
    }
    cout << "Wrong password so many times.\nProfessor page are being locked for security purpose.\n";
    valid = false;
}

void teacher::save()
{
    ofstream file;
    file.open("admin.txt");
    file << "PROFESSOR ACCOUNT LIST\n";
    file << "#############################\n";
    file << left << setw(20) << "USER_ID" << "PASSWORD" << endl;
    file << "#############################\n";
    teacher_node *run;
    run = head;
    while(run)
    {
        file << setw(20) << run->username << run->password << endl;
        run = run->next;
    }
    file.close();
}

void teacher::teacher_command()
{
    do
    {
        if(!valid)
            return;
        cout << "\nWhat do you want to do?\n";
        cout << "(1) Change password.\n" << "(2) Access class.\n" <<  "(3) Log out" << endl;
        cout << "Your choice: ";
        string choice;
        getline(cin, choice);
        if(choice == "1")
            change_password();
        else if(choice == "2")
        {
            teacher_access();
        }
        else if(choice == "3")
        {
            cout << "Log out successful.\n";
            break;
        }
        else
            cout << "Invalid input. Please try again.\n";
    }
    while(true);
}