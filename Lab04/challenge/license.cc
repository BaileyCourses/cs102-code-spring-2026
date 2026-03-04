#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: ./license <filename>" << endl;
        return 1;
    }

    char buffer[7];
    char *plates[8];

    FILE *fp = fopen(argv[1], "r");
    if (fp == nullptr)
    {
        cout << "Unable to open file." << endl;
        return 1;
    }

    int idx = 0;

    while (fread(buffer, 1, 7, fp) == 7)
    {
        buffer[6] = '\0';
        plates[idx] = buffer;
        idx++;
    }

    for (int i = 0; i < 8; i++)
    {
        cout << plates[i] << endl;
    }

    return 0;
}
