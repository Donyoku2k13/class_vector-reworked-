#include "Vector.h"

vector_::vector_()
{
	size = 0;
	arr = nullptr;
}

vector_::vector_(int size, int val)
{
	this->size = size;
	this->arr = new int[this->size];

	for (int i = 0; i < size; i++)
		this->arr[i] = val;
}

vector_::vector_(const vector_ & obj)//construct copy
{
	this->size = obj.size;
	if (size == 0)
		arr = nullptr;
	else {
		this->arr = new int[size];
		for (int i = 0; i < size; i++)
			this->arr[i] = obj.arr[i];
	}
}

void vector_::push_back(int n)
{
	if (this->size == 0)
	{
		this->size = 1;
		this->arr = new int[1];
		this->arr[0] = n;
		return;
	}
	int *tmp = new int[this->size + 1];
	for (int i = 0; i < this->size; i++)
	{
		tmp[i] = this->arr[i];
	}
	tmp[this->size] = n;
	delete[]this->arr;
	this->arr = tmp;
	this->size++;
}

void vector_::print()
{
	for (size_t i = 0; i <this->size; i++)
	{
		cout << this->arr[i] << "  ";
	}
}

void vector_::pop_back()
{
	if (this->size == 0) {
		cout << "Array`s empty\n";
		return;
	}
	int *tmp = new int[this->size - 1];
	for (size_t i = 0; i < this->size - 1; i++)
	{
		tmp[i] = this->arr[i];
	}
	delete[]this->arr;
	this->arr = tmp;
	this->size--;
}

void vector_::erase(int pos)
{
	if (this->size == 0) {
		cout << "Array`s empty\n";
		return;
	}
	else {
		int *tmp = new int[this->size - 1];
		int a = 0;
		for (size_t i = 0; i <this->size; i++)
		{
			if (i!= pos) {
				tmp[a] = this->arr[i];
				a++;
			}
		}
		delete[]this->arr;
		this->arr = tmp;
		this->size--;
	}
	
}

void vector_::clear()
{
	if (this->arr!= 0)
	{
		delete[]this->arr;
		this->size = 0;
	}
}

int vector_::getSize()
{
	return size;
}

bool vector_::empty()
{
	if (this->arr != nullptr) {
		return false;
	}
}

int vector_::getElement(int pos)
{
	if(this->size == 0)
	{
		cout << "array`s emty\n";
		return;
	}
	return arr[pos];
}
vector_ vector_::operator=(const vector_ & obj)
{
	if (this==&obj)
	{return *this;}
	this->clear();
	if (obj.arr!=nullptr)
	{
		this->arr = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			this->arr[i] = obj.arr[i];
		}
		
	}
	return *this;
}

vector_::~vector_()
{
	if (arr != nullptr) {
		delete[]this->arr;
		this->size = 0;
	}


}
