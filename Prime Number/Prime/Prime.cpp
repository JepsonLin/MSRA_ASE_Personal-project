#include <iostream>
using namespace std;
#define MAXLEN1 2038074744
#define MAXLEN2 100000001

unsigned int Prime(unsigned int n){
	unsigned int lastPrimeIndx;
	unsigned int dataTemp;

	bool *pbFlag = new bool[MAXLEN1];
	unsigned int *prime = new unsigned int[MAXLEN2];


	if (n < 1 || n > MAXLEN2)
	{
		return 0;
	}
	for (unsigned int i = 0; i < MAXLEN1; i++)
	{
		pbFlag[i] = false;
	}
	lastPrimeIndx = 0;
	for (unsigned int count = 2; count < MAXLEN1; count++)
	{
		if (!pbFlag[count])
		{
			if (lastPrimeIndx == n - 1)
			{
				return count;
			}
			if (lastPrimeIndx <= MAXLEN2)
			{
				prime[lastPrimeIndx++] = count;
			}
		}
		dataTemp = (MAXLEN1 - 1) / count;
		for (unsigned int count1 = 0; count1 < lastPrimeIndx && prime[count1] <= dataTemp; count1++)
		{
			pbFlag[count * prime[count1]] = true;
			if (!(count % prime[count1]))
			{
				break;
			}
		}
	}
	return 0;
}

int main()
{
	cout << "Input: one number N in decimal, 1 <= N <= 100,000,000:" << endl;
	unsigned int n;
	cin >> n;
	n = Prime(n);
	if (n != 0)
	{

		cout << "the Nth prime in decimal " << endl
			<< n << endl;
	}
	system("pause");
	return 0;
}