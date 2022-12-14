/*******************************
 * Lab 3: exercise 1            *
 * Frequency table of words     *
 *******************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>   //std::pair
#include <fstream>
#include <cassert>
#include <algorithm>

/*******************************
 * 1. Declarations              *
 ********************************/

// A function to test the tables created by the program
void test(const std::map<std::string, int>& t, const std::vector<std::pair<std::string, int>>& v,
          const std::string& file_name, int n);

using pair = std::pair<std::string, int>;

bool isPunc(const char& c) {

    std::string chars = ".,!?:();\"";

    return chars.find(c) != std::string::npos;
}

void removeChar(std::string& word) {

    word.erase(remove_if(word.begin(), word.end(), isPunc), word.end());

}

void lowerCase(std::string& word) {

    std::transform(word.begin(), word.end(), word.begin(), tolower);

}


bool sortBy(const pair& t1, const pair& t2) {

    if (t1.second == t2.second)
    {
        return(t1.first < t2.first);
    }
    return(t1.second > t2.second);
}

/*******************************
 * 2. Main function             *
 *******************************/

int main() {
    std::string name;
    std::cout << "Text file: ";
    std::cin >> name;

    std::ifstream in_File{"../code/" + name};

    if (!in_File) {
        std::cout << "Could not open input file!!\n";
        return 0;
    }

    std::map<std::string, int> table;
    int counter{0};  // to count total number of words read from the input file

    //ADD CODE to build table

    std::string inWord;

    while (in_File >> inWord)
    {
        removeChar(inWord);

        lowerCase(inWord);

        table[inWord]++;

        ++counter;
    }

    
    //ADD CODE to build vector freq

    std::vector<pair> freq;

    // std::vector<std::pair<std::string, int>> freq;

    std::copy(table.begin(), table.end(), std::back_inserter(freq));

    std::sort(freq.begin(), freq.end(), sortBy);

    /* ************** Testing **************** */

    test(table, freq, name, counter);
}


/*******************************
 * 2. Test implementation      *
 * Do not modify               *
 *******************************/

void test(const std::map<std::string, int>& t, const std::vector<std::pair<std::string, int>>& v,
          const std::string& file_name, int n) {

    std::ifstream file{"../code/out_" + file_name};

    // Test if stream is in good state
    assert(bool(file) == true);

    std::map<std::string, int> result1;
    std::string word;
    int counter{0};
    int total{0};

    // load expected frequency table sorted alphabetically
    while (file >> word >> counter && counter > 0) {
        result1[word] = counter;
        total += counter;
    }
	
	/*
    * uppgift1_kort: 69 words
    * uppgift1.txt: 1063 words
    */

    assert(total == n);  // test if total number of words is correct
    assert(t == result1);

    std::vector<std::pair<std::string, int>> result2;

    // load expected frequency table sorted by frequence
    while (file >> word >> counter) {
        result2.push_back(std::pair{word, counter});
    }

    assert(v == result2);

    std::cout << "\nPassed all tests successfully!!\n";
}
