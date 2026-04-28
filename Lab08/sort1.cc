// sort1.cc
// Do not modify this file.

#include <fstream>
#include <iostream>
#include <vector>

void sort(std::vector<int> &arr);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./sort1 <file.txt>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "Could not open file: " << argv[1] << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    int n;
    while (file >> n)
        numbers.push_back(n);
    file.close();

    sort(numbers);

    for (int x : numbers)
        std::cout << x << "\n";

    return 0;
}

void sort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}
