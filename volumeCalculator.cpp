// # Program name: volumeCalculator.cpp
// # Author: Ronit Patel
// # Date last updated: 3/20/2024
// # Purpose: Finding The Volume of Cube.


#include <iostream>
#include <utility>
#include <string>
#include <limits> // Include for std::numeric_limits
#include <ext/numeric_traits.h>

using namespace std;
// Global variables
int height_, width_, length_;
string colour_;

class Cube {

private:
    int length;
    int width;
    int height;
    string colour;

public:
    Cube(int x, int y, int z, string colo) : length(x), width(y), height(z), colour(std::move(colo)) {}

    // Getter methods
    int getWidth() const {
        return width;
    }
    int getHeight() const {
        return height;
    }
    int getLength() const {
        return length;
    }
    string getColour() const {
        return colour;
    }

    // Setter methods
    void setWidth(int w) {
        width = w;
    }
    void setLength(int l) {
        length = l;
    }
    void setHeight(int h) {
        height = h;
    }
    void setColour(const string& c) {
        colour = c;
    }

    int calculateVolume() {
        return length * width * height;
    }
};

// all important functions
void lenght_taker() {
    while (true) {
        cout << "Enter the length of the cube: ";
        if (cin >> length_ && length_ > 0) {
            break;
        } else {
            cout << "Please enter a proper integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

}

void width_taker() {
    while (true) {
        cout << "Enter the width of the cube: ";
        if (cin >> width_ && width_ > 0) {
            break;
        } else {
            cout << "Please enter a proper integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void height_taker() {
    while (true) {
        cout << "Enter the height of the cube: ";
        if (cin >> height_ && height_ > 0) {
            break;
        } else {
            cout << "Please enter a proper integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

}

void colour_taker() {
    cout << "Enter the colour of the cube: ";
    cin >> colour_;

}

void info_displayer() {
    Cube mycube(length_, width_, height_, colour_);
    cout << "-------------------------------------------------------------------" << endl;
    cout << "The length of the cube is " << mycube.getLength() << " m." << endl;
    cout << "The width of the cube is " << mycube.getWidth() << " m." << endl;
    cout << "The height of the cube is " << mycube.getHeight() << " m." << endl;
    cout << "The colour of the cube is " << mycube.getColour() << "." << endl;
    cout << "The volume of the cube is " << mycube.calculateVolume() << " m^3." << endl;
    cout << "-------------------------------------------------------------------" << endl;


}

int main() {
    string decider;
    int choice ;
   cout << "Welcome to Volume Calculator 🧮 \n Please Enter the Following values to procced" << endl;

    lenght_taker();
    width_taker();
    height_taker();
    colour_taker();

    info_displayer();

    // Decison to either edit the parameters or not.
    cout << "Do you want to make any changes to the values of cube ? (Y or N): "; cin >> decider;

    if (decider == "Y" || decider == "y") {
        do {
            cout << "Enter The Corrosponding Number to Selct the option; " << endl;
            cout << "Change length: 1" << endl;
            cout << "Change width: 2" << endl;
            cout << "Change height: 3" << endl;
            cout << "Change colour: 4" << endl;
            cout << "Exit (Satisfied with Changes): 0" << endl;
            while (true) {
                cout << "Enter Your Choice: ";
                if (cin >> choice) {
                    break;
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            // switch statement that finds out which option to select
            switch (choice) {
                case 1:
                    lenght_taker();
                    info_displayer();
                    break;
                case 2:
                    width_taker();
                    info_displayer();
                    break;
                case 3:
                    height_taker();
                    info_displayer();
                    break;
                case 4:
                    colour_taker();
                    info_displayer();
                    break;
                case 0:
                    break;
                default:
                    cout << "Please enter a valid choice." << endl;
                    break;
            }
        } while (choice != 0);

        info_displayer();

    };



    return 0;
}
