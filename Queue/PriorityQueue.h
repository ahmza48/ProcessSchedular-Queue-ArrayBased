#pragma once
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "Job.h"
#include <iostream>
using namespace std;

template <class T>
class PriorityQueue {
private:
	T * priorityQueue;
	int size;
	int front;
	int rear;
	int count;
public:
	PriorityQueue() {
		priorityQueue = NULL;
		size = 0;
	}
	PriorityQueue(int s) {
		size = s;
		priorityQueue = new T[size];
		front = -1;
		rear = -1;
	}
	void enqueue(T val) {
		if (isFull()) {
			resize();
			/*rear=(rear+1)%size;
			queue[rear] = val;
			count++;*/
		}
		//if (front == -1) {
		//	rear = (rear + 1) % size;
		//	priorityQueue[rear] = val;
		//	count++;
		//	return;
		//}
		if (rear == -1) {
			rear = (rear + 1) % size;
			front = (front + 1) % size;
			priorityQueue[rear] = val;
			//cout << "first val: " << val.getPriority();
			count++;
			return;
		}

		if (val.getPriority() > priorityQueue[front].getPriority()) {
			rear = (rear + 1) % size;
			for (int i = rear; i != front; i--)
			{
				priorityQueue[rear] = priorityQueue[rear - 1];
				//priorityQueue[rear] = priorityQueue[front];
			}priorityQueue[front] = val;
			//cout << "Second val: " << val.getPriority();
			/*Job temp = priorityQueue[front];*/
			/*priorityQueue[rear] = priorityQueue[front];
			priorityQueue[front] = val;*/
		}
		else {
			if (val.getPriority() < priorityQueue[front].getPriority()) {
				//priorityQueue[i + 1] = val;
				for (int i = front + 1; i <= rear; i++)
				{
					rear = (rear + 1) % size;
					if (val.getPriority() < priorityQueue[i].getPriority()) {
						//count++;
						Job temp = priorityQueue[i];
						priorityQueue[i] = val;
						priorityQueue[i + 1] = temp;
						//priorityQueue[i + 1] = val;
						//val.getPriority() < priorityQueue[i].getPriority()

					}
				}

			}



			//int count = 0;
			//cout << "FRONT: " << front << endl;
			//for (int i = front; i <= rear; i++)
			//{
			//	if (val.getPriority() < priorityQueue[i].getPriority()) {
			//		//priorityQueue[i + 1] = val;
			//		count++;
			//	}

			//}

		}


	}
	//-----------------------

	//rear = (rear + 1) % size;
	////				cout << "REAR: " << rear << endl;
	//for (int i = rear; i > count; i--)
	//{
	//	//cout << i << endl;

	//	priorityQueue[rear] = priorityQueue[rear - 1];

	//	//priorityQueue[rear] = priorityQueue[front];

	//}

	//priorityQueue[count] = val;
	//cout << "Successful: " << val.getPriority() << endl;



	void dequeue() {
		if (isEmpty()) {
			cout << "QUEUE IS EPMTY!" << endl;
		}
		//T val;
		//front = (front + 1) % size;
		//val = queue[front];
		if (front == -1) {
			front++;
		}
		front = (front + 1) % size;
		count--;
		//return val;

	}
	T peek() {
		if (!isEmpty()) {
			cout << "Size of Queue is: " << size << endl;
			cout << "Count is: " << count << endl;
			cout << "FRONT: " << front << " " << endl;
			/*	T val;
				if (front == 0) {
					return queue[front];
				}
				front = (front + 1) % size;
				val = queue[front];
				return val;
	*/
			return priorityQueue[front];

		}
		else {
			//return -1;
			cout << "EMPTY!!" << endl;
		}
		/*if (isEmpty()) {
			cout << "QUEUE IS EPMTY!" << endl;
		}
		if (front==-1)
		{
			return -1;
		}*/

	}

	bool isFull() {
		if (count == size)
		{
			return true;
		}
		else {
			return false;
		}
	}
	bool isEmpty() {
		/*if (rear == -1) {
			return true;
		}
		else {
			return false;
		}*/
		if (count == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
		/*
		return count == 0;*/
	}
	void resize() {
		int i = 0;
		T *temp = new T[size * 2];
		while (front != rear) {
			temp[i] = priorityQueue[front];
			front = (front + 1) % size;
			i++;
		}
		temp[i] = priorityQueue[front];
		size = size * 2;
		front = -1;
		rear = count - 1;
		delete[] priorityQueue;
		priorityQueue = temp;
	}

	void display() {
		if (!isEmpty())
		{
			if (front == -1) {
				front++;
			}
			for (int i = front; i <= rear; i++)
			{
				cout << "ID :" << priorityQueue[i].getId() << " ";
				cout << "Priority : " << priorityQueue[i].getPriority() << endl;
				//front = (front + 1) % size;
			}
			//int i = 0;
			///*do
			//{
			//	cout << queue[front] << " ";
			//	front = (front + 1) % size;
			//	i++;
			//} while (front != rear);
			//*/
			//while (front != rear)
			//{
			//	//cout << queue[front] << " ";
			//	front = (front + 1) % size;
			//	cout << queue[front] << " ";
			//	i++;
			//}cout << queue[front]<<" ";


			//		cout << queue[front] << " ";

				//for (int i = 0; i <= rear; i++)
				//{
				//	front = (front + 1) % size;
				//	//front = front + 1;
				//	cout << queue[front]<<" ";
				//}


		}


	}
};


int main()
{
	/*Queue<int> q1(5);
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.dequeue();
	q1.enqueue(4);
	q1.dequeue();
	q1.enqueue(5);
	q1.enqueue(6);
	q1.enqueue(7);
	q1.enqueue(8);
	q1.display();
	cout << "Peek Value is: " << q1.peek() << endl;
*/
	PriorityQueue<Job> JOBS(4);
	/*int num;
	cout << "HOW MANY JOBS YOU WANT TO ENTER? ";
	cin >> num;*/
	Job j1(1, 1), j2(2, 3), j3(3, 2), j4(4, 5);
	JOBS.enqueue(j1);
	JOBS.enqueue(j2);
	JOBS.enqueue(j3);
	JOBS.enqueue(j4);
	JOBS.display();
	cout << "Peek Value is: " << JOBS.peek().getPriority() << endl;
	return 0;
}
#endif