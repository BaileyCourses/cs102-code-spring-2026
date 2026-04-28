// sort3.cc
// Do not modify this file.

#include <fstream>
#include <iostream>
#include <vector>

void sort(std::vector<int> &arr);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./sort3 <file.txt>" << std::endl;
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
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            std::swap(arr[i], arr[min_idx]);
    }
}
