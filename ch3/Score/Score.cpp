// Author: pcmaniac23
// Date: 05/03/2016
// Problem source: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=4460

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int size = 0;
    cin >> size;

    vector<int> results;

    // looping through test cases
    for(unsigned int i=0; i < size; i++) {
        string test_case;
        cin >> test_case;

        int test_case_score = 0;
        int accumulator = 0;
        // looping through single test case's chars
        for(unsigned int j=0; j < test_case.length(); j++) {
            int score = 0;

            if(test_case[j] == 'O') {
                score = accumulator+1;
                accumulator++;
            }
            else if(test_case[j] == 'X') {
                accumulator = 0;
            }

            test_case_score += score;
        }

        results.push_back(test_case_score);
    }

    for(vector<int>::iterator it = results.begin(); it != results.end(); it++) {
        cout << *it << endl;
    }
}