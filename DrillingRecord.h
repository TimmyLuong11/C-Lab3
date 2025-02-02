#ifndef DRILLING_RECORD_H
#define DRILLING_RECORD_H

#include <iostream>

const unsigned int MAX_NUMS = 16;                     // the maximum numeric fields in each record
const unsigned int MAX_STRINGS = 2;                   // the maximum string fields in each record

class DrillingRecord {

	// overloaded output operator that sends one formatted record to ostream
	friend std::ostream& operator<<(std::ostream& os, const DrillingRecord& record);

private:
	double nums[MAX_NUMS];                            // holds the numeric data, in column order
	unsigned int numCtr = 0;                          // counts the number of numbers added to the record
	std::string strings[MAX_STRINGS];                 // holds the string data, in column order
	unsigned int strCtr = 0;                          // count the number of strings added to the record
public:
	void addNum(double num);                          // puts num in array, increments counter
	void addString(std::string string);               // puts string in array, increments counter
	double getNum(unsigned int index) const;          // returns (copy of) num at index in num array
	std::string getString(unsigned int index) const;  // returns (copy of) string at index in string array
};
#endif
