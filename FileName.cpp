#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cerr << "Error open file!" << endl;
        return 1;
    }

    map<string, int> wordFrequency;
    string word;

    while (inputFile >> word)
    {
        for (char& c : word)
        {
            if (c >= 'A' && c <= 'Z')
            {
                c += 32;
            }
        }
        wordFrequency[word]++;
    }

    inputFile.close();

    cout << "Word Frequency:" << endl;
    for (const auto& entry : wordFrequency)
    {
        cout << entry.first << ": " << entry.second << endl;
    }

    string mostFrequentWord;
    int maxFrequency = 0;
    for (const auto& entry : wordFrequency)
    {
        if (entry.second > maxFrequency)
        {
            mostFrequentWord = entry.first;
            maxFrequency = entry.second;
        }
    }

    cout << "\nMost frequent word: '" << mostFrequentWord << "' with frequency: " << maxFrequency << endl;

    ofstream outputFile("output.txt");
    if (!outputFile)
    {
        cerr << "Open file for writing!" << endl;
        return 1;
    }

    outputFile << "Word Frequency:" << endl;
    for (const auto& entry : wordFrequency) {
        outputFile << entry.first << ": " << entry.second << endl;
    }
    outputFile << "\nMost frequent word: '" << mostFrequentWord << "' with frequency: " << maxFrequency << endl;

    outputFile.close();
}