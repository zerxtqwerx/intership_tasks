#pragma once
#ifndef TINK5
#define TINK5
#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct request {
	int k;
	string s;
};

bool entry(string text, string pattern) {
	int t = 0;
	if (text[0] != pattern[0]) {
		return 0;
	}
	for (int i = 0; i != pattern.length(); i++) {
		if (text[i] == pattern[i]) {
			t++;
		}
	}
	if (t == pattern.length()) {
		return 1;
	}
	else {
		return 0;
	}
}

void output(vector<string>& secondNames, vector<request>& Requests, vector<int>& Output)
{
	for (vector<request>::size_type it = 0; it != Requests.size(); it++)
	{
		int count = 0;
		vector<string>::size_type j = 0;
		for (j = 0; j != secondNames.size(); j++) {
			if (entry(secondNames[j], Requests[it].s) == 1)
			{
				count++;
				if (count == Requests[it].k) {
					break;
				}
			}
		}
		if (count > 0) {
			Output.push_back(j + 1);
		}
		else {
			Output.push_back(-1);
		}

	}
}
void Tink5()
{
	long n, q;
	vector<string> secondNames;
	string secondName;
	vector<request> Requests;
	request r;
	vector<int> Output;

	cin >> n >> q;

	for (int i = 0; i != n; i++) {
		cin >> secondName;
		secondNames.push_back(secondName);
	}

	for (int i = 0; i != q; i++) {
		cin >> r.k >> r.s;
		Requests.push_back(r);
	}

	output(secondNames, Requests, Output);

	for (vector<int>::iterator it = Output.begin(); it != Output.end(); it++) {
		cout << *it << endl;
	}

}
#endif
