#pragma once
#ifndef TINK7
#define TINK7

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct segment {
	int beg;
	int end;
};

bool isOnly(vector<char>::iterator& begin, vector<char>::iterator& end, vector<char>::iterator& it) {
	for (begin; begin != end; begin++) {
		if (*it == *begin && it != begin) {
			return false;
		}
	}
	return true;
}

void Tink7()
{
	string s;
	vector<char> str;
	int n;
	vector<segment> segments;
	segment seg;

	cin >> s;
	cin >> n;
	for (int i = 0; i != n; i++)
	{
		cin >> seg.beg >> seg.end;
		segments.push_back(seg);
	}

	for (string::size_type h = 0; h != s.size(); h++)
	{
		str.push_back(s[h]);
	}

	vector<char> forward;
	remove_copy_if(str.begin(), str.end(), back_inserter(forward), !isOnly);
	sort(forward.begin(), forward.end());
	/*for (vector<char>::iterator ie = 0; ie != forward.size(); ie++)
	{
		for (vector<char>::iterator del = ie + 1; del != forward.size(); del++) {
			if (forward[ie] == forward[del]) {
				forward.erase(del);
			}
		}

	}*/

	for (vector<segment>::size_type c = 0; c != segments.size(); c++) {

		int globalCount = 0;
		vector<char>::iterator it = str.begin();

		for (vector<char>::iterator i = forward.begin() + segments[c].beg; i != forward.begin() + segments[c].end; i++) {
			int count = 0;

			vector<char>::iterator b = forward.begin();
			vector<char>::iterator e = forward.end();
			if (isOnly(b, e, i)) {
				for (vector<char>::iterator j = it; j != str.end(); j++) {
					if (*i == *j) {
						it = j;
						count++;
						break;
					}
					else {
						count++;
					}
				}
				globalCount += count;
			}
		}
		cout << globalCount << endl;
	}

}

#endif
