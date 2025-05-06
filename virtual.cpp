#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class Shape {
private:
public:
	virtual void draw ( ) = 0;
	virtual void rotate ( ) = 0;
	virtual~ Shape( ){}
	};

class Open_shape : public Shape { //abstract calss
public:
	~Open_shape( ){}
	};

class Closed_shape :public Shape { //abstract class
public:
	virtual~Closed_shape ( ) {};
	};

class Line : public Open_shape {
public:
	virtual void draw ( ) override {
		cout << "drawing a line" << endl;
		}
	virtual void rotate ( ) override {
		cout << "rotating a line" << endl;
		}
	virtual~ Line( ){}
	};

class Circle : public Closed_shape {
public:
	virtual void draw ( ) override {
		cout << "drawing a circle" << endl;
		}
	virtual void rotate ( ) override {
		cout << "rotating a circle" << endl;
		}
	virtual~ Circle( ){}
	};

int main ( ) {
	Circle c;
	c.draw ( );

	Shape* s = new Circle ( );

	delete s;
	}