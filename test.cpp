
#include <iostream>
using namespace std;

int main()
{
	try
	{
		int num;
		float num2;
		cout << "Enter a number: ";
		cin >> num;

		if (cin.fail())
		{
			throw "Not an integer!";
		}

		cout << "Enter another number: ";
		cin >> num2;

		if (cin.fail())
		{
			throw 0.0;

		}
		cout << "The sum is " << num + num2 << endl;
	}
	catch (float err)
	{
		cout << "You didnt enter a float" << endl;
	}
	catch (string err)
	{
		cout << "Something went wrong." << endl;
	}
	catch (...)
	{
		cout << "You didnt enter a float" << endl;
	}
}