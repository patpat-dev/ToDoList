//
// Created by ylade on 15/02/2026.
//

#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include "ToDoList.h"
#include <string>

class MemoryManager {
public:
    static void saveToFile(const ToDoList& list, const std::string& filename);
    static void loadFromFile(ToDoList& list, const std::string& filename);
};



#endif //MEMORYMANAGER_H
