#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;

void newline(istream& mystream, string& line)
{
    char symbol;
    mystream.get(symbol);
    line = "";
    while (symbol != '\n')
    {
        line += symbol;
        mystream.get(symbol);
        if (symbol == '#')
        {
            mystream.ignore();
            mystream.ignore();
            mystream.get(symbol);
        }
        if (!mystream) break;
    }
}

const int NUMBER_OF_CHAPTERS = 18;

int main()
{
    fstream answers("answers.dat", ios::in);

    if (!answers)
    {
        cout << "I couldn't find the file in the current directory";
        exit(1);
    }

    string answer, question;

    int answercounter = 0;
    int chapternumber = 18;

    while (true)
    {
        cout << "\n\nAsk a question to get answered\n";
        cout << "Enter your question: ";
        cin >> question;
        newline(answers, answer);
        ++answercounter;
        if (answercounter != 1)
        {
            cout << answer;
        }
        else
        {
            cout << answer << chapternumber << ".";
            --chapternumber;
            if (chapternumber == 0)
            {
                chapternumber = NUMBER_OF_CHAPTERS;
            }
        }
        if (answercounter == 8)
        {
            answers.close();
            answers.open("answers.dat", ios::in);
            answercounter = 0;
        }
    }

    return 0;
}