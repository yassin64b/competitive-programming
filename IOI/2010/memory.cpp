#include <cstdio>

/*
char faceup(int i)
{
	if(i > 25)
		return (char) (i-26 + 'A');

	return (char) ((i-1) + 'A');
}*/

void play()
{
	char m[52];
	bool b[100] = {0};

	for(int i = 1; i <= 50; ++i)
	{
		m[i] = faceup(i);

		if(b[(int)m[i]])
		{
			for(int j = 1; j < i; ++j)
				if(m[i] == m[j])
				{
					faceup(i); 
					faceup(j);
					printf("%d %d\n", i, j);
				}
		}	
		else
			b[(int)m[i]] = 1;
	}

	return;
}

/*
int main()
{
	play();
	return 0;
}*/