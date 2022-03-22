#include <string>
using namespace std;
#include "Direction.hpp"
#include <vector>
#include <array>

namespace ariel{

    class Page {
    public:
        Page() {}
        ~Page() {}

        void write(int page, int row, int col, Direction direction, string str) {}
        void read(int page, int row, int col, Direction direction, int chars) {}
        void erase(int page, int row, int col, Direction direction, int chars) {}
        void show() {}
    private:
        vector<array<char, 100>> data;
    };

    class Notebook {
    public:
        Notebook() {}
        ~Notebook() {}

        void write(int page, int row, int col, Direction direction, string str){}
        string read(int page, int row, int col, Direction direction, int chars){ return ""; }
        void erase(int page, int row, int col, Direction direction, int chars) {}
        void show(int page) {}

    private:
        vector<Page> pages;
    };

}