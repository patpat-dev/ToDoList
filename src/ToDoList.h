//
// Created by ylade on 21/01/2026.
//

#ifndef TODOLIST_H
#define TODOLIST_H


#include "Task.h"
#include <vector>
#include <limits>

class ToDoList {
private:
    std::vector<Task> tasks;
public:
    void addTask(const Task& t);
    void newTask();
    void modifyTitle(int index, std::string newTitle);
    void modifyDescription(int index, std::string newDescription);
    void markTaskAsDone(int index);
    void modifyDueDate(int index);
    void removeDueDate(int index);
    void removeTask(int index);
    void removeAllTasks();
    void showTaskDetails(int index) const;
    void showList() const;
    const std::vector<Task>& getTasks() const;
    int getNumberOfTasks() const;
    std::string inputDate() const;
};



#endif //TODOLIST_H
