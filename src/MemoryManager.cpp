//
// Created by ylade on 15/02/2026.
//

#include "MemoryManager.h"
#include <fstream>
#include <sstream>

void MemoryManager::saveToFile(const ToDoList &list, const std::string &filename) {
    std::ofstream outFile(filename);

    if (!outFile) {
        //throw std::runtime_error("Error: cannot open the file.");
        std::cerr << "\nError: could not find or open the file." << std::endl;
    }

    for (const auto& task : list.getTasks()) {
        outFile << task.getTitle() << ";"
                << task.getDescription() << ";"
                << (task.isCompleted() ? "1" : "0") << ";"
                << task.getDueDate() << ";"
                << task.getCreated() << ";"
                << task.getModified() << "\n";

    }
    outFile.close();
}

void MemoryManager::loadFromFile(ToDoList &list, const std::string &filename) {
    std::ifstream inFile(filename);
    if (!inFile) return;

    list.removeAllTasks();
    std::string line;

    while (std::getline(inFile, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);;
        std::string title, desc, status, dueDate, created, modified;

        std::getline(ss, title, ';');
        std::getline(ss, desc, ';');
        std::getline(ss, status, ';');
        std::getline(ss, dueDate, ';');
        std::getline(ss, created, ';');
        std::getline(ss, modified, ';');

        if (!title.empty()) {
            Task loadedTask(title, desc);

            loadedTask.setCompleted(status == "1");
            loadedTask.setDueDate(dueDate);
            loadedTask.setCreated(created);
            loadedTask.setModified(modified);

            list.addTask(loadedTask);
        }
    }
    inFile.close();
}
