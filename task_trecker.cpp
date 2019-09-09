#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <tuple>
using namespace std;

enum class TaskStatus{
	NEW, IN_PROGRESS, TESTING, DONE
};

using TasksInfo = map<TaskStatus, int>;


class TeamTasks{
public:

	void AddNewTask(const string& person) {
		if (data.count(person) != 0){
			data[person][TaskStatus::NEW]++;
		} else {
			data[person][TaskStatus::NEW] = 1;
		}
	}

//!!!!изменил условие задачи
	const TasksInfo GetPersonTasksInfo(const string& person) const {
		TasksInfo res;
		for (auto x : data){
			if (x.first == person) {
				res[TaskStatus::NEW] = x.second[TaskStatus::NEW];
				res[TaskStatus::IN_PROGRESS] = x.second[TaskStatus::IN_PROGRESS];
				res[TaskStatus::TESTING] = x.second[TaskStatus::TESTING];
				res[TaskStatus::DONE] = x.second[TaskStatus::DONE];
			}
		}
		return res;
	}

	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count){
		tuple<TasksInfo, TasksInfo> res;

		if (task_count <= data[person][TaskStatus::NEW]) {

			get<0>(res)[TaskStatus::IN_PROGRESS] = task_count;

			if (data[person][TaskStatus::NEW] - task_count != 0) {
			get<1>(res)[TaskStatus::NEW] = data[person][TaskStatus::NEW] - task_count;
			}
			if (data[person][TaskStatus::IN_PROGRESS] != 0){
			get<1>(res)[TaskStatus::IN_PROGRESS] = data[person][TaskStatus::IN_PROGRESS];
			}
			if (data[person][TaskStatus::TESTING] != 0) {
			get<1>(res)[TaskStatus::TESTING] = data[person][TaskStatus::TESTING];
			}
//			if (data[person][TaskStatus::DONE] != 0) {
//			get<1>(res)[TaskStatus::DONE] = data[person][TaskStatus::DONE];
//			}

			data[person][TaskStatus::IN_PROGRESS] += task_count;
			data[person][TaskStatus::NEW] -= task_count;

		} else if (task_count <= data[person][TaskStatus::NEW] + data[person][TaskStatus::IN_PROGRESS]){

			if (data[person][TaskStatus::NEW] != 0) {
			get<0>(res)[TaskStatus::IN_PROGRESS] = data[person][TaskStatus::NEW];
			}
			if (task_count - data[person][TaskStatus::NEW] != 0) {
			get<0>(res)[TaskStatus::TESTING] = task_count - data[person][TaskStatus::NEW];
			}

			if (data[person][TaskStatus::IN_PROGRESS] - (task_count - data[person][TaskStatus::NEW]) != 0) {
			get<1>(res)[TaskStatus::IN_PROGRESS] = data[person][TaskStatus::IN_PROGRESS] - (task_count - data[person][TaskStatus::NEW]);
			}
			if (data[person][TaskStatus::TESTING] != 0) {
			get<1>(res)[TaskStatus::TESTING] = data[person][TaskStatus::TESTING];
			}
//			if (data[person][TaskStatus::DONE] != 0) {
//			get<1>(res)[TaskStatus::DONE] = data[person][TaskStatus::DONE];
//			}

			data[person][TaskStatus::TESTING] += task_count - data[person][TaskStatus::NEW];
			data[person][TaskStatus::IN_PROGRESS] -= task_count - data[person][TaskStatus::NEW];
			data[person][TaskStatus::IN_PROGRESS] += data[person][TaskStatus::NEW];
			data[person][TaskStatus::NEW] = 0;
			if (data[person][TaskStatus::NEW] == 0) {
				data[person].erase(TaskStatus::NEW);
			}
			if (data[person][TaskStatus::IN_PROGRESS] == 0) {
				data[person].erase(TaskStatus::IN_PROGRESS);
			}
			if (data[person][TaskStatus::TESTING] == 0) {
				data[person].erase(TaskStatus::TESTING);
			}
			if (data[person][TaskStatus::DONE] == 0) {
				data[person].erase(TaskStatus::DONE);
			}
		} else if (task_count < data[person][TaskStatus::NEW] + data[person][TaskStatus::IN_PROGRESS] + data[person][TaskStatus::TESTING]){

			if (data[person][TaskStatus::NEW] != 0) {
			get<0>(res)[TaskStatus::IN_PROGRESS] = data[person][TaskStatus::NEW];
			}
			if (data[person][TaskStatus::IN_PROGRESS] != 0) {
			get<0>(res)[TaskStatus::TESTING] = data[person][TaskStatus::IN_PROGRESS];
			}
			if (task_count - data[person][TaskStatus::NEW] - data[person][TaskStatus::IN_PROGRESS] != 0) {
			get<0>(res)[TaskStatus::DONE] = task_count - data[person][TaskStatus::NEW] - data[person][TaskStatus::IN_PROGRESS];
			}

			if (data[person][TaskStatus::TESTING] - (task_count - data[person][TaskStatus::NEW] - data[person][TaskStatus::IN_PROGRESS]) != 0) {
			get<1>(res)[TaskStatus::TESTING] = data[person][TaskStatus::TESTING] - (task_count - data[person][TaskStatus::NEW] - data[person][TaskStatus::IN_PROGRESS]);
			}
			if (data[person][TaskStatus::DONE] != 0) {
			get<1>(res)[TaskStatus::DONE] = data[person][TaskStatus::DONE];
			}

			data[person][TaskStatus::DONE] += task_count - data[person][TaskStatus::NEW] - data[person][TaskStatus::IN_PROGRESS];
			data[person][TaskStatus::TESTING] -= (task_count - data[person][TaskStatus::NEW] - data[person][TaskStatus::IN_PROGRESS]);
			data[person][TaskStatus::TESTING] += data[person][TaskStatus::IN_PROGRESS];
			if (data[person][TaskStatus::NEW] != 0) {
				data[person][TaskStatus::IN_PROGRESS] += data[person][TaskStatus::NEW];
			} else {
				data[person][TaskStatus::IN_PROGRESS] = 0;
			}

			if (data[person][TaskStatus::NEW] == 0) {
				data[person].erase(TaskStatus::NEW);
			}
			if (data[person][TaskStatus::IN_PROGRESS] == 0) {
				data[person].erase(TaskStatus::IN_PROGRESS);
			}
			if (data[person][TaskStatus::TESTING] == 0) {
				data[person].erase(TaskStatus::TESTING);
			}
			if (data[person][TaskStatus::DONE] == 0) {
				data[person].erase(TaskStatus::DONE);
			}
		} else if (task_count == data[person][TaskStatus::NEW] + data[person][TaskStatus::IN_PROGRESS] + data[person][TaskStatus::TESTING]){
			if (data[person][TaskStatus::NEW] != 0) {
			get<0>(res)[TaskStatus::IN_PROGRESS] = data[person][TaskStatus::NEW];
			}
			if (data[person][TaskStatus::IN_PROGRESS] != 0) {
			get<0>(res)[TaskStatus::TESTING] = data[person][TaskStatus::IN_PROGRESS];
			}
			if (data[person][TaskStatus::IN_PROGRESS] != 0) {
			get<0>(res)[TaskStatus::DONE] = data[person][TaskStatus::IN_PROGRESS];
			}

			if (data[person][TaskStatus::DONE] != 0) {
			get<1>(res)[TaskStatus::DONE] = data[person][TaskStatus::DONE];
			}

			data[person][TaskStatus::DONE] +=  data[person][TaskStatus::TESTING];
			data[person][TaskStatus::TESTING] = data[person][TaskStatus::IN_PROGRESS];
			data[person][TaskStatus::IN_PROGRESS] = data[person][TaskStatus::NEW];
			data[person][TaskStatus::NEW] = 0;

			if (data[person][TaskStatus::NEW] == 0) {
				data[person].erase(TaskStatus::NEW);
			}
			if (data[person][TaskStatus::IN_PROGRESS] == 0) {
				data[person].erase(TaskStatus::IN_PROGRESS);
			}
			if (data[person][TaskStatus::TESTING] == 0) {
				data[person].erase(TaskStatus::TESTING);
			}
			if (data[person][TaskStatus::DONE] == 0) {
				data[person].erase(TaskStatus::DONE);
			}
		} else {
			get<0>(res)[TaskStatus::IN_PROGRESS] = data[person][TaskStatus::NEW];
			get<0>(res)[TaskStatus::TESTING] = data[person][TaskStatus::IN_PROGRESS];
			get<0>(res)[TaskStatus::DONE] = data[person][TaskStatus::TESTING];

			get<1>(res)[TaskStatus::DONE] = data[person][TaskStatus::DONE];

			data[person][TaskStatus::DONE] += data[person][TaskStatus::TESTING];
			data[person][TaskStatus::TESTING] = data[person][TaskStatus::IN_PROGRESS];
			data[person][TaskStatus::IN_PROGRESS] = data[person][TaskStatus::NEW];
			data[person][TaskStatus::NEW] = 0;

			if (data[person][TaskStatus::NEW] == 0) {
				data[person].erase(TaskStatus::NEW);
			}
			if (data[person][TaskStatus::IN_PROGRESS] == 0) {
				data[person].erase(TaskStatus::IN_PROGRESS);
			}
			if (data[person][TaskStatus::TESTING] == 0) {
				data[person].erase(TaskStatus::TESTING);
			}
			if (data[person][TaskStatus::DONE] == 0) {
				data[person].erase(TaskStatus::DONE);
			}
		}
		return (res);
	}

private:
	map<string, TasksInfo> data;
};

void PrintTasksInfo(TasksInfo tasks_info){
		cout << tasks_info[TaskStatus::NEW] << " new tasks" << ", ";
		cout << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress, ";
		cout<< tasks_info[TaskStatus::TESTING] << " tasks are being tested, ";
		cout << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
	TeamTasks tasks;
	TasksInfo updated_tasks, untouched_tasks;
	  tasks.AddNewTask("Ilia");
	  for (int i = 0; i < 3; ++i) {
	    tasks.AddNewTask("Ivan");
	  }
	  cout << "Ilia's tasks: ";
	  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
	  cout << "Ivan's tasks: ";
	  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

	  tie(updated_tasks, untouched_tasks) =
	      tasks.PerformPersonTasks("Ivan", 2);
	  cout << "Updated Ivan's tasks: ";
	  PrintTasksInfo(updated_tasks);
	  cout << "Untouched Ivan's tasks: ";
	  PrintTasksInfo(untouched_tasks);

	  tie(updated_tasks, untouched_tasks) =
	      tasks.PerformPersonTasks("Ivan", 2);
	  cout << "Updated Ivan's tasks: ";
	  PrintTasksInfo(updated_tasks);
	  cout << "Untouched Ivan's tasks: ";
	  PrintTasksInfo(untouched_tasks);

	  cout << endl;
	  cout << "New examples: " << endl;

	  //AddNewTasks Alice 5
	  for (int i = 0; i < 5; ++i) {
		  tasks.AddNewTask("Alice");
	  }
	  cout << "Alice's tasks: ";
	  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

	  //PerformPersonTasks Alice 5
	  tie(updated_tasks, untouched_tasks) =
	  	      tasks.PerformPersonTasks("Alice", 5);
	  cout << "Alice's tasks: ";
	  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

	  //PerformPersonTasks Alice 5
	  tie(updated_tasks, untouched_tasks) =
	  	      tasks.PerformPersonTasks("Alice", 5);
  	  cout << "Alice's tasks: ";
  	  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

  	  //PerformPersonTasks Alice 1
  	  tie(updated_tasks, untouched_tasks) =
  	  	      tasks.PerformPersonTasks("Alice", 1);
	  cout << "Alice's tasks: ";
	  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

	  //AddNewTasks Alice 5
	  for (int i = 0; i < 5; ++i) {
		  tasks.AddNewTask("Alice");
	  }
	  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

	  //PerformPersonTasks Alice 2
	  tie(updated_tasks, untouched_tasks) =
	      tasks.PerformPersonTasks("Alice", 2);
	  cout << "Alice's tasks: ";
	  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

	  //PerformPersonTasks Alice 4
	  tie(updated_tasks, untouched_tasks) =
	      tasks.PerformPersonTasks("Alice", 4);
	  cout << "Alice's tasks: ";
	  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

	  //PerformPersonTasks Alice 5
	  tie(updated_tasks, untouched_tasks) =
	      tasks.PerformPersonTasks("Alice", 5);
	  cout << "Alice's tasks: ";
	  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

	  //PerformPersonTasks Alice 10
  	  tie(updated_tasks, untouched_tasks) =
  	      tasks.PerformPersonTasks("Alice", 10);
  	  cout << "Alice's tasks: ";
  	  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

  	  //PerformPersonTasks Alice 10
   	  tie(updated_tasks, untouched_tasks) =
  	      tasks.PerformPersonTasks("Alice", 10);
  	  cout << "Alice's tasks: ";
  	  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

  	  //AddNewTasks Alice 1
	  tasks.AddNewTask("Alice");
	  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

	  //PerformPersonTasks Alice 2
   	  tie(updated_tasks, untouched_tasks) =
   	      tasks.PerformPersonTasks("Alice", 2);
   	  cout << "Alice's tasks: ";
   	  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
/*
   	  //PerformPersonTasks Bob 3
      tie(updated_tasks, untouched_tasks) =
   	      tasks.PerformPersonTasks("Bob", 3);
   	  cout << "Bob's tasks: ";
   	  PrintTasksInfo(tasks.GetPersonTasksInfo("Bob"));
*/
   	  cout << endl;
   	  cout << "More examples:" << endl;
   	  //AddNewTasks Jack 1
   	  tasks.AddNewTask("Jack");
   	  PrintTasksInfo(tasks.GetPersonTasksInfo("Jack"));

   	  //PerformPersonTasks Jack 1
   	  tie(updated_tasks, untouched_tasks) =
   	      tasks.PerformPersonTasks("Jack", 1);
   	  cout << "Jack's tasks: ";
   	  PrintTasksInfo(tasks.GetPersonTasksInfo("Jack"));

   	  //AddNewTasks Jack 1
   	  tasks.AddNewTask("Jack");
   	  PrintTasksInfo(tasks.GetPersonTasksInfo("Jack"));

   	  //PerformPersonTasks Jack 2
   	  tie(updated_tasks, untouched_tasks) =
   	      tasks.PerformPersonTasks("Jack", 2);
   	  cout << "Jack's tasks: ";
   	  PrintTasksInfo(tasks.GetPersonTasksInfo("Jack"));

   	  //AddNewTasks Jack 1
   	  tasks.AddNewTask("Jack");
   	  PrintTasksInfo(tasks.GetPersonTasksInfo("Jack"));

   	  //PerformPersonTasks Jack 3
   	  tie(updated_tasks, untouched_tasks) =
   	      tasks.PerformPersonTasks("Jack", 3);
   	  cout << "Jack's tasks: ";
   	  PrintTasksInfo(tasks.GetPersonTasksInfo("Jack"));

  return 0;
}
