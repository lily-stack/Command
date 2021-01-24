#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>    
#include "TodoListInterface.h"

using namespace std;

class TodoList : public TodoListInterface {
public:
	vector <string> tasks;
	TodoList() {
		cout << "In Constructor" << endl;
		ifstream infile("TODOList.txt");
		string line;
		if (infile.is_open())
		{
			while (getline(infile, line))
			{
				cout << line << '\n';
				tasks.push_back(line);
			}
			infile.close();
		}
	}
	virtual ~TodoList() {
		cout << "In Destructor" << endl;
		ofstream outfile;
		outfile.open("TODOList.txt", ofstream::out | ofstream::trunc);
		for (int i = 0; i < tasks.size(); i++) {
			cout << tasks[i] << '\n';
			outfile << tasks[i] << endl;
		}
		outfile.close();

	}

	/*
	*   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
	*/
	virtual void add(string _duedate, string _task) {
		cout << "In add " << _duedate << " " << _task << endl;
		tasks.push_back(_duedate + " " + _task);
	}

	/*
	*   Removes an item from the todo list with the specified task name
	*
	*   Returns 1 if it removes an item, 0 otherwise
	*/
	virtual int remove(string _task) {
		cout << "In remove " << tasks.size() << endl;
		cout << "This is the task to remove: " << _task << endl;
		for (int i = 0; i < tasks.size(); ++i) {
			int taskIndex = tasks[i].find(_task);
			if (taskIndex != -1) {
				cout << "This is the task " << tasks[i] << endl;
				tasks.erase(tasks.begin() + i);
				return 1;
			}
		}
		return 0;
	}

	/*
	*   Prints out the full todo list to the console
	*/
	virtual void printTodoList() {
		cout << "In list" << endl;
		for (int i = 0; i < tasks.size(); i++) {
			int spaceIndex = tasks[i].find(" ");
			for (int j = 0; j < tasks[i].size(); ++j) {
				if (j > spaceIndex) {
					cout << tasks[i][j];
				}
			}
			cout << endl;
		}
	}

	/*
	*   Prints out all items of a todo list with a particular due date (specified by _duedate)
	*/
	virtual void printDaysTasks(string _date) {
		cout << "In DaysTasks" << endl;
		for (int i = 0; i < tasks.size(); i++) {
			int dayIndex = tasks[i].find(_date);
			if (dayIndex != -1) {
				cout << tasks[i] << endl;
			}
		}
	}
};

#endif