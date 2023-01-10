#include <iostream>
#include <string>
using namespace std;



void computeLPS(string pat, int* lps)
{
    int j = 0;

    lps[0] = 0; // lps[0] is always 0 

    int i = 1;
    while (i < pat.size()) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0) {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool IsKPeriodic(const string& pat, const string& txt, const int k)
{
    int* lps = new int[k];
    int count = 0;
    computeLPS(pat, lps);

    int i = 0;
    int j = 0;
    while (i < txt.size()) {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == pat.size()) {
            count++;
            j = lps[j - 1];
        }
        else if (i < txt.size() && pat[j] != txt[i]) {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
    if ((count * k) == txt.size())
    {
        cout << "Kratna K" << endl;
        return true;
    }
    else
    {
        cout << "Ne Kratna K" << endl;
        return false;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int k = 1;
    string txt;
    cout << "¬ведите строку" << endl;
    cin >> txt;
    cout << "¬ведите k > 0" << endl;
    cin >> k;
    string pat = txt.substr(0, k);
    IsKPeriodic(pat,txt,k);
    return 0;
}


