#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>

// Template class for any library item
template<typename T>
class Item {
    T id;
    std::string title;
    std::string author;
    int year;

public:
    Item( ) {}
    Item ( T id , std::string title , std::string author , int year )
        : id ( id ) , title ( title ) , author ( author ) , year ( year ) {}

    void display ( ) const {
        std::cout << id << " | " << title << " | " << author << " | " << year << '\n';
        }

    T getId ( ) const {
        return id;
        }
    std::string getTitle ( ) const {
        return title;
        }
    std::string getAuthor ( ) const {
        return author;
        }
    int getYear ( ) const {
        return year;
        }

    bool operator<( const Item<T>& other ) const {
        return year < other.year;  // For sorting
        }
    };


class Library {
    std::vector<Item<int>> items;
    std::map<int , Item<int>> id_map;
    std::set<std::string> authors;
    std::unordered_map<std::string , std::vector<Item<int>>> grouped_by_author;

public:
    void add_book ( int id , std::string title , std::string author , int year ) {
        Item<int> item ( id , std::move ( title ) , std::move ( author ) , year );
        items.push_back ( item );
        id_map [ id ] = item;
        authors.insert ( item.getAuthor ( ) );
        grouped_by_author [ item.getAuthor ( ) ].push_back ( item );
        }

    void remove_book ( int id ) {
        auto it = id_map.find ( id );
        if ( it != id_map.end ( ) ) {
            std::string author = it->second.getAuthor ( );
            id_map.erase ( it );
            items.erase ( std::remove_if ( items.begin ( ) , items.end ( ) ,
                [ id ] ( const Item<int>& item ) { return item.getId ( ) == id; } ) , items.end ( ) );
            auto& vec = grouped_by_author [ author ];
            vec.erase ( std::remove_if ( vec.begin ( ) , vec.end ( ) ,
                [ id ] ( const Item<int>& item ) { return item.getId ( ) == id; } ) , vec.end ( ) );
            if ( vec.empty ( ) ) {
                grouped_by_author.erase ( author );
                authors.erase ( author );
                }
            }
        }

    void display_all_sorted_by_year ( ) const {
        std::vector<Item<int>> sorted = items;
        std::sort ( sorted.begin ( ) , sorted.end ( ) );
        for ( const auto& item : sorted )
            item.display ( );
        }

    void search_by_title ( const std::string& keyword ) const {
        std::cout << "Search results for title containing '" << keyword << "':\n";
        for ( const auto& item : items ) {
            if ( item.getTitle ( ).find ( keyword ) != std::string::npos )
                item.display ( );
            }
        }

    void group_books_by_author ( ) const {
        for ( const auto& pair : grouped_by_author ) {
            std::cout << "\nAuthor: " << pair.first << "\n";
            for ( const auto& item : pair.second )
                item.display ( );
            }
        }

    void display_summary ( ) const {
        std::cout << "\nTotal Books: " << items.size ( ) << '\n';
        std::cout << "Unique Authors: " << authors.size ( ) << '\n';
        if ( !items.empty ( ) ) {
            auto oldest = *std::min_element ( items.begin ( ) , items.end ( ) );
            auto newest = *std::max_element ( items.begin ( ) , items.end ( ) );
            std::cout << "Oldest Book: "; oldest.display ( );
            std::cout << "Newest Book: "; newest.display ( );
            }
        }
    };


int main ( ) {
    Library lib;
    lib.add_book ( 1001 , "The C++ Programming Language" , "Bjarne Stroustrup" , 2013 );
    lib.add_book ( 1002 , "Effective Modern C++" , "Scott Meyers" , 2014 );
    lib.add_book ( 1003 , "Clean Code" , "Robert C. Martin" , 2008 );
    lib.add_book ( 1004 , "The Pragmatic Programmer" , "Andy Hunt" , 1999 );

    std::cout << "\nAll Books Sorted by Year:\n";
    lib.display_all_sorted_by_year ( );

    std::cout << "\nGrouped by Author:\n";
    lib.group_books_by_author ( );

    std::cout << "\nSearch by Title:\n";
    lib.search_by_title ( "C++" );

    std::cout << "\nLibrary Summary:\n";
    lib.display_summary ( );

    lib.remove_book ( 1002 );
    std::cout << "\nAfter Removing Book ID 1002:\n";
    lib.display_all_sorted_by_year ( );
    lib.display_summary ( );

    return 0;
    }
