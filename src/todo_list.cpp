#include "todo_list.hpp"

void TodoList::add(const std::string &task)
{
    tasks.push_back({task, false});
}

void TodoList::all() const
{
   // pretty prints a list of all tasks
   std::cout << "\nAll tasks:" << std::endl;
    if (tasks.empty())
    {
        std::cout << "The todo list is empty." << std::endl;
        return;
    }

    for (const auto &task : tasks)
    {
        std::cout << (task.second ? "[x] " : "[ ] ") << task.first << std::endl;
    }
}

void TodoList::complete() const
{
    // Pretty prints the completed tasks
    std::cout << "\nCompleted tasks:" << std::endl;
    for (const auto &task : tasks)
    {
        if (task.second)
        {
            std::cout << "[x] " << task.first << std::endl;
        }
    }
}

void TodoList::complete(const std::string &task)
{
    // marks the task as completed
    for (auto &t : tasks)
    {
        if (t.first == task)
        {
            t.second = true;
            break;
        }
    }
}

void TodoList::incomplete() const
{
    // Pretty prints the incomplete tasks
    std::cout << "\nIncomplete tasks:" << std::endl;
    for (const auto &task : tasks)
    {
        if (!task.second)
        {
            std::cout << "[ ] " << task.first << std::endl;
        }
    }
}

void TodoList::clear()
{
    tasks.clear();
}