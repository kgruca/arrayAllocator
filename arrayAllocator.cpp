#include <iostream>
using namespace std;

int arrLen();
int* allocateArr(int);
void displayArr(int*, int);

int main() {
    // var to hold desired length of array
    int length;
    // pointer to a dynamically allocated array returned from function allocateArray
    int* getNums;

    length = arrLen();
    getNums = allocateArr(length);
    displayArr(getNums, length);

    // free up memory
    delete[] getNums;
    return 0;
}
/*
    Function arrLen() asks the user what their desired length of the array will be.
    Returns desired length as an int.
*/
int arrLen() {
    int length;

    cout << "What's the length of your array: ";
    cin >> length;

    return length;
}

/*
    Function allocateArray() creates a pointer to an array and dynamically allocates memory to it, 
    based on the user's input from arrLen().
    Returns the pointer to the dynamically allocated array, which will be stored in variable getNums.
*/
int* allocateArr(int len) {
    int* arrPtr;

    arrPtr = new int[len];

    for (int i = 0; i < len; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> *(arrPtr + i);
    }

    return arrPtr;
}

/*
    Function displayArr() accepts a pointer to an int, as well as the length of the dynamically 
    allocated array, and outputs the dynamically created array back to the user.
*/
void displayArr(int* arr, int len) {
    cout << "Your array: " << endl;
    cout << "[";

    for (int i = 0; i < len; i++) {
        if (i == len - 1) {
            cout << arr[i] << "]";
            break;
        }
        cout << arr[i] << ", ";
    }
}