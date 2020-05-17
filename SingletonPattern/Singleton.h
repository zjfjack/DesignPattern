#pragma once

class Singleton
{
private:
	// it is not good to do like this
	static Singleton* instance;
	Singleton() = default;
public:
	Singleton(const Singleton&) = delete; // Delete copy constructor
	Singleton& operator=(const Singleton&) = delete; // Delete assignment operator

	static Singleton* getInstance();
	void print();
};