#pragma once
#ifndef TINK4
#define TINK4
#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<map>

using namespace std;

bool isNumeric(std::string const& str)
{
	auto it = str.begin();
	if (*it == '-') {
		it++;
	}
	while (it != str.end() && std::isdigit(*it)) {
		it++;
	}

	return !str.empty() && it == str.end();
}

void breakdown(vector<string>::iterator& it, string& variable, string& value) {
	bool eqFlag = 0;

	for (int j = 0; j != (*it).size(); j++) {

		if ((*it)[j] != '=' && eqFlag == 0) {
			variable += (*it)[j];
		}
		else if ((*it)[j] == '=') {
			eqFlag = 1;
		}
		else if ((*it)[j] != '=' && eqFlag == 1) {

			value += (*it)[j];

		}

	}
}
void output(map<string, vector<int> >& Var, string& variable) {
	map<string, vector<int> >::iterator iter = Var.find(variable);

	vector<int>::size_type i = iter->second.size() - 1;

	std::cout << iter->second[i] << endl;
}

void handler(vector<string>& input, map<string, vector<int> >& Var)
{
	map<int, vector<string> > Changes;

	int beginFlag = 0;

	for (vector<string>::iterator it = input.begin(); it != input.end() - 1; it++) {


		if ((*it) == "{") {
			beginFlag++;
		}
		else if ((*it) == "}") {

			for (map<int, vector<string> >::iterator ch = Changes.begin(); ch != Changes.end(); ch++) { //Changes {1 <"a", "b">}
				if (ch->first == beginFlag) { //beginFlag == 1                                         //Var{ "a" <1, 2>, "b" <2, 4>}
					for (vector<string>::iterator i = ch->second.begin(); i != ch->second.end(); i++) {
						string v = *i;
						map<string, vector<int> >::iterator del = Var.find(v);

						if (del->second.size() != 0) {
							del->second.pop_back();
							if (del->second.size() == 0) {
								del->second.push_back(0);
							}
						}
						else {
							del->second.push_back(0);
						}
					}
					Changes[beginFlag].clear();
					break;
				}
			}
			beginFlag--;
		}
		else {
			bool eqFlag = 0;
			string variable, value;
			string sValue;
			int iValue = 0;

			breakdown(it, variable, value);

			if (beginFlag == 0) {

				if (isNumeric(value)) {
					iValue = stoi(value);

					if (Var[variable].size() != 0) {

						Var[variable].pop_back();
						Var[variable].push_back(iValue);
					}
					else { Var[variable].push_back(iValue); }
				}
				else { //value==string
					map<string, vector<int> >::iterator iterator = Var.find(value);

					if (Var.find(variable) == Var.end()) { //if variable is not exist //вставляет ноль потому что а - единственный элемент
						if (iterator != Var.end()) { //if value exist

							vector<int>::size_type i = iterator->second.size() - 1;
							Var[variable].push_back(iterator->second[i]);
						}
						else {//if value is not exist
							Var[variable].push_back(0);
							Var[value].push_back(0);
						}

					}
					else { //if variable exist   //in general error
						if (Var.find(variable) != Var.end()) {

							map<string, vector<int> >::iterator del = Var.find(variable);
							int i = del->second.size() - 1;
							int n = iterator->second.size() - 1;

							if (i >= 0) {
								Var[variable].pop_back();
							}

							if (n >= 0) { //if value exist
								Var[variable].push_back(iterator->second[n]);
							}
							if (n < 0) { // if value is not exist
								Var[variable].push_back(0);
							}
						}
					}
					output(Var, variable);
				}


			}
			else if (beginFlag > 0) {
				if (isNumeric(value)) {
					iValue = stoi(value);

					Var[variable].push_back(iValue);
				}
				else {

					map<string, vector<int> >::iterator iterator = Var.find(value);
					//if value exists


					if (iterator != Var.end()) {
						vector<int>::size_type i = iterator->second.size() - 1;
						Var[variable].push_back(iterator->second[i]);
					}

					else {
						Var[variable].push_back(0);
						Var[value].push_back(0);
					}

					output(Var, variable);
				}

				Changes[beginFlag].push_back(variable);
			}

		}
	}
	Changes.clear();
}

int Tink4()
{
	string s;
	vector<string> input;
	map<string, vector<int> > Var;

	while (cin) {
		getline(cin, s);
		input.push_back(s);
	}
	handler(input, Var);
}
#endif
