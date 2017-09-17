#pragma once
#include <iostream>

template <typename type>
class Array {
protected:
	type* data;
	long base;
	unsigned long length;
public:
	/// <summary>
	/// One-dimensional array
	/// </summary>
	/// <param name="newLength">Length</param>
	/// <param name="newBase">Base</param>
	Array(long newLength, long newBase) {
		lengt = newLength;
		base = newBase;
		data = new type[length];
	}

	Array(long newLength) {
		length = newLength;
		data = new type[length];
		base = 0l;
	}

	~Array() {
		delete[] data;
	}

	int getLength() {
		return length;
	}

	int getBase() {
		return base;
	}
	
	void printArray() {
		for (unsigned long i = 0; i < length; i++)
			std::cout << "data[" << i << "]: " << data[i] << std::endl;
	}
	
	Array<type>& operator=(Array<type>& another) {
		if (&another != this) {
			if (length != another.getLength()) {
				if (data)
					delete[] data;
				length = another.getLength();
				data = new type[length];
			}
			for (unsigned long i = 0; i < length; i++)
				data[i] = another[i];
			base = another.getBase();
		}
		return *this;
	}

	type& operator[](unsigned long index) {
		unsigned long offset = index - base;
		if (offset >= length)
			throw new std::exception("index out of bounds");
		return data[offset];
	}

	void changeLength(unsigned long newLength) {
		if (length != newLength) {
			type* newData = new type[newLength];
			int smaller = length;
			if (smaller > newLength)
				smaller = newLength;
			for (unsigned long i = 0; i < smaller; i++)
				newData[i] = data[i];
			delete[] data;
			data = newData;
		}
	}
};