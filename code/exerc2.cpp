/*****************************************
 * Lab 3: exercise 2                      *
 * Anagrams table                         *
 ******************************************/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <set>



    // ADD CODE

    using table_entry = std::pair < std::string, std::set<std::string>>; // ger pair<blablabla> namnet table_entry;

    int main() {

        std::map<std::string, std::set<std::string>> subjects; //skapar en tabell som vi namnger som subjects, med en string + lista med strings

        std::ifstream input("../code/uppgift2_kort.txt"); //testar ifall vi kan nå textfilen

        if (!input) {

            std::cout << "Could not open input file!!\n";
            return 0;

        }

        std::vector<std::string> words; //vilken textfil vi läser från, whitespace separerar orden, stoppa in i words
        std::copy(std::istream_iterator<std::string>(input), 
                std::istream_iterator<std::string>(), std::back_inserter(words));

        std::for_each(words.begin(), words.end(), [&subjects](std::string aWord) {  //sorterar bokstäverna i stringsen från words och stoppar in i subjects
            std::string temp = aWord;

            std::sort(aWord.begin(), aWord.end());
            subjects[aWord].insert(temp); //lägger in det sorterade ordet i subjects

            });

        std::ofstream output("../code/output.txt"); // får åtkosmt till output-filen

        output << "Total number of words: " << words.size() << std::endl; //skriver ut total number of words, med antalet element i outp.filen

        output << std::endl << "-- ANAGRAMS --" << std::endl; //skriver ut vilka anagram som finns
        std::for_each(subjects.begin(), subjects.end(), [&output](table_entry p) { //skriver ut alla ord som har gemensamt subject samt antalet ord
            if (p.second.size() >= 2) {
                std::copy(p.second.begin(), p.second.end(), std::ostream_iterator<std::string>(output, " "));

                output << " --> " << p.second.size() << " words." << std::endl;
            }
            });
        return 0;
    }

    