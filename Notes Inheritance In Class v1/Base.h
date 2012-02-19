#pragma once

class Base
{
public:
	Base(int xx=12);
	~Base(void);

	inline int getX(){return this->x;}
	inline void setX(int xx){this->x = xx;}

	void print(ostream & out);
	virtual void someMethod();

	friend ostream & operator<<(ostream & out, const Base & rhs);

private:
	int x;
};

