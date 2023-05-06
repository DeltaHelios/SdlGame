#include <iostream>
#include <random>
#include <ctime>
using namespace std;
const int BEH_HEALTH = 500;
const int DRAG_HEALTH = 500;
const int BEH_ATTACK = 10;
const int DRAGON_ATTACK = 15;
int main()
{
	default_random_engine randomGenerator(time(NULL));
	uniform_int_distribution<int> DragonRoll(0,DRAGON_ATTACK);
	uniform_int_distribution<int> BehemothRoll(0,BEH_ATTACK);
	int DragonCnt, BehCnt;
	cout << "How many dragons are there? ";
	cin >> DragonCnt;
	cout << "\nHow many behemots are there? ";
	cin >> BehCnt;
	int dhealth = DRAG_HEALTH;
	int bhealth = BEH_HEALTH;
//	cout << "\n *Battle Noises*\n";
	while (DragonCnt>0&&BehCnt>0) {
		bhealth -=DragonRoll(randomGenerator);
		//cout << " Beh has " << bhealth << " health left.\n";
		if (bhealth <= 0) {
			BehCnt--;
			bhealth = BEH_HEALTH;
		//	cout << "Beth died.\n";
		}
		
		dhealth -=BehemothRoll(randomGenerator);
	//	cout << " Dragon has " << dhealth << " health left.\n";
		if (dhealth <= 0) {
			DragonCnt--;
			dhealth = DRAG_HEALTH;
		///	cout << "Dwagon died :c \n";
		}
	}
	if (DragonCnt < BehCnt) {
		cout << "Behemoths won!\n";
	}
	else {
		cout << "Dragons won!\n";
	}
	cout << "There are " << DragonCnt << " dragons left and " << BehCnt << " behemoths left.\n";


}

