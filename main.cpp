#include <iostream>
#include "src/Task.h"
#include "src/ToDoList.h"
#include <vector>
#include <limits>
#include "src/MemoryManager.h"

// LIST OF ACTION ON A SELECTED TASK
void taskActions() {
    std::cout << "\n--- ACTIONS MENU ---" << std::endl;
    std::cout << "[1] Set as completed." << std::endl;
    std::cout << "[2] Modify title." << std::endl;
    std::cout << "[3] Modify description." << std::endl;
    std::cout << "[4] Set a due date." << std::endl;
    std::cout << "[5] Delete this task." << std::endl;
    std::cout << "[6] Go back." << std::endl;
}

// CHECK USER INPUT, MUST BE AN INTEGER
int getValidInteger(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            // in case of string input
            std::cout << "Error: Please put a valid integer number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            // iin case of integer input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

int main() {
    ToDoList myList;
    int choiceTask;
    int choiceAction;
    std::string input;
    const std::string filename = "data/tasks.csv";

    MemoryManager::loadFromFile(myList, filename);

    //Task t1 = Task("A task", "desc..");
    //Task t2 = Task("Another task", "desc..");

    //myList.addTask(t1);
    //myList.addTask(t2);

    // SHOW LIST OF TASK ALREADY CREATED
    do {
        myList.showList();
        choiceTask = getValidInteger("\nSelect a task (0: add a new task, -1: exit): ");

        // EXIT
        if (choiceTask == -1) {break;}

        // CREATE A NEW TASK
        if (choiceTask == 0) {
            myList.newTask();
            MemoryManager::saveToFile(myList, filename);
            continue;
        }

        // SHOW ACTIONS ON SELECTED TASK
        if (choiceTask > 0 && choiceTask <= myList.getNumberOfTasks()) {
            int taskIndex = choiceTask - 1;

            // TASK ACTIONS
            do {
                myList.showTaskDetails(taskIndex);
                taskActions();
                choiceAction = getValidInteger("\nSelect an action: ");

                if (choiceAction == 6) {break;}

                // SHOW ACTIONS
                switch (choiceAction) {
                    case 1: {
                        myList.markTaskAsDone(taskIndex);
                        MemoryManager::saveToFile(myList, filename);
                        break;
                    }
                    case 2: {
                        std::cout << "New title: ";
                        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::getline(std::cin, input);
                        myList.modifyTitle(taskIndex, input);
                        MemoryManager::saveToFile(myList, filename);
                        break;
                    }
                    case 3: {
                        std::cout << "New description: ";
                        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::getline(std::cin, input);
                        myList.modifyDescription(taskIndex, input);
                        MemoryManager::saveToFile(myList, filename);
                        break;
                    }
                    case 4: {
                        myList.modifyDueDate(taskIndex);
                        MemoryManager::saveToFile(myList, filename);
                        break;
                    }
                    case 5: {
                        myList.removeTask(taskIndex);
                        std::cout << "Task has been successfully removed." << std::endl;
                        MemoryManager::saveToFile(myList, filename);
                        choiceAction = 6;
                        break;
                    }
                    default: {
                        std::cout << "Error: Invalid choice." << std::endl;
                        break;
                    }
                } // close switch-case
            } while (choiceAction != 6); // close do-while
        } // close if
        else {
            std::cout << "Invalid choice." << std::endl;
        }
    } while (true); // close do-while

    return 0;
}
