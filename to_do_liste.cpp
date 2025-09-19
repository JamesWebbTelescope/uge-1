#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

vector<string> todo_list;
vector<string> removed_tasks;
bool validate = false; //For checking whether the input is valid or not
int command; //for receiving commands via the interface
int task_number;
bool end_program = false;
string task; //The tasks to be added

void add_task(string task)
{
    todo_list.push_back(task);
}

void remove_task(int tn)
{
    cout << todo_list.size() << "\n";
    if(todo_list.empty() == 0)
    {
        for(int i = todo_list.size()-1; i >= tn; i--)
        {
            if(i < 0)
            {
                break;
            }
            removed_tasks.push_back(todo_list.at(i));
            todo_list.pop_back();
        }
        for(int i = 0; i<=removed_tasks.size()-1; i++)
        {
            todo_list.push_back(removed_tasks.at(i));
            removed_tasks.pop_back();
        }
        while (removed_tasks.empty() == 0)
        {
            removed_tasks.pop_back();
        }
        
    }
    else
    {
        cout << "To-do list is empty\n";
    }
}

void show_all_tasks()
{
    cout << "List of tasks\n";
    for (int i = 0; i < todo_list.size(); i++)
    {
        cout << i << ". " << todo_list.at(i) <<  "\n";
    }
    
}

void mark_as_complete(int tn)
{
    string task;
    if(todo_list.empty() == 0)
    {
        task = todo_list.at(tn);
        todo_list.at(tn) = task + "(Færdig)";
    }
    else
    {
        cout << "To-do list is empty" << "\n";
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
    while (end_program == false)
    {
        cout << "What do you want to do?\n";
        cout << "1. Add task.\n2. Remove task.\n3. Show all tasks.\n4. Mark task as complete.\n5. End program.\n";
        cin >> command;
        validateInput();
        switch (command)
        {
        case 1:
            cout << "What is the task?\n";
            cin >> task;
            add_task(task);
            break;
        case 2:
            cout << "Which task do you want to remove?\n";
            cin >> task_number;
            remove_task(task_number);
            break;
        case 3:
            show_all_tasks();
            break;
        case  4:
            cout << "Which task is finished?" << "\n";
            cin >> task_number;
            mark_as_complete(task_number);
            break;
        case 5:
            end_program = true;
        default:
            break;
        }
    }
}