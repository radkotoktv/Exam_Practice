#pragma once
class Person {
protected:
	char* name;

public:
	Person();
	Person(const char* name);
	virtual ~Person();
};

