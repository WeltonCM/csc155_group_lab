/*
Name: Group Lab
Author: Christopher Welton & Raem Qamar
Description: This program recreates a library. You can add, modify, and remove books from the library. 
Users are registered and can checkout library books. The library class manages what is in stock and out of stock. 
*/

#include "Library.h"
#include <string>
#include <iostream>

int main() {
    // Make a Library
    Library austinPublicLibrary = Library("Austin Public Library");

    //Make 3 Books
    Book cppPrimer = Book("C++ Primer", "Stanley Lippman");
    Book programmingPrinciplesCpp = Book("Programming: Principles and Practice Using C++", "Bjarne Stroustrup");
    Book tourCpp = Book("A Tour of C++", "Bjarne Stroustrup");

    // Add books to library inventory
    austinPublicLibrary.addBook(cppPrimer, 3);
    austinPublicLibrary.addBook(programmingPrinciplesCpp, 4);
    austinPublicLibrary.addBook(tourCpp, 10);

    //Make 2 Library Members
    LibraryMember joeSixpack = LibraryMember("Joe", "Sixpack");
    LibraryMember cptAmerica = LibraryMember("Captain", "America");

    //Add members to library
    austinPublicLibrary.addMember(joeSixpack);
    austinPublicLibrary.addMember(cptAmerica);

    // Print the library
    austinPublicLibrary.print();

    // Checkout books
    if(austinPublicLibrary.checkoutBook(cppPrimer.getIsbn(), joeSixpack.getId())) joeSixpack.checkoutBook(cppPrimer);
    if(austinPublicLibrary.checkoutBook(tourCpp.getIsbn(), cptAmerica.getId())) cptAmerica.checkoutBook(tourCpp);
    if(austinPublicLibrary.checkoutBook(tourCpp.getIsbn(), joeSixpack.getId())) joeSixpack.checkoutBook(tourCpp);
    if(austinPublicLibrary.checkoutBook(programmingPrinciplesCpp.getIsbn(), joeSixpack.getId())) joeSixpack.checkoutBook(programmingPrinciplesCpp);
    

    // Print Library & members
    austinPublicLibrary.print();
    joeSixpack.print();
    cptAmerica.print();

    // Return books
    if(austinPublicLibrary.returnBooks(joeSixpack.getCheckedoutBooks(), joeSixpack.getId())) joeSixpack.returnBooks();
    if(austinPublicLibrary.returnBooks(cptAmerica.getCheckedoutBooks(), cptAmerica.getId())) cptAmerica.returnBooks();

    // Print Library
    austinPublicLibrary.print();

    return 0;
}