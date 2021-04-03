#include <iostream>
#include <Windows.h>
#include "Miner.h"

using namespace std;

void main()
{
	Miner* miner = new Miner();

	int input;

	for (int i = 0; i < 20; i++)
	{
		cout << "1. Full of gold" << endl; // 금덩이 가득 참
		cout << "2. The amount is more than the target value" << endl; // 은행에 보관된 금덩이가 목표치 이상
		cout << "3. The amount is below the target value" << endl; // 은행에 보관된 금더잉가 목표치 이하
		cout << "4. Fatigue recovery" << endl; // 피로회복
		cout << "5. Thirsty" << endl; // 목마름
		cout << "6. Not thirsty" << endl; // 목마르지 않음
			do
			{
				cin >> input;
			} while (input < 0 || input > 6);
		miner->Update(input);
		cout << endl;
		Sleep(1000);
	}
	system("Pause");

}