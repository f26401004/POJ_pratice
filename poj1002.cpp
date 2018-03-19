#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

char transfer(char c)
{
	if (c == 'A' || c == 'B' || c == 'C')
		return '2';
	if (c == 'D' || c == 'E' || c == 'F')
		return '3';
	if (c == 'G' || c == 'H' || c == 'I')
		return '4';
	if (c == 'J' || c == 'K' || c == 'L')
		return '5';
	if (c == 'M' || c == 'N' || c == 'O')
		return '6';
	if (c == 'P' || c == 'R' || c == 'S')
		return '7';
	if (c == 'T' || c == 'U' || c == 'V')
		return '8';
	if (c == 'W' || c == 'X' || c == 'Y')
		return '9';

}

int main()
{
	int N;
	map<string, int> data;
	while(cin >> N)
	{
		data.clear();
		cin.get();
		char buffer[256];
		int i = 0;
		for (int i = 0 ; i < N ; ++i)
		{
			int j = 0, k = 0;
			char target[7];
			fgets(buffer, sizeof(buffer), stdin);
			for (int j = 0 ; buffer[j] != '\0' ; ++j)
			{
				if (buffer[j] != '-')
					target[k++] = buffer[j] -'0' > 9 ? transfer(buffer[j]) : buffer[j];
				
			}
			target[k] = '\0';
			++data[target];
		}
		bool flag = false;
		for (map<string, int>::iterator iter = data.begin() ; iter != data.end() ; ++iter)
			if (iter->second > 1)
			{
				for (int i = 0 ; i < 7 ; ++i)
				{
					cout << iter->first[i];
					if (i == 2)
						cout << '-';
				}
				cout << " " << iter->second << endl;
				flag = true;
			}
		if (!flag)
			cout << "No duplicates." << endl;
	}
	return 0;
}
