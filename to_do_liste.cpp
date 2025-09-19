#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

vector<string> todo_list[];
std::vector<std::string> removed_task[];
bool validate = false; //For checking whether the input is valid or not
int command; //for receiving commands via the interface
string task; //The tasks to be added

void add_task(string task)
{
    todo_list->push_back(task);
}

void remove_task(int task_number)
{
    int size = todo_list->size();
    for(int i = size; i <= task_number; i--)
    {
        removed_task->push_back(todo_list->at(i));
        todo_list->pop_back();
    }
}

void validateInput()
{
    validate = cin.fail();
    if(validate == true)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number\n";
    }
}

void main()
{
    cout << "What do you want to do?\n";
    cout << "1. Add task.\n2. Remove task.\n3. Show all tasks.\n4. Mark task as complete.\n5. Mark task as complete.\n";
    cin >> command;
    validateInput();
    switch (command)
    {
    case 1:
        cout << "What is the task?\n";
        cin >> task;
        add_task(task);
        break;
    
    default:
        break;
    }
}