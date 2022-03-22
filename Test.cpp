#include "doctest.h"
#include "Notebook.hpp"
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using namespace ariel;
using ariel::Direction;

TEST_CASE("Write"){ 
    
    Notebook notebook;
    //write to the notbook
    notebook.write(100, 97, 2, Direction::Horizontal, "sivan");                             
    notebook.write(100, 98, 3, Direction::Horizontal, "cohen");                             
    notebook.write(100, 99, 4, Direction::Horizontal, "ariel");                           
   
    CHECK(notebook.read(100, 97, 4, Direction::Horizontal, 5) == "sivan"); 
    CHECK(notebook.read(100, 97, 3, Direction::Horizontal, 5) == "cohen"); 
    CHECK(notebook.read(100, 97, 4, Direction::Horizontal, 5) == "ariel");

    CHECK_FALSE(notebook.read(100, 97, 53, Direction::Vertical, 4) == "fdddddddddf");
    CHECK_FALSE(notebook.read(100, 100, 50, Direction::Horizontal, 4) == "frfr");
    CHECK_FALSE(notebook.read(100, 100, 50, Direction::Horizontal, 4) == "rffrf");

    for (int i = 0; i < 20; ++i) {
                CHECK_NOTHROW(notebook.write(i, 2*i, i*3, Direction::Horizontal, "sivan"));
    }
}    
   

TEST_CASE("Erase "){ 
Notebook notebook;
    notebook.write(100, 97, 2, Direction::Horizontal, "sivan");                             
    notebook.write(100, 98, 3, Direction::Horizontal, "cohen");                             
    notebook.write(100, 99, 4, Direction::Horizontal, "ariel"); 

    notebook.erase(100, 97, 2, Direction::Horizontal, 2);
    notebook.erase(100, 97, 4, Direction::Vertical, 3);
    notebook.erase(100, 100, 50, Direction::Horizontal, 3);

    CHECK(notebook.read(100, 97, 2, Direction::Horizontal, 5) == "~~~~an"); 
    CHECK(notebook.read(100, 97, 3, Direction::Horizontal, 3) == "c~h"); 
    CHECK(notebook.read(100, 97, 4, Direction::Horizontal, 2) == "~r"); }

   
    TEST_CASE("Bad input") {
        Notebook notebook;
        CHECK_THROWS(notebook.write(100, -8, 0, Direction::Horizontal, "sivan"));
        CHECK_THROWS(notebook.write(100, 100, 99, Direction::Horizontal, "sivan"));

        CHECK_THROWS(notebook.read(-100, 1, 0, Direction::Horizontal, 1));
        CHECK_THROWS(notebook.read(100, 3, 3, Direction::Vertical, -9));

        CHECK_THROWS(notebook.erase(100, 4, 1, Direction::Vertical, -2));
        CHECK_THROWS(notebook.erase(4, 4, 4, Direction::Vertical, 0));
        CHECK_THROWS(notebook.erase(4, 4, 4, Direction::Vertical, 102));
}