#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<iomanip>
#include<string>
#include<cstdio>

int cnt = 1;

struct Student {
	char s [ 50 ];
	int rno;
	char course [ 50 ];
	float grade;
	};

using namespace std;

void log ( const string& action ) {
	ofstream logFile ( "../log.txt" , ios::app );
	logFile << action << endl;
	}


void add ( ) {
	Student s;
	cout << "Enter Name: ";
	cin.ignore ( );
	cin.getline ( s.s , 50 );
	cout << "Enter Roll No: ";
	cin >> s.rno;
	cout << "Enter Course: ";
	cin.ignore ( );
	cin.getline ( s.course , 50 );
	cout << "Enter Grade: ";
	cin >> s.grade;
	ofstream fp { "../example.bin", ios::binary | ios::app };
	fp.write ( (char*) & s , sizeof ( s ) );

	ostringstream oss;
	oss << "student " << ( cnt++ ) << " details: " << s.s << " " << s.rno << " " << s.course << " " << s.grade << endl;
	log ( oss.str ( ) );
	}

void viewAll ( ) {
	ifstream file ( "../example.bin" , ios::binary );
	Student s;

	ostringstream oss;
	oss << left << setw ( 20 ) << "Name" << setw ( 10 ) << "Roll No" << setw ( 15 ) << "Course" << setw ( 10 ) << "Grade" << "\n";
	oss << string ( 55 , '-' ) << "\n";

	while ( file.read ( ( char* ) &s , sizeof ( s ) ) ) {
		oss << left << setw ( 20 ) << s.s << setw ( 10 ) << s.rno << setw ( 15 ) << s.course << setw ( 10 ) << s.grade << "\n";
		}

	cout << oss.str ( );

	ostringstream loss;
	loss << "student list viewed." << endl;
	log ( loss.str ( ) );
	}

void search ( ) {
	int roll;
	cout << "Enter Roll Number to search: ";
	cin >> roll;

	ifstream file ( "../example.bin" , ios::binary );
	Student s;
	bool found = false;

	while ( file.read ( ( char* ) &s , sizeof ( s ) ) ) {
		if ( s.rno== roll ) {
			cout << "Record Found:\n";
			cout << "Name: " << s.s << "\nRoll No: " << s.rno << "\nCourse: " << s.course << "\nGrade: " << s.grade << endl;
			ostringstream oss;
			oss << "student with roll no "<<roll<<" was searched." << endl;
			log ( oss.str ( ) );
			found = true;
			break;
			}
		}

	if ( !found ) {
		ostringstream oss;
		oss << "student with roll "<<roll<<" search was unsuccessful." << endl;
		log ( oss.str ( ) );
		cout << "Record not found.\n";

		}
	}

void update ( ) {
	int roll;
	cout << "Enter Roll Number to update: ";
	cin >> roll;

	fstream file ( "../example.bin" , ios::binary | ios::in | ios::out );
	Student s;
	bool found = false;

	while ( file.read ( ( char* ) &s , sizeof ( s ) ) ) {
		if ( s.rno == roll ) {
			cout << "Enter new details:\n";
			cout << "Enter Name: ";
			cin.ignore ( );
			cin.getline ( s.s , 50 );
			cout << "Enter Course: ";
			cin.getline ( s.course , 50 );
			cout << "Enter Grade: ";
			cin >> s.grade;

			file.seekp ( -1*sizeof ( s ) , ios::cur );
			file.write ( ( char* ) &s , sizeof ( s ) );
			cout << "Record updated.\n";
			ostringstream oss;
			oss << "student with roll " << roll << " update was successful." << endl;
			log ( oss.str ( ) );
			found = true;
			break;
			}
		}

	if ( !found ) {
		cout << "Record not found.\n";
		ostringstream oss;
		oss << "student with roll " << roll << " search was unsuccessful." << endl;
		log ( oss.str ( ) );
		}
	}

void deletes ( ) {
	int roll;
	cout << "Enter Roll Number to delete: ";
	cin >> roll;

	ifstream file ( "../example.bin" , ios::binary );
	ofstream temp ( "../temp.dat" , ios::binary );
	Student s;
	bool found = false;

	while ( file.read ( ( char* ) &s , sizeof ( s ) ) ) {
		if ( s.rno == roll ) {
			found = true;
			ostringstream oss;
			oss << "Deleted: " << s.s << ", Roll No: " << s.rno;
			log ( oss.str ( ) );
			continue;
			}
		temp.write ( ( char* ) &s , sizeof ( s ) );
		}

	file.close ( );
	temp.close ( );
	remove ( "../example.bin" );
	rename ( "../temp.dat" , "../example.bin" );

	if ( found ) cout << "Record deleted.\n";
	else {
		cout << "Record not found.\n";
		ostringstream oss;
		oss << "student with roll " << roll << " delete was unsuccessful." << endl;
		log ( oss.str ( ) );
		}
	}

void exports ( ) {
	ifstream file ( "../example.bin" , ios::binary );
	ofstream report ( "../report.txt" );
	Student s;

	ostringstream oss;
	oss << left << setw ( 20 ) << "Name" << setw ( 10 ) << "Roll No" << setw ( 15 ) << "Course" << setw ( 10 ) << "Grade" << "\n";
	oss << string ( 55 , '-' ) << "\n";

	while ( file.read ( ( char* ) &s , sizeof ( s ) ) ) {
		oss << left << setw ( 20 ) << s.s << setw ( 10 ) << s.rno << setw ( 15 ) << s.course << setw ( 10 ) << s.grade << "\n";
		}

	report << oss.str ( );
	cout << "Data exported to report.txt\n";
	}

void backup ( ) {
	ifstream src ( "../example.bin" , ios::binary );
	ofstream dest ( "../backup.dat" , ios::binary );
	dest << src.rdbuf ( );
	cout << "Backup complete.\n";
	}

void restore ( ) {
	 ifstream src("../backup.dat", ios::binary);
    ofstream dest("../example.bin", ios::binary);
    dest << src.rdbuf();
    cout << "Data restored from backup.\n";
	}

int main ( ) {
	int c;
	do {
		cout << "\nStudent Management System."<<endl;
		cout << "===================================="<<endl;
		cout << "1. add new student" << endl;
		cout << "2. view all students" << endl;
		cout << "3. search for student by rno" << endl;
		cout << "4. update student" << endl;
		cout << "5. delete student" << endl;
		cout << "6. export students as text report" << endl;
		cout << "7. backup and restore" << endl;
		cout << "0. exit" << endl;
		cout << "===================================="<<endl;
		cout << "enter choice: " << endl;
		cin >> c;

		switch ( c ) {
			case 1: add ( ); break;
			case 2: viewAll ( ); break;
			case 3: search ( ); break;
			case 4: update ( ); break;
			case 5: deletes ( ); break;
			case 6: exports ( ); break;
			case 7: 
			{
			int opt;
			cout << "1.backup\n 2.restore\nenter option: ";
			cin >> opt;
			if ( opt == 1 ) backup ( );
			else if ( opt == 2 ) restore ( );
			else cout << "invalid option\n";
			break;
			}
			case 0: cout << "exiting...\n"; break;
			default: cout << "invalid choice.\n";
			}
		} while ( c != 0 );
	}