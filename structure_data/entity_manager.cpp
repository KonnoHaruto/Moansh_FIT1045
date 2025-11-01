#include "splashkit.h"
#include "utilities.h"

using std::to_string;

struct book_data
{
    string title;
    string location;
    int pages;
};

book_data read_book()
{
    book_data book;
    book.title = read_string("Enter the name of the book: ");
    book.location = read_string("Enter book location: ");
    book.pages = read_integer("Enter number of pages: ");

    return book;
}

void print_book(book_data book)
{
    write_line("Book details:");
    write_line("Title: " + book.title);
    write_line("Location: " + book.location);
    write_line("Pages: " + to_string(book.pages));
}

int show_menu()
{
    write_line("Menu:");
    write_line("1 - Read book");
    write_line("2 - Print book");
    write_line("3 - Quit");
    return read_integer("Option: ");
}

int main()
{
    book_data book;
    int option;

    write_line("Book entry system:");
    write_line();
    book = read_book();
    write_line();

    do
    {
        option = show_menu();
        if (option == 1)
        {
            write_line();
            book = read_book();
            write_line();
        }
        else if (option == 2)
        {
            write_line();
            print_book(book);
            write_line();
        }
        else break;
    }
    while(option != 3);

    return 0;
}