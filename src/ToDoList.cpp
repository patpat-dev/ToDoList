//
// Created by ylade on 21/01/2026.
//

#include "ToDoList.h"
#include <stdexcept>
#include <iostream>

void ToDoList::addTask(const Task &t) {
    tasks.push_back(t);
}

void ToDoList::newTask() {
    std::string title;
    std::string description;

    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\n-- CREATE NEW TASK --" << std::endl;
    std::cout << "Title: ";
    std::getline(std::cin, title);
    std::cout << "Description: ";
    std::getline(std::cin, description);

    Task newTask(title, description);
    tasks.push_back(newTask);

    std::cout << "Task added successfully." << std::endl;
}

void ToDoList::modifyTitle(int index, std::string newTitle) {
    if (index < 0 || index >= tasks.size()) {
        throw std::out_of_range("Index out of range.");
    }
    tasks[index].setTitle(newTitle);
}

void ToDoList::modifyDescription(int index, std::string newDescription) {
    if (index < 0 || index >= tasks.size()) {
        throw std::out_of_range("Index out of range.");
    }
    tasks[index].setDescription(newDescription);
}

void ToDoList::modifyDueDate(int index) {
    if (index < 0 || index >= tasks.size()) {
        throw std::out_of_range("Index out of range.");
    }
    std::string date = inputDate();
    tasks[index].setDueDate(date);
}

void ToDoList::removeDueDate(int index) {
    if (index < 0 || index >= tasks.size()) {
        throw std::out_of_range("Index out of range.");
    }
    tasks[index].setDueDate("0000-00-00");
}

void ToDoList::removeTask(int index) {
    if (index < 0 || index >= tasks.size()) {
        throw std::out_of_range("Index out of range.");
    }
    tasks.erase(tasks.begin() + index);
}

void ToDoList::markTaskAsDone(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].setCompleted(true);
    }
    else {
        throw std::out_of_range("Index out of range.");
    }
}

void ToDoList::removeAllTasks() {
    tasks.clear();
}

void ToDoList::showTaskDetails(int index) const {
    std::cout << "-- TASK DETAILS --" << std::endl;
    std::cout << "Title: " << tasks[index].getTitle() << std::endl;
    std::cout << "Description: " << tasks[index].getDescription() << std::endl;
    std::cout << "Status: ";
    if(tasks[index].isCompleted()) {
        std::cout << "Completed" << std::endl;
    } else {
        std::cout << "Not completed" << std::endl;
    }
    std::cout << "DueDate: ";
    if(tasks[index].getDueDate() == "0000-00-00") {
        std::cout << "No due date set" << std::endl;
    } else {
        std::cout << tasks[index].getDueDate() << std::endl;
    }
    std::cout << "Created: " << tasks[index].getCreated() << std::endl;
    std::cout << "Modified: " << tasks[index].getModified() << std::endl;
}

void ToDoList::showList() const {
    if (tasks.empty()) {
        std::cout << "List is empty. Add a new task." << std::endl;
    }
    else {
        std::cout << "\n-- TO DO LIST --" << std::endl;
        for (int i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].getTitle();
            (tasks[i].isCompleted()) ? std::cout << " [Completed]" << std::endl : std::cout << " [Not completed]" << std::endl;
        }
    }
}

const std::vector<Task> & ToDoList::getTasks() const {
    return tasks;
}

int ToDoList::getNumberOfTasks() const {
    return tasks.size();
}

std::string ToDoList::inputDate() const {
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