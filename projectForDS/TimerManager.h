#pragma once
#include"MyListQueue.h"
#include<functional>
#include<chrono>
#include<thread>
#include<future>
using namespace std;
class Task
{
public:
	Task(function<void()> task, int timer = 50) {
		this->task = task;
		this->timer = chrono::milliseconds(timer);
	};
	Task() {
	
	}
	~Task() {
		
	};


	function<void()> task;
	chrono::milliseconds timer;

};


class TimerManager
{
public:
	TimerManager() { };
	~TimerManager() { };
	void start(){
		while (!tasks.isEmpty()) {
			Task task = tasks.GetFront();
			if (chrono::steady_clock::now() - t >= task.timer) {
				auto func = task.task;
				func();
				tasks.poll();
			}
			//this_thread::sleep_for(task.timer);
			
		}
	};
	void commit(function<void()> func, int timer) {
		Task t(func, timer);
		tasks.push(t);
	}
private:
	MyListQueue<Task> tasks;
	chrono::steady_clock::time_point t = chrono::steady_clock::now();
};

