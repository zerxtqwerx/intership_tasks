#pragma once
#ifndef TINK6
#define TINK6

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct lift {
	int s;
	int f;
};
struct cell
{
	int y;
	int x;
};

bool sorting(lift& a, lift& b)
{
	if (a.s != a.f) {
		return a.s < b.s;
	}
	else {
		return a.f < b.f;
	}
}

//template <class It, class T> It find_s(It begin, It end, T seekF)
//{
//	while (begin != end) {
//		if (begin->s == seekF) {
//			return begin;
//		}
//		
//		begin++;
//		
//	}
//	return begin - 1;
//}



//int handler(vector<lift>& lifts) {
//	sort(lifts.begin(), lifts.end(), sorting);
//
//	int count = 1;
//	vector<lift>::iterator i = lifts.begin();
//
//	for (i; i != lifts.end()-1; i++)
//	{
//		vector<lift>::iterator b = i + 1;
//		vector<lift>::iterator it = find_s(b, lifts.end(), i->f);
//		if (it != i) {
//			count++;
//		}
//	}
//
//	return count;
//
//}
//void find_lift(vector<lift>::iterator& begin, vector<lift>::iterator& end, int maxCount)
//{
//	vector<vector<lift>::iterator> variants;
//	int count;
//	only(begin, end, begin->s, end->f, variants);
//	for (vector<vector<lift>::iterator>::iterator it = variants.begin(); it != variants.end(); it++)
//	{
//		count++;
//		while (begin != end) {
//			if (find_s(begin, end, begin->f) != begin)
//			{
//				maxCount = std::max(count, maxCount);
//				vector<lift>::iterator beg = begin + 1;
//				find_lift(beg, end, maxCount);
//			}
//		}
//		
//	}
//	
//}
////////////////////////////////////////////////////////////////////////

//bool only(vector<lift>::iterator begin, vector<lift>::iterator end)
//{
//	int count;
//	for (vector<lift>::iterator i = begin + 1; i != end; i++)
//	{
//		if ((i)->s == begin->f) {
//			count++;
//		}
//	}
//	if (count > 1)
//	{
//		return false;
//	}
//	return true;
//}

//int nextLift(vector<lift>::iterator i, vector<lift>::iterator end)
//{
//	if (i != end && i->f == (i+1)->s) {
//		return (i + 1)->s;
//	}
//}
//
//int findCurrentLift(vector<lift>::iterator begin, vector<lift>::iterator end, vector<int>& variants)
//{
//	int currentLift;
//	vector<int> counts;
//	for (vector<int>::iterator it = variants.begin(); it != variants.end(); it++) {
//
//		int count;
//
//		for (vector<lift>::iterator i = begin + 1; i != end; i++)
//		{
//			if (i->s == begin->f) {
//				currentLift = i->s;
//				variants.push_back(currentLift);
//				count++;
//			}
//		}
//		counts.push_back(count);
//	}
//	return *max_element(counts.begin(), counts.end());
//}
//
//
//
//int handler(vector<lift>& lifts) {
//	sort(lifts.begin(), lifts.end(), sorting);
//	vector<int> variants;
//
//	int output = findCurrentLift(lifts.begin(), lifts.end(), variants);
//
//	return 0;
//}

//void output(vector<lift>& lifts)
//{
//	vector<cell> table;
//	sort(lifts.begin(), lifts.end(), sorting);
//	int line;
//
//	for (vector<lift>::iterator i = lifts.begin(); i != lifts.end(); i++)
//	{
//		line++;
//		int x;
//		for (vector<lift>::iterator j = lifts.begin(); j != lifts.end(); j++)
//		{
//			if (i->f == j->s) {
//				table[line][x] = i->f;
//
//				table[line + 1][x] = j->s;
//				x++;
//			}
//		}
//	}
//}
//
//int f(vector<lift>::iterator& begin, vector<lift>::iterator& end, int& currentLift)
//{
//	vector<lift>::iterator beg = begin;
//	begin++;
//	while (begin != end)
//	{
//		if (begin->s == beg->f)
//			currentLift = begin->s;
//	}
//	return currentLift;
//}
//
//void d(vector<lift>::iterator& begin, vector<lift>::iterator& end)
//{
//	int currentLift = 0;
//	while (begin != end)
//	{
//
//	}
//}

bool isStart(vector<lift>::iterator& it, vector<lift>::iterator& end)
{
	vector<lift>::iterator begin = it + 1;
	for (end; end != begin; end--) {
		if (it->s == end->f) {
			return false;
		}
	}
	return true;
}

void addVariants(vector<lift>::iterator& it, vector<lift>::iterator& end, vector<vector<lift>::iterator>& variants)
{
	variants.push_back(it);
	vector<lift>::iterator begin = it + 1;
	for (begin; begin != end; begin++) {
		if (begin->s > it->s) {
			break;
		}
		if (it->s == begin->s && it->f != begin->f) {
			variants.push_back(begin);
		}
	}
}

int handler(vector<lift>& lifts)
{
	vector<lift>::iterator begin = lifts.begin();
	vector<lift>::iterator end = lifts.end();
	int maxCount = 0;
	for (begin; begin != end; begin++)
	{
		int count = 1;
		int currentLift = begin->f;

		vector<vector<lift>::iterator> variants;
		addVariants(begin, end, variants);

		int countForVar = 0;
		int maxcountVar = 0;
		for (vector<vector<lift>::iterator>::size_type n = 0; n != variants.size(); n++) {

			for (vector<lift>::iterator it = variants[n] + 1; it != end; it++)
			{
				if (currentLift == it->s) {
					currentLift = it->f;
					countForVar++;
				}
				maxcountVar = std::max(maxcountVar, countForVar);
			}
		}
		count += maxcountVar;
		variants.clear();

		maxCount = std::max(count, maxCount);

	}
	return maxCount;
}

int rec(vector<lift>::iterator& begin, vector<lift>::iterator& end)
{
	int count = 1;
	int currentLift = begin->f;

	for (vector<lift>::iterator it = begin + 1; it != end; it++) {
		vector<vector<lift>::iterator> variants;
		addVariants(begin, end, variants);
		if (variants.size() > 1) {
			count += rec(it, end);
		}
		else if (variants.size() == 0) {
			break;
		}
		else {
			currentLift = it->f;
			count++;
		}
	}
	return count;
}

int hand(vector<lift>& lifts)
{
	vector<lift>::iterator begin = lifts.begin();
	vector<lift>::iterator end = lifts.end();
	int maxCount = 0;

	for (begin; begin != end; begin++) {

		if (isStart(begin, end)) {
			int count = 1;
			int currentLift = begin->f;

			for (vector<lift>::iterator it = begin + 1; it != end; it++) {
				vector<vector<lift>::iterator> variants;
				addVariants(begin, end, variants);
				if (variants.size() > 1) {
					count += rec(it, end);
				}
				else if (variants.size() == 0) {
					break;
				}
				else {
					currentLift = it->f;
					count++;
				}
				variants.clear();
			}
			maxCount = std::max(count, maxCount);
		}
	}
	return maxCount;
}
//int handler1(vector<lift>::iterator& begin, vector<lift>::iterator& end, int count)
//{
//
//	for (begin; begin != end; begin++)
//	{
//		int currentLift = begin->f;
//
//		vector<vector<lift>::iterator> variants;
//		addVariants(begin, end, variants);
//
//		if (variants.size() == 1) {
//			currentLift == begin->f;
//			count++;
//		}
//		else if(variants.size()> 1 ) {
//			for (vector<vector<lift>::iterator>::size_type n = 0; n != variants.size(); n++) {
//				count++;
//				count = handler1(variants[n], end, count);
//				
//			}
//		}
//		variants.clear();
//
//	}
//	return count;
//}

//void counting(vector<lift>::iterator&, vector<lift>::iterator&, int&);
//
//void defoltFor(vector<lift>::iterator& begin, vector<lift>::iterator& end, int& count, vector<vector<lift>::iterator>& variants)
//{
//	variants.clear();
//	for (begin; begin != end; begin++) {
//		counting(begin, end, count);
//	}
//}
//
//void forVariants(vector<lift>::iterator& begin, vector<lift>::iterator& end, int& count, vector<vector<lift>::iterator>& variants)
//{
//	for (vector<vector<lift>::iterator>::size_type n = 0; n != variants.size(); n++)
//	{
//		defoltFor(begin, end, count, variants);
//	}
//}
//
//bool checkVariants(vector<lift>::iterator& begin, vector<lift>::iterator& end, int& count, vector<vector<lift>::iterator>& variants)
//{
//	if (variants.size() == 1) {
//		return 0;
//	}
//	else {
//		return 1;
//	}
//}
//
//void counting(vector<lift>::iterator& begin, vector<lift>::iterator& end, int& count )
//{
//	vector<vector<lift>::iterator> variants;
//	addVariants(begin, end, variants);
//	if (variants.size() != 0) {
//		count++;
//		bool check = checkVariants(begin, end, count, variants);
//		if (check == 1) {
//			forVariants(begin, end, count, variants);
//		}
//		else {
//			defoltFor(begin, end, count, variants);
//		}
//	}
//	else {
//		cout << count << endl;
//	}
//}

void Tink6()
{
	int n;
	vector<lift> lifts;
	lift ilift;
	cin >> n;

	for (int i = 0; i != n; i++) {
		cin >> ilift.s >> ilift.f;
		lifts.push_back(ilift);
	}

	std::sort(lifts.begin(), lifts.end(), sorting);

	/*vector<lift>::iterator begin = lifts.begin();
	vector<lift>::iterator end = lifts.end();
	int count = 0;*/

	//handler(begin, end, count);

	int output = hand(lifts);
	cout << output << endl;

}

//нужен двумерный расширяемый массив 
// 0 1 2 3 4
// 1 тут заполняем этажи на которые попали при N ходе
// 2 сколько заполнено по вертикали максимально - ответ
// 3

#endif