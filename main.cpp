#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the menu options
void displayMenu() {
    cout << "\nTodo List Menu:\n";
    cout << "1. Add task\n";
    cout << "2. View tasks\n";
    cout << "3. Mark task as complete\n";
    cout << "4. Quit\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<string> tasks;
    vector<bool> completed;

    int choice;
    string task;

    do {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter task: ";
                cin.ignore(); // Clear input buffer
                getline(cin, task);
                tasks.push_back(task);
                completed.push_back(false);
                break;
            case 2:
                if(tasks.empty()) {
                    cout << "Todo list is empty.\n";
                } else {
                    cout << "Todo List:\n";
                    for(size_t i = 0; i < tasks.size(); ++i) {
                        cout << (completed[i] ? "[X] " : "[ ] ") << tasks[i] << endl;
                    }
                }
                break;
            case 3:
                if(tasks.empty()) {
                    cout << "Todo list is empty.\n";
                } else {
                    int index;
                    cout << "Enter the index of the task to mark as complete: ";
                    cin >> index;
                    if(index >= 0 && index < static_cast<int>(tasks.size())) {
                        completed[index] = true;
                        cout << "Task marked as complete.\n";
                    } else {
                        cout << "Invalid index.\n";
                    }
                }
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 4);

    return 0;
}
