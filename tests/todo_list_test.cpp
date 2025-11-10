#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/todo_list.hpp"

TEST_CASE( "it adds tasks to the todo list" ) {
    TodoList list;
    list.add("Task 1");
    list.add("Task 2");

    REQUIRE( list.getTasks().size() == 2 );
    REQUIRE( list.getTasks()[0].first == "Task 1" );
    REQUIRE( list.getTasks()[0].second == false );
    REQUIRE( list.getTasks()[1].first == "Task 2" );
    REQUIRE( list.getTasks()[1].second == false );
}

TEST_CASE( "it marks tasks as complete" ) {
    TodoList list;
    list.add("Task 1");
    list.add("Task 2");

    list.complete("Task 1");

    REQUIRE( list.getTasks()[0].second == true );
    REQUIRE( list.getTasks()[1].second == false );
}

TEST_CASE( "it clears the todo list" ) {
    TodoList list;
    list.add("Task 1");
    list.add("Task 2");

    list.clear();

    REQUIRE( list.getTasks().empty() );
}

TEST_CASE( "it retrieves incomplete tasks" ) {
    TodoList list;
    list.add("Task 1");
    list.add("Task 2");
    list.complete("Task 1");

    auto incompleteTasks = list.getIncompleteTasks();

    REQUIRE( incompleteTasks.size() == 1 );
    REQUIRE( incompleteTasks[0].first == "Task 2" );
    REQUIRE( incompleteTasks[0].second == false );
}

TEST_CASE( "it retrieves complete tasks" ) {
    TodoList list;
    list.add("Task 1");
    list.add("Task 2");
    list.complete("Task 1");

    auto completeTasks = list.getCompleteTasks();

    REQUIRE( completeTasks.size() == 1 );
    REQUIRE( completeTasks[0].first == "Task 1" );
    REQUIRE( completeTasks[0].second == true );
}
