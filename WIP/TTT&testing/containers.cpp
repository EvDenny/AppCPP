#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <list>
using namespace std;

const string clone_prefix = "clone-";

class container {
protected:
	string _name;
	int _size;
	int _capacity;
	std::list<string> _list;
public:
	friend class iterator;
	container();
	container(const string & name, list<string> & list, const int & size, const int & capacity) : _name(name), _list(list), _size(size), _capacity(capacity) {
		std::cout << "Constructed w/ parmaeters: " << this->_name << endl;
	}
	container(const container & rhs) : _name(rhs._name), _list(rhs._list), _size(rhs._size), _capacity(rhs._capacity) {
		std::cout << "Copied: " << clone_prefix << this->_name << endl;
	}
	~container();
	virtual void pushback(const std::string &) = 0;
	virtual void print() const = 0;
	virtual void popback() = 0;
	virtual void pushfront(const std::string &) = 0;
};

void container::pushback(const std::string & str) {
	if (_size == _capacity) {
		std::cout << "Container is full" << endl;
		return;
	}
	_list.push_back(str);
	_size++;
}

void container::pushfront(const std::string & str) {
	if (_size == _capacity) {
		std::cout << "Container is full" << endl;
		return;
	}
	_list.push_front(str);
	_size++;
}

void container::popback() {
	if (_size == 0) {
		std::cout << "Container is empty" << endl;
		return;
	}
	_list.pop_back();
	_size--;
}

void container::print() const {
	for (auto it = _list.begin(); it != _list.end(); it++) {
		std::cout << *it << endl;
	}
}

class box : public container {
private:
	int _vsize;
	string _type;
	vector<int> _intVector;
	vector<double> _dVector;
	vector<char> _charVector;
	vector<string> _vector;
protected:
	string _name;
	int _size;
	int _capacity;
	list<string> _list;
public:
	friend class iterator;
	vector<string> getVector() const {
		return _vector;
	}
	box() : _name(""), _size(0), _capacity(this->getCapacity()), _list(), _vector(), _type() {
		cout << "Default constructor: empty (string) box object" << endl;
	}
	box(const string & name, list<string> & list, const int & size, const int & capacity, const string & type, const vector<string> & vector) : _name(name), _list(list), _size(size), _capacity(capacity), _type(type), _vector() {
		if (_type != "std::string" || _type != "string") {
			if (_type == "double") {
				std::vector<double> _dVector;
			} else if (_type == "int") {
				std::vector<int> _intVector;
			} else if (_type == "char") {
				std::vector<char> _charVector;
			}
			this->_vector.clear();
			getVector().shrink_to_fit();
		};
		cout << "Constructed w/ parmaeters: " << this->_name << endl;
	}
	box(const container &);
	box(const box & rhs) : _name(rhs._name), _list(rhs._list), _size(rhs._size), _capacity(rhs._capacity) {
		cout << "Copied: " << clone_prefix << this->_name << endl;
	}
	~box() {
		cout << _name << " destructed." << endl;
	}
	// getters //
	string getName() {
		return _name;
	}
	int getSize() {
		_size = _list.size();
		return _size;
	}
	int getCapacity() {
		if (!_vector.empty()) {
			_capacity = _vector.capacity();
		} else if (!_intVector.empty()) {
			_capacity = _intVector.capacity();
		} else if (!_charVector.empty()) {
			_capacity = _charVector.capacity();
		} else if (!_dVector.empty()) {
			_capacity = _dVector.capacity();
		}
		return _capacity;
	}
	string getListMembers() {
		int i = 0;
		for (std::list<string>::iterator it=_list.begin(); it != _list.end(); ++it) {
			cout << ++i << ". " << *it << endl;
		}
		std::list<string>::iterator it = _list.end();
		--it;
		return *it;
	}
	void popback() {
		_list.pop_back();
		_vector.pop_back();
	}
	void pushback(const string & a) {
		_list.push_back(a);
		_vector.push_back(a);
	}
	void pushfront(const string & a) {
		_list.push_front(a);
		_vector.insert(_vector.begin(), a);
	}
	void print() const {
		for (int i = 0; i < _vector.size(); i++) {
			cout << _vector[i] << endl;
		}
	}
};

int main() {
	box code;
	code.pushback("C++");
	code.pushback("is");
	code.print();
	code.getListMembers(); 
}