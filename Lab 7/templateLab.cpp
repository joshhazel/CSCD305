#include "MyArray.h"
#include "Simple.h"
#include <algorithm>

template <typename T>
void Swap(T& x,T& y)
{
     T temp;
     temp=x;
     x=y;
     y=temp;
}


int main()
{

	/*===========================================================
	  ================ Template Lab Part A ======================
	  ===========================================================*/
	/* You need to write the swap function in this file
	   Put your code above the main function
	   
	   NOTE: it is Capital S Swap -- otherwise the built-in swap gets
	   called and that will really mess with you*/

	cout << "PART A " << endl;

	int a = 5, b = 6;
	double c = 7.8, d = 8.9;
	string e = "stu", f = "amack";
	Simple g, h(35);

	cout << "Before swap -- a: " << a << " b: " << b << endl;
	Swap(a, b);
	cout << "After swap -- a: " << a << " b: " << b << endl;

	cout << endl;

	cout << "Before swap -- c: " << c << " d: " << d << endl;
	Swap(c, d);
	cout << "After swap -- c: " << c << " d: " << d << endl;

	cout << endl;

	cout << "Before swap -- e: " << e << " f: " << f << endl;
	Swap(e, f);
	cout << "After swap -- e: " << e << " f: " << f << endl;

	cout << endl;

	cout << "Before swap -- g: " << g << " h: " << h << endl;
	Swap(g, h);
	cout << "After swap -- g: " << g << " h: " << h << endl;

	cout << endl << endl;
	/*===========================================================
	  ================ Template Lab Part B ======================
	  ===========================================================*/

	/* You need to write the MyArray class.  The MyArray class has a
	constructor that takes an integer > 0 if that int is not > 0 then
	the default is 5. 

	You will need to overload the input operator, the output 
	operator as separate functions not inline

	You must write the constructor, destructor, copy constructor, 
	and getSize as inline functions

	You must write the assignment operator and plus operator as
	member functions just not inline.

	MyArray contains 2 private data members
	T * theArray and int size */
	cout << "PART B " << endl;
	/*===========================================================
	  ====== Play with integers in MyArray ======================
	  ===========================================================*/
	MyArray<int> w, x(4), temp;
	cout << "Please enter " << w.getSize() << " integers" << endl;

	cin >> w;

	cout << "Your array contains " << endl;
	cout << w << endl;


	cout << "Please enter " << x.getSize() << " integers" << endl;
	cin >> x;

	cout << "Your array contains " << endl;
	cout << x << endl;

	temp = w + x;

	cout << "Your array contains " << endl;
	cout << temp << endl;


	/*===========================================================
	  ====== Play with Simples in MyArray ======================
	  ===========================================================*/
	MyArray<Simple>y(2), z(3), temp2;
	cout << "Please enter " << y.getSize() << " Simples" << endl;
	cin >> y;

	cout << "Your array contains " << endl;
	cout << y << endl;

	cout << "Please enter " << z.getSize() << " Simples" << endl;
	cin >> z;

	cout << "Your array contains " << endl;
	cout << z << endl;

	temp2 = y + z;

	cout << "Your array contains " << endl;
	cout << temp2 << endl;


	/*===========================================================
	  ============ Stuff needed for debugging ===================
	  ===========================================================*/
	string s;
	getline(cin, s);

	getline(cin, s);

	return 0;


}// end main