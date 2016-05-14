#include <iostream>
using namespace std;
int main()
{
	int a, b, num, carry;

	while(cin >> a >> b && (a || b))
	{
		num = carry = 0;

		while(a || b)
		{
			if(a % 10 + b % 10 + carry > 9)
				carry = 1, ++num;
			else
				carry = 0;

			a /= 10, b /= 10;
		}
		cout << (num ? std::to_string(num) : "No") << " carry operation" 
			<< (num > 1 ? "s." : ".") << endl;
	}
}