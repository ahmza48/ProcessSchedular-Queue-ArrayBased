#pragma once
#ifndef PROCESS_H
#define PROCESS_H
#include <iostream>
#include <string>
using namespace std;
class Process
{
private:
	int processId;
	string processName;
	int processExecTime;
public:
	Process() {
		processId = 0;
		processName = "";
		processExecTime = 0;
	}
	Process(int id,string name,int burstTime) {
		processId = id;
		processName = name;
		processExecTime = burstTime;
	}
	void setExeTime(int t) {
		this->processExecTime = t;
	}
	int getId() {
		return processId;
	}
	string getName() {
		return processName;
	}
	int getExeTime() {
		return processExecTime;
	}
};
#endif

