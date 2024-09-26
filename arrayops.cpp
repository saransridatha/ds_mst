#include <iostream>

using namespace std;

void createArray(int arr[], int &size) {
    cout << "Enter the number of elements (N): ";
    cin >> size;

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void displayArray(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int &size, int elem, int pos) {
    if (pos < 1 || pos > size + 1) {
        cout << "Invalid position!" << endl;
        return;
    }


    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = elem;
    size++;
    cout << "Element inserted successfully." << endl;
}

void deleteElement(int arr[], int &size, int pos) {
    if (pos < 1 || pos > size) {
        cout << "Invalid position!" << endl;
        return;
    }


    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    cout << "Element deleted successfully." << endl;
}

int main() {
    int arr[100];
    int size = 0, choice, elem, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create an Array\n";
        cout << "2. Display Array\n";
        cout << "3. Insert an Element\n";
        cout << "4. Delete an Element\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createArray(arr, size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                cout << "Enter the element to insert: ";
                cin >> elem;
                cout << "Enter the position to insert the element (1 to " << size + 1 << "): ";
                cin >> pos;
                insertElement(arr, size, elem, pos);
                break;
            case 4:
                cout << "Enter the position to delete the element (1 to " << size << "): ";
                cin >> pos;
                deleteElement(arr, size, pos);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
