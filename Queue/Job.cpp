#include "Job.h"
#include <iostream>
using namespace std;

Job::Job() {
	job_id = 0;
	priority = 0;
}
Job::Job(int id, int prior) {
	job_id = id;
	priority = prior;
}
void Job::setId(int id) {
	job_id = id;
}
void Job::setPriority(int prior) {
	priority = prior;
}
int Job::getId() {
	return job_id;
}
int Job::getPriority() {
	return priority;
}