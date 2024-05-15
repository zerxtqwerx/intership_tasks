#pragma once
#ifndef TINK2
#define TINK2
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

void Tink2()
{
	map<string, int> winners;

	int years;
	cout << "Enter a count of years" << endl;
	cin >> years;
	string name;

	for (int n = 0; n != years; n++) {
		cout << "Enter a winning team in " << n + 1 << " year." << endl;
		vector<string> names;
		for (int i = 0; i != 3; i++)
		{
			cin >> name;

			for (string::iterator i = name.begin(); i != name.end(); i++) {
				*i = toupper(*i);
			}
			names.push_back(name);
			sort(names.begin(), names.end());
		}
		string NAME = names[0] + " " + names[1] + " " + names[2];

		winners[NAME]++;
	}
	int max = 0;
	for (map<string, int>::iterator it = winners.begin(); it != winners.end(); it++) {
		if (it->second > max) {
			max = it->second;
		}
	}

	cout << max << endl;
}
#endif
