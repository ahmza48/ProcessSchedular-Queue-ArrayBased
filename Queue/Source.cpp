#include <iostream>
#include "Process.h"
using namespace std;


template <typename T>
class Queue {	//Schedular
private:
	T * queue;
	//int processArrayLength;
	//int timeQuantum;

	int size;
	int front;
	int rear;
	int count;
public:
	Queue() {
		size = 0;
		queue = nullptr;
		front = rear = -1;
		count = 0;
		//processArrayLength = 0;
		//timeQuantum = 0;
	}
	Queue(int s) {
		size = s;
		queue = new T[size];
		front = -1;
		rear = -1;
	}
	void setSize(int s) {
		size = s;
		queue = new T[size];
		front = -1;
		rear = -1;
	}
	void setProcess(int s) {
		size = s;
		queue = new T[size];
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
		if (front == -1) {
			front++;
		}
		rear = (rear + 1) % size;
		queue[rear] = val;
		count++;
		
	}
	void dequeue() {
		if (isEmpty()) {
			cout << "QUEUE IS EPMTY!" << endl;
		}
		//T val;
		//front = (front + 1) % size;
		//val = queue[front];
		//if (front == -1) {
		//	front++;
		//}
		front = (front + 1) % size;
		count--;
		//return val;

	}
	T& peek() {
		if (!isEmpty()) {
			//cout << "Size of Queue is: " << size << endl;
			//cout << "Count is: " << count << endl;
			//cout << "FRONT: " << front << " " << endl;
		/*	T val;
			if (front == 0) {
				return queue[front];				
			}
			front = (front + 1) % size;
			val = queue[front];
			return val;
			*/
			return queue[front];

		}
		else {
			cout << "Empty!" << endl;
			//return -1;
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
		if (count==size)
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
		if (count==0)
		{
			return true;
		}
		else {
			return false;
		}
		/*
		return count == 0;*/
	}
	void resize() {
		int i = 0;
		T *temp = new T[size * 2];
		while (front!=rear) {
			temp[i] = queue[front];
			front = (front + 1) % size;
			i++;
		}
		temp[i] = queue[front];
		size = size * 2;
		front = -1;
		rear = count - 1;
		delete[] queue;
		queue = temp;
	}
	void display() {
		if (!isEmpty())
		{
			if (front == -1) {
				front++;
			}
			for (int i = front; i <= rear; i++)
			{
				cout << queue[i] << " ";
				//front = (front + 1) % size;
			}
		}


	}

};

//-----------------------------------------------------------------------------------------------------
class Schedular
{
private:
	Queue<Process> processArray;
	int processArrayLength;
	int timeQuantum;
public:
	Schedular(Process*p, int procArrLen, int quantum) {
		processArray.setSize(procArrLen);
		for (int i = 0; i < procArrLen; i++)
		{
			processArray.enqueue(p[i]);
		}
/*
		processArray.enQueue(p[3])*/
		
		processArrayLength = procArrLen;
		timeQuantum = quantum;
	}
	void assignProcessor() {
		while (!processArray.isEmpty())
		{
			/*for (int i = front; i <= rear; i++)
			{

			}*/
			if (processArray.peek().getExeTime() > 0)
			{
				
				cout << "Process to be executing is: " << endl;
				cout << processArray.peek().getId() << endl;
				cout << processArray.peek().getName() << endl;
				cout << processArray.peek().getExeTime() << endl;
				int time = processArray.peek().getExeTime() - timeQuantum;
				cout << '\n' << time << '\n';
				processArray.peek().setExeTime(time);
				cout <<"before processing: " <<processArray.peek().getExeTime()<<'\n';
				if (processArray.peek().getExeTime() <= 0)
				{
					processArray.dequeue();
				}
				else {
					Process temp = processArray.peek();
					cout << "Time while processing: ";
					cout << temp.getExeTime() << '\n';
					processArray.dequeue();
					processArray.enqueue(temp);

				}

				/*processArray[rear] = processArray[i].peek();
				processArray[i].dequeue();*/
				
				//processArray[i].peek().setExeTime(processArray[i].peek().getExeTime() - timeQuantum);
				//processArray[rear] = processArray[i].peek();
				//processArray[i].dequeue();
			}
		}
	}
};

//---------------------------------------------------------------------------------------------------------

int main() 
{
	Process arr[4] = {
		Process(1,"notepad",20),
		Process(13,"mp3Player",5),
		Process(4,"bcc",30),
		Process(11,"explorer",2)
	};
	Schedular s(arr, 4, 5);
	s.assignProcessor();

	/*queue<int> q1(5);
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
	cout << "peek value is: " << q1.peek() << endl;*/


	return 0;
}