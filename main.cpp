#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

int main() {
    string line;
    int pos;
    ifstream myfile;
    map<string, string> Translator; // creates map for translation
    myfile.open("Translation.txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) { // gets line and saves in line variable;
            pos = line.find(":"); // finds position of ":"
            Translator[line.substr(0,pos)] = line.substr(pos + 1, line.length());
            // saves key as first half of string before ":" and the value as the last half of string after ":"

        }

      string input;
        while (input != "quit") {
            cout << "Enter a line: "; // takes user input while input is not quit
            getline(cin, input); // saves user input into input variable
            for (int i = 0; i < input.length(); ++i) {
                input[i] = tolower(input[i]);  // lowers the input
            }


            for (auto element: Translator) { // loops through keys in Translator
                int start_pos = 0; // initialize start position for looping through string
                    while ((start_pos = input.find(element.first, start_pos)) != string::npos) { // finds occurrence of key in input string
                        if (start_pos != 0 && isalpha(input[start_pos - 1]) || // Check left side of string to see if it is an alphabetic character
                        (start_pos + element.first.length() < input.length() && isalpha(input[start_pos + element.first.length()]))) { // Check right side of string to see if it is an alphabetic character
                                start_pos += element.first.length(); // If left or right side is an alphabetic character, move to next position in string

                        }
                        else {
                            input.replace(start_pos, element.first.length(), element.second); // replaces words in string with what's in Translator map
                            start_pos += element.second.length(); // moves to next position in string
                        }



                }
            }
            int probability = rand() % 100;
            if (probability < 30) {  // adds "arr" to end of string 30% of time
                input += ", arr";
            }
            cout << input << endl; // outputs translated string

                }


        }










    myfile.close();
    return 0;

}