#include <iostream>
#include <vector>
#include <random>

#include <iomanip>
#include <ctime>

using namespace std;


// what holds the values
struct colour {
    int r;
    int g;
    int b;
};

// first I need to set up some kind of random generator
int main() {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist_n(25, 50); // for number of colours
    uniform_int_distribution<> dist_rgb(0, 255); // for rgb values

    // generate a random number of colours between 25 and 50
    int ncolours = dist_n(gen);

    vector<colour> colours;
    for (int i = 0; i < ncolours; ++i) {
        colour c;
        c.r = dist_rgb(gen);
        c.g = dist_rgb(gen);
        c.b = dist_rgb(gen);
        colours.push_back(c);
    }

    // display the colours header table
    cout << left << setw(8) << "Color ##" 
         << left << setw(8) << "##Red" 
         << left << setw(8) << "##Green" 
         << left<< setw(8) << "##Blue" << endl;
    cout <<  "-------  --------- --------- ---------" << endl;

    // output the vector's content
    for (size_t i = 0; i < colours.size(); ++i) {
        cout << left << setw(8) << (i + 1)
             << left << setw(8) << colours[i].r
             << left << setw(8) << colours[i].g
             << left << setw(8) << colours[i].b 
             << endl;
    }
    return 0;
}