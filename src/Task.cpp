//
// Created by ylade on 21/01/2026.
//

#include "Task.h"

Task::Task(const std::string &t, const std::string &d)
    :
        title(t),
        description(d),
        completed(false),
        created(getCurrentDateTime()),
        modified(getCurrentDateTime()),
        dueDate("0000-00-00")
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
    modified = getCurrentDateTime();
}

void Task::setDescription(const std::string &d) {
    description = d;
    modified = getCurrentDateTime();
}

void Task::setCompleted(bool c) {
    completed = c;
    modified = getCurrentDateTime();
}

void Task::setModified(const std::string &m) {
    modified = m;
}

void Task::setDueDate(const std::string &d) {
    dueDate = d;
    modified = getCurrentDateTime();
}
/*
void Task::toggleCompleted() {
    completed = !completed;
    modified = getCurrentDateTime();
}
*/
std::string Task::getCurrentDateTime() const {
    std::time_t now = std::time(nullptr);
    std::tm* t = std::localtime(&now);

    std::ostringstream oss;
    oss << std::put_time(t, "%Y-%m-%d %H:%M:%S");

    return oss.str();
}