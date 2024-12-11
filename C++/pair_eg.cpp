#include <iostream>
#include <utility>  // For pair

using namespace std;

int main() {
    // Declaration of a pair
    pair<int, string> myPair;

    // Initialize pair using make_pair()
    myPair = make_pair(1, "Alice");

    // Accessing elements of a pair using first and second
    cout << "Pair elements: ";
    cout << "First: " << myPair.first << ", Second: " << myPair.second << endl;

    // Changing values of a pair
    myPair.first = 2;
    myPair.second = "Bob";

    // Display updated pair values
    cout << "Updated Pair: ";
    cout << "First: " << myPair.first << ", Second: " << myPair.second << endl;

    // Declaration and initialization of another pair
    pair<int, string> anotherPair(3, "Charlie");

    // Comparing two pairs (Lexicographical comparison)
    if (myPair < anotherPair) {
        cout << "myPair is less than anotherPair" << endl;
    } else {
        cout << "myPair is greater than or equal to anotherPair" << endl;
    }

    // Swapping two pairs
    cout << "Before swap:" << endl;
    cout << "myPair: (" << myPair.first << ", " << myPair.second << ")" << endl;
    cout << "anotherPair: (" << anotherPair.first << ", " << anotherPair.second << ")" << endl;

    myPair.swap(anotherPair);  // Swapping myPair and anotherPair

    cout << "After swap:" << endl;
    cout << "myPair: (" << myPair.first << ", " << myPair.second << ")" << endl;
    cout << "anotherPair: (" << anotherPair.first << ", " << anotherPair.second << ")" << endl;

    return 0;
}