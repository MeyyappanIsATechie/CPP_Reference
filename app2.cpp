#include<iostream>
#include<memory>
#include<vector>

using namespace std;

class Course; // forward declare

class Student {
    string name;
    vector<shared_ptr<Course>> courses;

public:
    Student ( string name ) : name ( name ) {}

    void enroll ( shared_ptr<Course> course ) {
        courses.push_back ( course );
        }

    string get_name ( ) const {
        return name;
        }
    };


class Course {
    string title;
    vector<weak_ptr<Student>> students; // avoid circular refs

public:
    Course ( string title ) : title ( title ) {}

    void add_student ( shared_ptr<Student> student ) {
        students.push_back ( student ); // doesn't increase ref count, just observes so hat avoiding deadlock
        }

    void print_roster ( ) const {
        cout << "Course: " << title << endl;
        for ( const auto& wp : students ) {
            if ( auto sp = wp.lock ( ) ) { // check validity
                cout << " - " << sp->get_name ( ) << endl;
                }
            }
        }
    };


class University {
    vector<unique_ptr<Student>> students;
    vector<unique_ptr<Course>> courses;

public:
    Student* add_student ( const string& name ) {
        auto s = make_unique<Student> ( name );
        Student* ptr = s.get ( );
        students.push_back ( move ( s ) );
        return ptr;
        }

    Course* add_course ( const string& title ) {
        auto c = make_unique<Course> ( title );
        Course* ptr = c.get ( );
        courses.push_back ( move ( c ) );
        return ptr;
        }
    };


int main ( ) {
    University uni;

    Student* s1 = uni.add_student ( "Alice" );
    Student* s2 = uni.add_student ( "Bob" );

    Course* c1 = uni.add_course ( "Math" );
    Course* c2 = uni.add_course ( "Physics" );

    auto shared_s1 = shared_ptr<Student> ( s1 , [ ] ( Student* ) { } ); // fake shared, custom deleter
    auto shared_s2 = shared_ptr<Student> ( s2 , [ ] ( Student* ) { } );

    auto shared_c1 = shared_ptr<Course> ( c1 , [ ] ( Course* ) { } );
    auto shared_c2 = shared_ptr<Course> ( c2 , [ ] ( Course* ) { } );

    s1->enroll ( shared_c1 );
    s2->enroll ( shared_c1 );
    s1->enroll ( shared_c2 );

    c1->add_student ( shared_s1 );
    c1->add_student ( shared_s2 );
    c2->add_student ( shared_s1 );

    c1->print_roster ( );
    c2->print_roster ( );

    return 0;
    }
