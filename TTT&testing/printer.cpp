#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <fstream>
#include <chrono>
#include <thread>
using namespace std;

//-- interface --
class Printer {
protected:
	int _queue_size;
	std::queue<std::string> Queue;
public:
	Printer() : Queue() {};
	~Printer() {};
	virtual void inQueue() = 0;
	virtual void print() = 0;
	virtual void add(std::string str) = 0;
};

class printStr : public Printer {
protected:
	std::queue<std::string> Queue;
public:
	printStr() : Printer() {};
	~printStr() {};
	void print() {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		fstream file;
		file.open("file.txt", std::ios_base::openmode = 128);
		while (!Queue.empty()) {
			cout << "PRINT> " << Queue.front() << endl;
			file >> Queue.front();
			Queue.pop();
		}
		file.close();
		std::cout << std::endl;
	}
	void add(std::string str) {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		Queue.push(str);
		cout << "Queued:" << "[ " << str << " ]" << endl;
 	}
	void inQueue() {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		if (Queue.empty()) {
			cout << "Queue is empty" << endl;
		} else {
		cout << "Queue size: " << Queue.size() << endl;
		cout << "Next in queue: " << Queue.front() << endl;
		cout << std::endl;
		}
	}
};

int main() {
	printStr print;
	print.inQueue();
	print.add("Evan");
	print.inQueue();
	print.add("Denny");
	print.inQueue();
	print.print();
	print.inQueue();
	return 0;
}
