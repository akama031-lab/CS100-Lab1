#include <iostream>
#include <string>
#include <limits>
#include "../header/rectangle.hpp"
#include "../header/triangle.hpp"

using namespace std;

// Input validation to reject negatives and letters (Required for Full Credit)
double getValidInput(string prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val && val >= 0) {
            return val;
        }
        cout << "Invalid input. Please enter a non-negative number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    int choice;
    cout << "Choose a shape (1 for Rectangle, 2 for Triangle): ";
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cout << "Invalid choice. Enter 1 or 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (choice == 1) {
        // Using your Rectangle Class
        Rectangle rect;
        int w = (int)getValidInput("Enter width: ");
        int h = (int)getValidInput("Enter height: ");
        rect.set_width(w);
        rect.set_height(h);
        cout << "Area of rectangle: " << rect.area() << endl;
    } 
    else {
        // Using the Triangle Function
        double base = getValidInput("Enter base: ");
        double height = getValidInput("Enter height: ");
        cout << "Area of triangle: " << triangle_area(base, height) << endl;
    }

    return 0;
}