#pragma once

// https://stackoverflow.com/a/1008289/5514452
class SingletonOnline
{
private:
	SingletonOnline() = default;

public:
	SingletonOnline(const SingletonOnline&) = delete; // Delete copy constructor
	SingletonOnline& operator=(const SingletonOnline&) = delete; // Delete assignment operator

	static SingletonOnline& getInstance();
public:
	void print();
};