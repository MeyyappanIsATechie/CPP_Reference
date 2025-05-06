#include <iostream>
#include <initializer_list>

using namespace std;

template<typename T>
class Vector {
private:
    friend ostream& operator<< <>( ostream& os , const Vector<T>& v );
    T* arr;
    size_t s;
    size_t cap;

    //private utility
    void resize ( size_t new_cap ) {
        T* new_arr = new T [ new_cap ];
        for ( size_t i = 0; i < s; ++i )
            new_arr [ i ] = arr [ i ];
        delete [ ] arr; //cleanup
        arr = new_arr;
        cap = new_cap;
        }

    void swap ( T*& arr , int a , int b ) {
        T t = arr [ a ];
        arr [ a ] = arr [ b ];
        arr [ b ] = t;
        }

public:
    // explicit default constructor
    Vector ( ) : arr ( nullptr ) , s ( 0 ) , cap ( 1 ) {}
    Vector ( initializer_list<T> l ) : s { l.size ( ) } , cap { l.size ( ) } {
        arr = new T [ cap ];
        size_t i = 0;
        for ( const T& v : l ) {
            arr [ i++ ] = v;
            }
        }

    ~Vector ( ) {
        delete [ ] arr;
        }

    void push_back ( const T& value ) {
        if ( s == cap ) {
            resize ( cap * 2 );
            }
        arr [ s++ ] = value;
        }

    void pop_back ( const T& value ) {
        s--;
        }

    T& operator[]( size_t index ) {
        return arr [ index ];  // no bounds check
        }

    size_t size ( ) const {
        return s;
        }

    size_t capacity ( ) const {
        return cap;
        }

    T& at ( size_t index ) {
        if ( index >= s ) {
            throw out_of_range ( "index out of bounds" );
            }
        return arr [ index ];
        }

    void sort ( ) {
        for ( size_t i = 0; i < s - 1; i++ ) {
            for ( size_t j = i + 1; j < s; j++ ) {
                if ( arr [ i ] > arr [ j ] ) {
                    swap ( arr , i , j );
                    }
                }
            }
        }

    void reverse ( ) {
        int l = 0 , r = s - 1;
        while ( l < r ) {
            swap ( arr , l , r );
            l++;
            r--;
            }
        }

    string& find ( T val ) {
        for ( size_t i = 0; i < s; i++ ) {
            if ( arr [ i ] == val ) return "found " + val + " at " + " index " + i+".";
            }
        return val + "not found.";
        }

    //insert

    //clear

    //erase

    //swap

    //begin

    //end

    };

template<typename T>
ostream& operator<< <>( ostream& os , const Vector<T>& v ) {
    cout << "[ ";
    for ( const auto& i : v.arr ) {
        cout << i << " ";
        }
    cout << "] ";
    }

int main ( ) {
    Vector<int> v;
    }
