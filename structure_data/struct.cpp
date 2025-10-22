#include "splashkit.h"

#include "utilities.h"

using std::to_string;

struct book_data
{
    string title;
    int pages;
};

void print_book(book_data book)
{
    write_line(book.title + " (" + to_string(book.pages) + " pages)");
}

int main()
{
    book_data book_0 = {"Happy Days", 20};
    print_book(book_0);
}