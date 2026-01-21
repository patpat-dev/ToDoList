//
// Created by ylade on 21/01/2026.
//

#include "ToDoList.h"
#include <stdexcept> // per gestire errori di indice
#include <iostream> // do not include on final project use std::.. instead

void ToDoList::addTask(const Task &t) {
    tasks.push_back(t);
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
// same for modify due date
void ToDoList::addDueDate(int index, std::string date) {
    if (index < 0 || index >= tasks.size()) {
        throw std::out_of_range("Index out of range.");
    }
    tasks[index].setDueDate(date);
}

void ToDoList::removeDueDate(int index) {
    if (index < 0 || index >= tasks.size()) {
        throw std::out_of_range("Index out of range.");
    }
    tasks[index].setDueDate(""); // cercare con attributo.clear
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
        tasks[index].setModified("modified now");
    }
    else {
        throw std::out_of_range("Index out of range.");
    }
}

void ToDoList::removeAllTasks() {
    tasks.clear();
    // vedere come liberare memoria
}

const std::vector<Task> & ToDoList::getAllTasks() const {
    for (const Task& t : tasks) {
        std::cout << "Titolo: " << t.getTitle() << std::endl;
        std::cout << "Descrizione: " << t.getDescription() << std::endl;
        std::cout << "Stato: " << t.isCompleted() << std::endl;
        std::cout << "Creazione: " << t.getCreated() << std::endl;
        std::cout << "Modifica: " << t.getModified() << std::endl;
        std::cout << "Scadenza: " << t.getDueDate() << std::endl;
    }
}

int ToDoList::getNumberOfTasks() const {
    return tasks.size();
}