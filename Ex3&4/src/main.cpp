#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<std::vector<int>> get_data(std::string path);
bool is_report_safe(std::vector<int> report);
bool problem_dampener(std::vector<int> report);

int main(int argc, char** argv)
{
    std::vector<std::vector<int>> reports = get_data("data/data.txt");

    int counter = 0; 

    for(auto report : reports)
    {
        if(problem_dampener(report))
        {
            counter++;
        }
    }

    std::cout << counter;

    return 0;
}

std::vector<std::vector<int>> get_data(std::string path)
{
    std::ifstream file(path);
    std::string line;
    std::vector<std::vector<int>> reports;

    while (std::getline(file, line))
    {
        std::vector<int> levels;
        std::istringstream stream(line);
        int number;

        while (stream >> number) {
            levels.push_back(number);
        }

        reports.push_back(levels);
    }
    
    return reports;
}

bool is_report_safe(std::vector<int> report)
{
    if(report.size() <= 1)
    {
        return true;
    }

    if(report.at(0) == report.at(1) 
        || abs(report.at(0) - report.at(1)) > 3)
    {
        return false;
    }

    bool is_ascending = report.at(0) < report.at(1);

    for(int i = 1; i < report.size() - 1; i++)
    {
        bool is_next_ascending = report.at(i) < report.at(i+1);

        if(is_next_ascending != is_ascending 
            || report.at(i) == report.at(i+1)
            || abs(report.at(i) - report.at(i+1)) > 3)
        {
            return false;
        }
    }

    return true;
}

std::vector<int> removeElementAt(std::vector<int> original, size_t index) {
    if (index >= original.size()) {
        throw std::out_of_range("Index is out of range.");
    }

    std::vector<int> result;
    result.reserve(original.size() - 1);

    result.insert(result.end(), original.begin(), original.begin() + index);
    result.insert(result.end(), original.begin() + index + 1, original.end());

    return result;
}

bool problem_dampener(std::vector<int> report)
{
    for(int i = 0; i < report.size(); i++)
    {
        auto mitigated_report = removeElementAt(report, i);
        if(is_report_safe(mitigated_report))
        {
            return true;
        }
    }

    return false;
}
