#include <iostream>
#include <cstring>
using namespace std;

char *mystrtok(char str[], char delimiter)
{
    static char *input = NULL;
    if (str != NULL)
        input = str;

    if (input == NULL)
        return NULL;
    char *output = new char[strlen(input) + 1]; // +1 for the '\0' or null char at the endl
    // Return a word as dynamically allocated word array from my function.
    // Read the word from input and i will store in output and just return till delimiter
    int i;
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != delimiter)
            output[i] = input[i];
        else
        {
            output[i] = '\0';
            input += i++;
            return output;
        }
    }
    // return the last word if delimiter is not there
    output[i] = '\0';
    input = NULL;
    return output;
}

int main()
{
    char str[] = "Hi, I am String";
    char *ptr;
    ptr = mystrtok(str, ',');
    while (ptr != NULL)
    {
        cout << ptr << endl;
        ptr = mystrtok(NULL, ' ');
    }
    return 0;
}