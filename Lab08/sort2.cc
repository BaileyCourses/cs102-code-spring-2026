// sort2.cc
// Do not modify this file.

#include <fstream>
#include <iostream>
#include <vector>

void merge(std::vector<int> &arr, int left, int mid, int right);
void sort(std::vector<int> &arr, int left, int right);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./sort2 <file.txt>" << std::endl;
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

    sort(numbers, 0, (int)numbers.size() - 1);

    for (int x : numbers)
        std::cout << x << "\n";

    return 0;
}

void merge(std::vector<int> &arr, int left, int mid, int right)
{
    std::vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < (int)L.size() && j < (int)R.size())
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < (int)L.size())
        arr[k++] = L[i++];
    while (j < (int)R.size())
        arr[k++] = R[j++];
}

void sort(std::vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    sort(arr, left, mid);
    sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
