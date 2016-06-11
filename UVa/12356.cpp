#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);

	int S, B;
	vector<int> left(100000+2), right(100000+2);
	while(cin >> S >> B && (S || B))
	{
		for(int i = 1; i <= S; ++i)
			left[i] = i-1, right[i] = i+1;

		for(int i = 0; i < B; ++i)
		{
			int L, R;
			cin >> L >> R;
		
			if(left[L] > 0)
				cout << left[L] << ' ';
			else
				cout << "* ";

			if(right[R] <= S)
				cout << right[R] << '\n';
			else
				cout << "*\n";

			left[right[R]] = left[L];
			right[left[L]] = right[R];
		}


		cout << '-' << endl;
	}
}