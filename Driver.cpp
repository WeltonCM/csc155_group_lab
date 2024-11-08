/*
Name: Group Lab
Author: Christopher Welton & Raem Qamar
Description: This program recreates a library. You can add, modify, and remove books from the library. 
Users are registered and can checkout library books. The library class manages what is in stock and out of stock. 
*/

#include "Book.h"
#include "LibraryMember.h"
#include <string>
#include <iostream>

int main() {
    Book book = Book("Hello", "Welton");
    book.print();
    cout<< "\n";

    LibraryMember chris = LibraryMember("Chris", "Welton");
    chris.checkoutBook(book);

    chris.print();
    chris.returnBook(book);
    chris.print();
    return 0;
}