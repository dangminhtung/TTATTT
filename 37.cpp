#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

int *build_lookup(char *partern, int p_len)
{
    int *table = new int[p_len]();
    int index = 0;
    int j = 1;
    while (j < p_len)
    {
        if (partern[index] == partern[j])
        {
            index++;
            table[j] = index;
            j++;
        }
        else if (index > 0)
        {
            index = table[index - 1];
        }
        else
        {
            j++;
        }
    }
    return table;
}
void search(char *string, char *partern, int *table, int s_len, int p_len)
{
    int i = 0, j = 0;
    while (i < s_len && j < p_len)
    {
        if (string[i] == partern[j])
        {
            i++;
            j++;
        }
        else if (j > 0)
        {
            j = table[j - 1];
        }
        else
        {
            i++;
        }
    }
    if (j == p_len)
    {
        cout << "chuoi bat dau tu " << i - j;
    }
    else
    {
        cout << "chuoi ko khop";
    }
}
int main()
{
    char *p = new char[255];
    char *s = new char[255];
    cout << "nhap chuoi S: ";
    cin >> s;
    cout << "nhap chuoi P: ";
    cin >> p;
    int p_len = strlen(p);
    int s_len = strlen(s);
    int *table = build_lookup(p, p_len);
    cout << "table" << endl;
    for (int i = 0; i < p_len; i++)
    {
        cout << " " << table[i];
    }
    cout << endl;
    search(s, p, table, s_len, p_len);
}
// abcabababababaabac
// ababaaba
