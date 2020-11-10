#include "school.h"
//===================Addtional function===========================//
string format_title()
{
    string to_print = "First           Last      ID      HW    Quiz    Mid    Final    Average";
    return to_print;
}



string choose_semeter()
{
    string file_name;
    cout << "\nChoose your semester.\n";
    cout << "(1) Spring." << setw(20) << "(2) Summer." << setw(20) << "(3) Fall." << endl;
    cout << "Your choice: ";
    int choice;
    cin >> choice;
    cin.ignore();
    switch (choice)
    {
        case 1:
            file_name = "Spring ";
            break;
        case 2:
            file_name = "Summer ";
            break;
        case 3:
            file_name = "Fall ";
            break;
        default:
            cout << "Invalid input.\n";
    }

    cout << "Enter year: ";
    cin >> choice;
    cin.ignore();
    file_name = file_name + to_string(choice) + ".txt";
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
    /*string to_print = RHS.first;
    to_print.resize(16);
    to_print += RHS.last;
    to_print.resize(26);
    to_print += to_string(RHS.student_id);
    to_print.resize(34);
    to_print += to_string(RHS.hw);
    to_print.resize(40);
    to_print += to_string(RHS.quiz);
    to_print.resize(48);
    to_print += to_string(RHS.midterm);
    to_print.resize(55);
    to_print += to_string(RHS.final);
    to_print.resize(64);
    to_print += to_string(RHS.average);

    stream << to_print << endl;
     */
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
    node *delete_node = current;
    current = current->previous;
    current->next = current->next->next;
    current->next->previous = current;
    delete delete_node;
    current = head;
    length--;
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
}

void access::create_class()
{
    cout << "Add student.\n";
    string first, last;
    unsigned id;
    do
    {
        cout << "Enter student first name: ";
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
        int choose;
        cout << "Your choice: ";
        cin >> choose;
        cin.ignore();
        if(choose != 1)
            break;
    }
    while(true);
}



void access::input_grade()
{
    cout << "Which grade do you want to input?\n";
    cout << "(1)Homeword.     (2)Quiz.      (3)Midterm.     (4)Final.     (other)Exit.\n";
    cout << "Your choice: ";
    int i;
    cin >> i;
    cin.ignore();
    if(i < 1 || i > 4)
        return;
    current = head;
    while(current)
    {
        int grade;
        cout << current->data.get_last() << ", " << current->data.get_first() << ": ";
        cin >> grade;
        cin.ignore();
        switch(i)
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
        if(!found)
            cout << "Student are not exist.\n";
        else
        {
            int hw, quiz, mid, final;
            cout << current->data << endl;
            cout << "Input student grade. (Enter the same grade if nothing change)\n";
            cout << "Homeword: ";
            cin >> hw;
            cin.ignore();
            cout << "Quiz: ";
            cin >> quiz;
            cin.ignore();
            cout << "Midterm: ";
            cin >> mid;
            cin.ignore();
            cout << "Final: ";
            cin >> final;
            cin.ignore();
            current->data.input_score(quiz, hw, mid, final);
        }
        cout << "Do you want to edit another student?(input 1 to exit): ";
        int exit;
        cin >> exit;
        cin.ignore();
        if (exit == 1)
            break;
    }
    while(true);
}

void access::access_class()
{
    bool run = true;
    do
    {
        int choose;
        cout << "\nWhat do you want to do with this class?\n";
        cout << "(1) Input grade. (Input grade for the whole class)\n";
        cout << "(2) Edit grade. (Specific student)\n";
        cout << "(3) Add student.\n";
        cout << "(4) Drop student.\n";
        cout << "(5) Print student list.\n";
        cout << "(6) Exit class.\n";
        cout << "Your choice: ";
        cin >> choose;
        cin.ignore();
        cout << endl;
        switch(choose)
        {
            case 1:
                input_grade();
                break;
            case 2:
                edit_grade();
                break;
            case 3:
                create_class();
                break;
            case 4:
            {
                string first, last;
                cout << "Enter student first name: ";
                getline(cin, first);
                cout << "Enter student last name: ";
                getline(cin, last);
                find(first, last);
                delete_student();
                break;
            }
            case 5:
                print();
                break;
            case 6:
                run = false;
                break;
            default:
                cout << "Invalid input.\n";
                continue;
        }
    }
    while(run);
    int choose;
    cout << "\nSave before exit?\n(1) Yes.\n(Other). No\n";
    cout << "Your choice: ";
    cin >> choose;
    cin.ignore();
    if(choose == 1)
        write_to_file();
}

void access::teacher_command()
{
    bool exit_class = false;
    do
    {
        cout << "\nWhat do you want to do?\n";
        cout << "(1) Open exist class.\n";
        cout << "(2) Create class.\n";
        cout << "(3) Back to teacher homepage.\n";
        cout << "Your choice: ";
        int choose;
        cin >> choose;
        cin.ignore();

        switch (choose)
        {
            case 1:
                file_name = choose_semeter();
                read_from_file();
                access_class();
                break;
            case 2:
            {
                file_name = choose_semeter();
                create_class();
                access_class();
                break;
            }
            case 3:
                exit_class = true;
                break;
            default:
                cout << "Invalid input. Please try again.\n";
                continue;
        }
    }
    while(!exit_class);
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
    string ln;
    cout << "\nEnter your first name: ";
    getline(cin, fn);
    cout << "Enter your last name: ";
    getline(cin, ln);
    bool found = find(fn, ln);
    if(!found)
        cout << "Student are not exist.\n";
    else
        print_student();
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

void teacher::login()
{
    create_list();
    bool exit = false;
    string username, password;
    do
    {
        cout << "\nEnter username: ";
        getline(cin, username);
        //cin.ignore();

        cout << "Enter password: ";
        getline(cin, password);
        //cin.ignore();


        bool allow_access = find(username, password);
        if(allow_access)
            teacher_command();
        else
            current = head;
        int choice;
        cout << "\nDo you want to go back to homepage?\n";
        cout << "(1) Yes.\n(other) No.\n";
        cout << "Your choice is: ";
        cin >> choice;
        cin.clear();
        cin.ignore();
        if(choice == 1)
            exit = true;
        cout << endl;
    }
    while(!exit);
}

void teacher::change_password()
{
    cout << "\nEnter new password: ";
    string pass;
    getline(cin, pass);
    current->password = pass;
    cout << "Password change successful.\n";
}

void teacher::teacher_command()
{
    bool log_out = false;
    do
    {
        cout << "\nWhat do you want to do?\n";
        cout << "(1) Change password.\n" << "(2) Access class.\n" <<  "(other) Log out" << endl;
        cout << "Your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        switch(choice)
        {
            case 1:
                change_password();
                break;
            case 2:
            {
                access course;
                course.teacher_command();
                break;
            }
            default:
                log_out = true;
                cout << "Log out successful.\n";
        }
    }
    while(!log_out);
}