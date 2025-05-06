#include <iostream>
#include<stack>
#include<queue> //pq
#include<list>
#include<vector>

using namespace std;

//insertion and removal in order from front of container
//priority order (largest at front - max heap)
//no iterators supported
//push,pop,top,empty?,size

template<typename T>
void display ( priority_queue<T> pq ) {
	while ( !pq.empty ( ) ) {
		T e = pq.top ( );
		pq.pop ( );
		cout << e << " ";
		}
	}

int main ( ) {
	priority_queue<int> pq; //vector by default

	pq.push ( 11 );
	pq.push ( 2 );
	pq.push ( 3 );

	cout << pq.top ( ) << endl; //greatest element
	pq.pop ( );
	int top = pq.top ( );

	display ( pq );

	//pq.top ( ) = 5; // cant do this
	}