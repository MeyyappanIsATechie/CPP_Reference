 #define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<memory>

using namespace std;

class Test {
private:
	int data;
public:
	Test ( ) :data { 0 } {
		cout << "test constructor" << data << endl;
		}
	Test ( int data ) :data { data } {
		cout << "Test constructor" << data << endl;
		}
	int get_data ( ) const {
		return data;
		}
	~Test ( ) {
		cout << "Test destructor" << data << endl;
		}
	};

unique_ptr<vector<shared_ptr<Test>>> make ( ){ // or auto make(){}
	return make_unique<vector<shared_ptr<Test>>> ( );
	}
void fill ( vector<shared_ptr<Test>>& vec , int num ){
	int t;
	for ( int i = 1; i <= num; i++ ) {
		cin >> t;
		//shared_ptr<Test> ptr = make_shared<Test> ( t );
		//vec.push_back ( ptr );
		vec.push_back ( make_shared<Test> ( t ) );

		}
	}
void display ( const vector<shared_ptr<Test>>& vec ){
	for ( const auto& ptr : vec ) {
		cout << ptr->get_data ( ) << endl;
		}
	}

int main ( ) {
	unique_ptr<vector<shared_ptr<Test>>> ptr;
	ptr = make ( );
	int n;
	cin >> n;
	fill ( *ptr , n );
	display ( *ptr );
	}