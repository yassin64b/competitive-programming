#include "grader.h"
#include "memory.h"

/*
#include <cstdio>

char faceup(int i)
{
	if(i > 25)
		return (char) (i-26 + 'A');

	return (char) ((i-1) + 'A');
}*/

void play()
{
	char m[52];
	bool b[100] = {0}, isup = false;

	for(int i = 1; i <= 50; ++i)
	{
		if(!isup) isup = true;
		else isup = false;
		
		m[i] = faceup(i);

		if(b[(int)m[i]])
		{
			for(int j = 1; j < i; ++j)
				if(m[i] == m[j])
				{
					if(!isup) 
						faceup(i);

					faceup(j);
					isup = false;
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
