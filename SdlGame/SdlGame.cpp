#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int main()
{
	default_random_engine randomGenerator(time(NULL));
	uniform_real_distribution<float> atticRoll(0.0f, 1.0f);
	int health = 100;
	int cnt = 0;
	while (true) {
		float attack = atticRoll(randomGenerator);
		if (attack > 0.3f) {
			cout << "I misseed the snake oh noooooooooooooooooooooooooooooooooooooooooooo\n";
		}
		else {
			cout << "I hit the snake yassssssssssssssssssssssssssssssssssssssss.\n";
			health -= 10;
		}
		cnt++;
		if (health == 0) {
			cout << "Dah snek is ded\n";
			cout << "Took you " << cnt << " hits ya loser. Get better dexterity.";
			break;
		}
	}

}

