#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <tuple>

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));
    return r;
}

// bool LexiSort(std::vector<int> a, std::vector<int> b) 
// {
//     if (a == b) {
//         return false;
//     }
 
//     // Compare the octets and return the result
//     for (int i = 0; i < 4; i++) {
//         if (a[i] > b[i]) {
//             return false;
//         } else if (a[i] < b[i]) {
//             return true;
//         }
//     }
//     return false;
// }
/**
 * @brief Функция для лексикографической сортировки от меньшего к большему.
 * 
 */
auto LexiSort = [](auto a, auto b)
{
    if (a == b) return false;
    for (auto i = 0; i < 4; i++)
    {
        if (a[i] > b[i])
        {
            return false;
        }
        else if (a[i] < b[i])
        {
            return true;
        }
    }
    return false;
};

auto PrintAll = [](std::vector<std::vector<int>> ip_address)
{
    for (auto i = 0; i < ip_address.size(); i++)
    {
        for (auto j = 0; j < 4; j++)
        {
            std::cout << ip_address[i][j];
            if (j < 3) std::cout << ".";
        } 
        std::cout << std::endl;
    }
};

auto PrintByteOne = [](std::vector<std::vector<int>> ip_address)
{
    for (auto i = 0; i < ip_address.size(); i++)
    {
        for (auto j = 0; j < 4; j++)
        {
            if (ip_address[i][0] == 1)
            {
                std::cout << ip_address[i][j];
                if (j < 3) std::cout << ".";
                else if (j == 3) std::cout << std::endl;
                else break;
            }

        } 
    }
};

auto Print46and70 = [](std::vector<std::vector<int>> ip_address)
{
    for (auto i = 0; i < ip_address.size(); i++)
    {
        for (auto j = 0; j < 4; j++)
        {
            if (ip_address[i][0] == 46 && ip_address[i][1] == 70)
            {
                std::cout << ip_address[i][j];
                if (j < 3) std::cout << ".";
                else if (j == 3) std::cout << std::endl;
                else break;
            }
        } 
    }
};

auto Print46 = [](std::vector<std::vector<int>> ip_address)
{
    for (auto i = 0; i < ip_address.size(); i++)
    {
        for (auto j = 0; j < 4; j++)
        {
            if ( std::find(ip_address[i].begin(), ip_address[i].end(), 46) != ip_address[i].end() )
            {
                std::cout << ip_address[i][j];
                if (j < 3) std::cout << ".";
                else if (j == 3) std::cout << std::endl;
                else break;
            }
        } 
    }
};
int main()
{
    std::vector<std::vector<int>> ip_address;
    std::string s;
    std::ifstream file("ip_filter.tsv");
    while(std::getline(file, s))
    {
        auto splited = split(s.substr(0, s.find('\t')), '.');
        std::vector<int> octets = {stoi(splited[0]), stoi(splited[1]), stoi(splited[2]), stoi(splited[3])};
        ip_address.push_back(octets);
    }

    sort(ip_address.begin(), ip_address.end(), LexiSort);
    PrintAll(ip_address);
    PrintByteOne(ip_address);
    Print46and70(ip_address);
    Print46(ip_address);
}