//
// Created by ylade on 15/02/2026.
//

#include <gtest/gtest.h>
#include "../src/ToDoList.h"
#include "../src/MemoryManager.h"
#include <fstream>

TEST(PersistenceTest, SaveAndLoadTest) {
    ToDoList saveList;
    saveList.addTask(Task("Test title", "Test desc"));

    saveList.markTaskAsDone(0); // segno completato prima di salvare

    const std::string testFile = "test_tasks.csv";

    // salvo
    ASSERT_NO_THROW(MemoryManager::saveToFile(saveList, testFile));

    // carico in una nuova lista
    ToDoList loadList;
    ASSERT_NO_THROW(MemoryManager::loadFromFile(loadList, testFile));

    // verifica dei dati corretti
    ASSERT_EQ(loadList.getNumberOfTasks(), 1);
    EXPECT_EQ(loadList.getTasks()[0].getTitle(), "Test title");
    EXPECT_EQ(loadList.getTasks()[0].getDescription(), "Test desc");
    EXPECT_EQ(loadList.getTasks()[0].getCreated(), saveList.getTasks()[0].getCreated());

    //saveList.markTaskAsDone(0);
    EXPECT_TRUE(loadList.getTasks()[0].isCompleted());

    // Pulizia file di test
    std::remove(testFile.c_str());
}

TEST(ToDoListTest, InvalidIndexTest) {
    ToDoList list;
    list.addTask(Task("Test", "Desc"));
    // verifico eccezione
    EXPECT_THROW(list.removeTask(99), std::out_of_range);
}

TEST(PersistenceTest, MissingFileTest) {
    ToDoList list;
    EXPECT_NO_THROW(MemoryManager::loadFromFile(list, "non_existent_file.csv"));
}