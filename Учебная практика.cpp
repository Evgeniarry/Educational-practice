#include<string>
#include<list>
#include<vector>
#include<iostream>
#include<sstream>

using namespace std;

vector<string> division_into_words(string text)
{
    stringstream s(text);
    vector <string> svec;
    for (string word; s >> word; svec.push_back(word));
    return svec;
}

vector<string> clear_of_excess(vector<string>words)
{
    vector<string> updated_words;
    vector<char> symbols_of_updated_word;

    for (string word : words) {
        for (char symbol : word) {
            if ((symbol >= 'a' && symbol <= 'z')|| (symbol >= 'A' && symbol <= 'Z'))
                symbols_of_updated_word.push_back(symbol);
        }
        string updated_word(symbols_of_updated_word.begin(), symbols_of_updated_word.end());
        updated_words.push_back(updated_word);
        symbols_of_updated_word.clear();
    }
    copy(updated_words.begin(), updated_words.end(), ostream_iterator<string>(cout, " "));
    return updated_words;
}



int main()
{
    string text = "Both operands must be integral values. These operators perform the usual arithmetic conversions; the type of the result is the type of the left operand after conversion.";    
    clear_of_excess(division_into_words(text));
    return 0;
}
