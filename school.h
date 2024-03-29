//
// Created by minhh on 10/29/2020.
//

#ifndef CMPE_126_SCHOOL_H
#define CMPE_126_SCHOOL_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <sstream>

using namespace std;

class student{
private:
    unsigned hw, quiz, midterm, final, average;
    unsigned student_id;
    string first, last;
public:
    student();
    student(string firstname, string lastname, unsigned id);
    virtual ~student();
    string get_first();
    string get_last();
    unsigned get_id();
    void input_score(unsigned quiz_score, unsigned hw_score, unsigned midterm_score, unsigned final_score);
    void calculate_average();
    void input_hw(unsigned score);
    void input_quiz(unsigned score);
    void input_midterm(unsigned score);
    void input_final(unsigned score);
    friend ostream& operator << (ostream &stream, const student &a);
};


class node{
public:
    node *next, *previous;
    student data;
    node(student input);
    ~node();
};


class access{
private:
    node *head;
    node *tail;
    node *current;
    int length;
    string file_name;
    void append(node *input);
    void create_class();
    void delete_student();
    void clear_list();
    void input_grade();
    void edit_grade();
    void drop();
    void swap(node *x, node *y);
    void sort();
    void read_from_file();
    void write_to_file();
    int get_length();
    void print();
    void print_student();
    void access_class();
    bool find(string first_name, unsigned id);
    bool find(string first_name, string last_name);

protected:
    void teacher_access();

public:
    access();
    ~access();
    void student_command();
};

class teacher_node{
public:
    string username;
    string password;
    teacher_node *next;
    teacher_node(string name, string pass);
    ~teacher_node();
};

class teacher: public access{
private:
    teacher_node *head;
    teacher_node *tail;
    teacher_node *current;
    bool valid;
    void append(teacher_node *input);
    bool find(string user, string pass);
    void create_list();
    void save();
    void change_password();
    void teacher_command();

public:
    teacher();
    ~teacher();
    bool login();
};
#endif //CMPE_126_SCHOOL_H
