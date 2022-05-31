#include<string>
#include<list>
#include<vector>
#include<iostream>
#include<sstream>
#include<fstream>
#include<chrono>

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

vector<string> shellsort(vector<string>x, int n)              
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
    setlocale(LC_ALL, "Russian");
    string name;
    cout << "Введите название файла (исходный файл):";
    cin >> name;
    ifstream file(name+= ".txt", ios_base::in);
    if (!file.is_open()) 
    {
       cout << "Файл не может быть открыт\n"; 
       return 1; 
    }
    string tmp, text;
    while (getline(file, tmp))
        text += tmp;
    file.close();

    cout << "Введите название файла (для записи информации с анализом текста):";
    cin >> name;
    ofstream fanalys(name += ".txt", ios_base::out | ios_base::trunc);
    if (!fanalys.is_open())
    {
        cout << "Файл не может быть открыт или создан\n";
        return 100;
    }

    fanalys << "Исходный текст: \n" << text << endl << endl << "Вариант 4: Латиница, по количеству символов в слове, по убыванию, игнорировать числа, сортировка Шелла.\n";
    cout << "Исходный текст: \n" << text << endl << endl << "Вариант 4: Латиница, по количеству символов в слове, по убыванию, игнорировать числа, сортировка Шелла.\n";

    auto start = chrono::high_resolution_clock::now();
    vector<string> clear_text;
    clear_text = clear_of_excess(division_into_words(text));
    int n = clear_text.size();
    vector<string> sort;
    sort = shellsort(clear_text, n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duraction = end - start;

    fanalys << "Количество слов: " << n << endl << "Время сортировки: " << duraction.count() << endl << "Статистика (количество слов каждой длины): \n";
    cout << "Количество слов: " << n << endl << "Время сортировки: " << duraction.count() << endl << "Статистика (количество слов каждой длины): \n";

    int statistic [100] = {};
    int k = 0;
    for (int i = 0; i < n; i++) 
    {
        k = clear_text[i].length();
        statistic[k]++;
    }

    for (int i=0; i < 20; i++)
    {
        if (statistic[i] != 0) {
            fanalys << "[" << i << "] - " << statistic[i] << endl;
            cout << "[" << i << "] - " << statistic[i] << endl;
        }
    }

    cout << "Введите название файла (для записи результата сортировки):";
    cin >> name;
    ofstream fout(name+=".txt", ios_base::out | ios_base::trunc);
    if (!fout.is_open())
    {
        cout << "Файл не может быть открыт или создан\n"; 
        return 10; 
    }
    for (int i = 0; i < n; i++)
        fout << sort[i] << endl;
    fout.close();
    fanalys.close();

    return 0;
}
