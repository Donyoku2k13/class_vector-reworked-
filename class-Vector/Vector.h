#include<iostream>
using namespace std;
class vector_
{
private:
	int size;
	int *arr;
public:
	vector_();
	vector_(int size, int val);
	vector_(const vector_ &obj);//construct copy
	void push_back(int n);
	void print();
	void pop_back();
	void erase(int pos);
	void clear();
	int getSize();
	bool empty();
	int getElement(int pos);
	~vector_();
	

};