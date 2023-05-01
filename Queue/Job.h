#pragma once
#ifndef JOB_H
#define JOB_H
class Job
{
private:
	int job_id;
	int priority;
public:
	Job();
	Job(int,int);
	void setId(int);
	void setPriority(int);
	int getId();
	int getPriority();

};
#endif
