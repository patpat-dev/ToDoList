//
// Created by ylade on 21/01/2026.
//

#ifndef TODOLIST_H
#define TODOLIST_H


#include "Task.h"
#include <vector>

class ToDoList {
private:
    std::vector<Task> tasks;
public:
    void addTask(const Task& t);
    void modifyTitle(int index, std::string newTitle);
    void modifyDescription(int index, std::string newDescription);
    void markTaskAsDone(int index); // cannot undone
    void addDueDate(int index, std::string date); // same for modify due date
    void removeDueDate(int index);
    void removeTask(int index);
    void removeAllTasks();
    const std::vector<Task>& getAllTasks() const;
    int getNumberOfTasks() const;
    // altri metodi/azioni?
};



#endif //TODOLIST_H
