// Author: pcmaniac23
// Date: 05/03/2016
// Problem source: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=4461

#include <string>
#include <iostream>
#include <vector>

#define CARBON_WEIGHT    12.01
#define HYDROGEN_WEIGHT  1.008
#define OXYGEN_WEIGHT    16.00
#define NITROGEN_WEIGHT  14.01

using namespace std;

void main() {
    int num_test_cases = 0;
    cin >> num_test_cases;

    vector<double> results;

    while(num_test_cases--) {
        string test_case;
        cin >> test_case;

        double total = 0;
        unsigned int count = 0;
        char atom;

        for(unsigned int i = 0; i < test_case.length();) {
            const char *p_atom = &(test_case[i]);
            const char *p_count = NULL;

            if(isalpha(test_case[i])) {
                atom = test_case[i];
                p_count = p_atom + 1;
                
                if(isalpha(*p_count) || ((p_count - p_atom) >= test_case.length())) {
                    count = 1;
                    i++;
                    p_count = NULL;
                }
                else {
                    while(isdigit(*p_count)) {
                        p_count++;
                    }

                    i = p_count - test_case.c_str();
                    
                    p_count--;
                    unsigned int base = 1;
                    while(p_count > p_atom) {
                        count = count + (((*p_count)-'0') * base);
                        base *= 10;
                        p_count--;
                    }
                }

                if(atom == 'C') {
                    total = total + (CARBON_WEIGHT * count);
                }
                else if(atom == 'H') {
                    total = total + (HYDROGEN_WEIGHT * count);
                }
                else if(atom == 'O') {
                    total = total + (OXYGEN_WEIGHT * count);
                }
                else if(atom == 'N') {
                    total = total + (NITROGEN_WEIGHT * count);
                }

                results.push_back(total);
            }
        }
    }

    for (vector<double>::iterator it = results.begin(); it != results.end(); it++)
    {
        cout << *it << endl;
    }
}