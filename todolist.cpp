#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isDone;
};

vector<Task> todoList;

void addTask() {
    string desc;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, desc);
    todoList.push_back({desc, false});
    cout << "Task added!\n";
}

void viewTasks() {
    if (todoList.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    for (size_t i = 0; i < todoList.size(); ++i) {
        cout << i + 1 << ". [" << (todoList[i].isDone ? "X" : " ") << "] "
             << todoList[i].description << endl;
    }
}

void markDone() {
    int index;
    cout << "Enter task number to mark as done: ";
    cin >> index;
    if (index < 1 || index > todoList.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    todoList[index - 1].isDone = true;
    cout << "Task marked as done.\n";
}

void deleteTask() {
    int index;
    cout << "Enter task number to delete: ";
    cin >> index;
    if (index < 1 || index > todoList.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    todoList.erase(todoList.begin() + index - 1);
    cout << "Task deleted.\n";
}

void menu() {
    int choice;
    do {
        cout << "\n--- TO-DO LIST MENU ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markDone(); break;
            case 4: deleteTask(); break;
            case 5: cout << "Goodbye!\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}
