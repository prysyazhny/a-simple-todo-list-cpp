
#pragma once

#include <string>
#include <vector>
#include <iostream>

class TodoList
{
private:
    std::vector<std::pair<std::string, bool>> tasks;
public:
    void add(const std::string &task);
    void complete(const std::string &task);

    void all() const;
    void complete() const;
    void incomplete() const;

    void clear();

    // for testing 

    std::vector<std::pair<std::string, bool>> getTasks() const {
        return tasks;
    }

    std::vector<std::pair<std::string, bool>> getIncompleteTasks() const {
        std::vector<std::pair<std::string, bool>> incompleteTasks;
        for (const auto &task : tasks) {
            if (!task.second) {
                incompleteTasks.push_back(task);
            }
        }
        return incompleteTasks;
    }

    std::vector<std::pair<std::string, bool>> getCompleteTasks() const {
        std::vector<std::pair<std::string, bool>> completeTasks;
        for (const auto &task : tasks) {
            if (task.second) {
                completeTasks.push_back(task);
            }
        }
        return completeTasks;
    }
};