#include "CFraction.h"

int main()
{
	CFraction a(1,2), b(2,3), c;
	CFraction d = b;
	CFraction e = 3;
	e = a;

	if(operator==(a,b))
		cout << "Yupp"<< endl;

	if(b != a)
		cout << "Yupp" << endl;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;
	cout << "e: " << e << endl;

	string ch;
	getline(cin, ch);

	return 0;
}// end
