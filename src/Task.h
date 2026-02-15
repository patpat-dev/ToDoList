//
// Created by ylade on 21/01/2026.
//

#ifndef TASK_H
#define TASK_H


#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <optional>

class Task {
private:
    std::string title;
    std::string description;
    bool completed;
    std::string created;
    std::string modified;
    std::string dueDate;

public:
    //costruttore
    Task(const std::string& t, const std::string& d);

    // getters
    std::string getTitle() const;
    std::string getDescription() const;
    bool isCompleted() const;
    std::string getCreated() const;
    std::string getModified() const;
    std::string getDueDate() const;

    // setters
    void setTitle(const std::string& t);
    void setDescription(const std::string& d);
    void setCompleted(bool c);
    void setModified(const std::string& m);
    void setDueDate(const std::string& d);
    void setCreated(const std::string& c);

    // metodi
    //void toggleCompleted();
    std::string getCurrentDateTime() const;
};



#endif //TASK_H
