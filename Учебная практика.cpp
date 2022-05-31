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
            if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z'))
                symbols_of_updated_word.push_back(symbol);
        }
        string updated_word(symbols_of_updated_word.begin(), symbols_of_updated_word.end());
        updated_words.push_back(updated_word);
        symbols_of_updated_word.clear();
    }
    return updated_words;
}

vector<string> shellsort(vector<string>x, int n)              //SHELL SORT - SHELL'S INCREMENTS
{
    int i, j, k, increment;
    int swp = 0, comp = 0;
    string temp;
    increment = n / 2;

    while (increment > 0)
    {
        for (i = 0; i < increment; i++)
        {
            for (j = 0; j < n; j += increment)
            {
                temp = x[j];
                for (k = j - increment;k >= 0 && temp.length() > x[k].length();k -= increment)
                {
                    comp++;
                    swp++;
                    x[k + increment] = x[k];
                }
                x[k + increment] = temp;
                swp++;
            }
        }
        comp++;
        if (increment / 2 != 0)
            increment = increment / 2;
        else if (increment == 1)
            increment = 0;
        else
            increment = 1;
    }
    return x;
}

int main()
{
    string text = "Both operands must be integral values. These operators perform the usual arithmetic conversions; the type of the result is the type of the left operand after conversion.";
    vector<string> clear;
    clear = clear_of_excess(division_into_words(text));
    int n = clear.size();      
    vector<string> sort;
    sort = shellsort(clear, n);
    for (int i = 0; i < n; i++)
        cout << sort[i] << ' ';
    return 0;
}
