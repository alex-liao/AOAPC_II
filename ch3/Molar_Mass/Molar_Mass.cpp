#include <string>
#include <iostream>
#include <vector>

using namespace std;

double get_atomic_weight(char atom) {
    switch (atom)
    {
    case 'C': 
    	return 12.01;
    case 'H': 
        return 1.008;
    case 'O': 
        return 16.00;
    case 'N': 
        return 14.01;
    default :
        return 0.0;
    }
}

int main() {
    vector<double> results;
    
    unsigned int num_test_cases = 0;
    cin >> num_test_cases;

    // loop through test cases
    while(num_test_cases--) {
        string test_case = "";
        cin >> test_case;

        double total = 0;
        const char *p_atom = test_case.c_str();
        const char *p_count = NULL;

        // loop through the input string for a single test case
        while((unsigned)(p_atom - test_case.c_str()) < test_case.length()) {
            if(isalpha(*p_atom)) {
                char atom = test_case[p_atom - test_case.c_str()];
                unsigned int count = 0;
                p_count = p_atom+1;

                if(isdigit(*p_count)) {
                    while(isdigit(*p_count)) {
                        p_count++;
                    }
                    const char *p_next_atom = p_count;
                    p_count--;

                    unsigned int base = 1;
                    while(p_count > p_atom) {
                        count += ((*p_count - '0') * base);
                        base *= 10;
                        p_count--;
                    }

                    p_atom = p_next_atom;
                    p_next_atom = NULL;
                    p_count = NULL;
                }
                else {
                    count = 1;
                    p_atom++;
                    p_count = NULL;
                }

                total += count * get_atomic_weight(atom);
            }
        }

        results.push_back(total);
    }

    for(vector<double>::iterator it = results.begin(); it != results.end(); it++) {
        cout.precision(3);
        cout << fixed << *it << endl;
    }
}