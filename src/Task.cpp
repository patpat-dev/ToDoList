//
// Created by ylade on 21/01/2026.
//

#include "Task.h"

Task::Task(const std::string &t, const std::string &d)
    :
        title(t),
        description(d),
        completed(false),
        created("date and time now"),
        modified("same with created")
{}

std::string Task::getTitle() const {
    return title;
}

std::string Task::getDescription() const {
    return description;
}

bool Task::isCompleted() const {
    return completed;
}

std::string Task::getCreated() const {
    return created;
}

std::string Task::getModified() const {
    return modified;
}

std::string Task::getDueDate() const {
    return dueDate;
}

void Task::setTitle(const std::string &t) {
    title = t;
}

void Task::setDescription(const std::string &d) {
    description = d;
}

void Task::setCompleted(bool c) {
    completed = c;
}

void Task::setModified(const std::string &m) {
    modified = m;
}

void Task::setDueDate(const std::string &d) {
    dueDate = d;
}

void Task::toggleCompleted() {
    completed = !completed;
}