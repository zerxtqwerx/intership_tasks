#pragma once
#ifndef TINK3
#define TINK3
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Tink3()
{
    cout << "Enter n:" << endl;
    int n;
    cin >> n;

    cout << "Enter a:" << endl;
    int a;
    vector<int> dayData;

    for (int i = 0; i != n; i++) {
        cin >> a;
        dayData.push_back(a);
    }

    int a_max = 0;
    int i_max = 0;
    int a_min = -1;
    int i_min = 0;

    for (int i = 0; i != n; i++) {
        if ((i + 1) % 2 == 0) {
            if (dayData[i] > a_max) {
                a_max = dayData[i];
                i_max = i;
            }

        }
        else {
            if (a_min == -1 || dayData[i] < a_min) {
                a_min = dayData[i];
                i_min = i;
            }
        }
    }
    swap(dayData[i_min], dayData[i_max]);

    int profit = 0;
    for (int i = 0; i != n; i++) {
        profit += (pow(-1, i) * dayData[i]);
    }
    cout << profit << endl;

}
#endif

