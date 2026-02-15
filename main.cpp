#include <iostream>
#include "src/Task.h"
#include "src/ToDoList.h"
#include <vector>
#include <limits>

void initialMenu() {
    std::cout << "\n--- TO-DO LIST MENU ---" << std::endl;
    std::cout << "[1] Add a new task." << std::endl;
    std::cout << "[2] Exit." << std::endl;
    std::cout << "Select an action: ";
}

void standardMenu() {
    std::cout << "\n--- TO-DO LIST MENU ---" << std::endl;
    std::cout << "\n>> SELECT A TASK:" << std::endl;
}

void taskActions() {
    std::cout << "\n--- ACTIONS MENU ---" << std::endl;
    std::cout << "[1] Set as completed." << std::endl;
    std::cout << "[2] Modify title." << std::endl;
    std::cout << "[3] Modify description." << std::endl;
    std::cout << "[4] Set a due date." << std::endl;
    std::cout << "[5] Delete this task." << std::endl;
    std::cout << "[6] Go back." << std::endl;
}

void showList(std::vector<Task> t) {
    if (t.empty()) {
        std::cout << "Lista vuota." << std::endl;
    }
    else {
        std::cout << "\n-- TO DO LIST --" << std::endl;
        for (int i = 0; i < t.size(); ++i) {
            std::cout << i + 1 << ". " << t[i].getTitle();
            (t[i].isCompleted()) ? std::cout << " [Completed]" << std::endl : std::cout << " [Not completed]" << std::endl;
        }
    }
}

void showTaskDetails(const Task &t) {
    //std::tm tempDate = t.getDueDate();
    std::cout << "-- TASK DETAILS --" << std::endl;
    std::cout << "Title: " << t.getTitle() << std::endl;
    std::cout << "Description: " << t.getDescription() << std::endl;
    std::cout << "Status: ";
        if(t.isCompleted()) {
            std::cout << "Completed" << std::endl;
        } else {
            std::cout << "Not completed" << std::endl;
        }
    std::cout << "DueDate: ";
    if(t.getDueDate() == "0000-00-00") {
        std::cout << "No due date set" << std::endl;
    } else {
        std::cout << t.getDueDate() << std::endl;
    }
    std::cout << "Created: " << t.getCreated() << std::endl;
    std::cout << "Modified: " << t.getModified() << std::endl;
}

void addTask(std::vector<Task> &todolist) {
    std::string title;
    std::string description;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\n-- CREATE NEW TASK --" << std::endl;
    std::cout << "Title: ";
    std::getline(std::cin, title);
    std::cout << "Description: ";
    std::getline(std::cin, description);

    Task newTask(title, description);
    todolist.push_back(newTask);

    std::cout << "Task added successfully." << std::endl;
}

std::string inputDate() {
    std::string input;
    std::tm date{};
    std::ostringstream oss;

    while (true) {
        std::cout << "New due date (yyyy-mm-dd): ";
        std::cin >> input;

        std::istringstream iss(input);
        iss >> std::get_time(&date, "%Y-%m-%d");

        if (!iss.fail()) {
            date.tm_hour = 0;
            date.tm_min  = 0;
            date.tm_sec  = 0;

            std::tm check = date;
            if (std::mktime(&check) != -1 &&
                check.tm_mday == date.tm_mday &&
                check.tm_mon  == date.tm_mon  &&
                check.tm_year == date.tm_year) {

                oss << std::put_time(&date, "%Y-%m-%d");
                return oss.str();
                }
        }

        std::cout << "Invalid date. Try again." << std::endl;
    }
}


int main() {
    std::vector<Task> todolist;
    //ToDoList myList;
    int choiceTask;
    int choiceAction;
    std::string input;
    std::tm date;

    Task t1 = Task("A task", "desc..");
    Task t2 = Task("Another task", "desc..");

    todolist.push_back(t1);
    todolist.push_back(t2);
    /*
    myList.addTask(Task("A task", "desc.."));
    myList.addTask(Task("Another task", "desc"));
    */

    // SHOW LIST OF TASK ALREADY CREATED
    do {
        showList(todolist);
        std::cout << "\nSelect a task (0: add a new task, -1: exit): ";
        std::cin >> choiceTask;

        // EXIT
        if (choiceTask == -1) {break;}

        // CREATE A NEW TASK
        if (choiceTask == 0) {
            addTask(todolist);
            continue;
        }

        // SELECTED TASK, THEN SHOW DETAILS
        if (choiceTask > 0 && choiceTask <= todolist.size()) {
            int taskIndex = choiceTask - 1;

            // TASK ACTIONS
            do {
                showTaskDetails(todolist[taskIndex]);
                taskActions();
                std::cout << "Select an action: ";
                std::cin >> choiceAction;

                if (choiceAction == 6) {break;}

                // SHOW ACTIONS
                switch (choiceAction) {
                    case 1: {
                        todolist[taskIndex].setCompleted(true); // da aggiustare
                        break;
                    }
                    case 2: {
                        std::cout << "New title: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::getline(std::cin, input);
                        todolist[taskIndex].setTitle(input);
                        break;
                    }
                    case 3: {
                        std::cout << "New description: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::getline(std::cin, input);
                        todolist[taskIndex].setDescription(input);
                        break;
                    }
                    case 4: {
                        std::cout << "New due date (yyyy-mm-dd): ";
                        std::cin >> input;
                        todolist[taskIndex].setDueDate(inputDate());
                        break;
                    }
                    case 5: {
                        todolist.erase(todolist.begin() + taskIndex);
                        std::cout << "Task has been successfully removed." << std::endl;
                        choiceAction = 6;
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
