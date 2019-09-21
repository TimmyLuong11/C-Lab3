#include "DrillingRecordArray.h"

//Constructs array with default capacity
DrillingRecordArray::DrillingRecordArray()
{
	this->data = new DrillingRecord[this->capacity];
}

//Constructs array with specified capacity
DrillingRecordArray::DrillingRecordArray(unsigned int capacity)
{
	this->data = new DrillingRecord[capacity];
	this->capacity = capacity;
}

//Frees array space as object is deleted
DrillingRecordArray::~DrillingRecordArray()
{
	delete[] this->data;
	this->data = NULL;
}

//Adds record, increments size, doubles capacity as necessary
void DrillingRecordArray::add(DrillingRecord record)
{
	if (size < capacity)
	{
		data[size] = record;
		++size;
	}
	else
	{
		int range = size;
		capacity *= 2;
		DrillingRecord* drillingRecord = new DrillingRecord[capacity];
		for (int index = 0; index < range; ++index)
		{
			drillingRecord[index] = data[index];
		}
		data = drillingRecord;
		data[size] = record;
		++size;
	}
}

//Returns (copy of) record at index
DrillingRecord DrillingRecordArray::get(unsigned int index) const
{
	return data[index];
}
