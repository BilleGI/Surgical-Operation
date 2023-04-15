#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include "my-coordinates.h"
#include "my-command.h"

struct oder
{
    std::string instruct;
    coordinates points;
};

void check(std::string& word)
{
    while(true)
    {
        auto it = std::find_if(word.begin(), word.end(), [] (char const &c)
        {
            return !std::isalpha(c);
        });
        if(word.end() == it)
            break;

        std::cout << "Enter the correct command: ";
        getline(std::cin, word);
    }
}

void registr(std::string& word)
{
    for (int i = 0; i < word.size(); ++i)
    {
        if(word[i] < 'a' || word[i] > 'z')
            word[i] = tolower(word[i]);
    }
}

void last(std::vector<oder>& command, int& num)
{
    for(int i = command.size() - 1; i >= 0 ; --i)
    {
        if(command[i].points.second[0] >= 0 && command[i].points.second[1] >= 0)
        {
            num =i;
            break;
        }
    }
}

int main()
{
    std::vector<oder> command;
    std::cout << "The program simulates the operation." << std::endl;
    std::cout << "List of commands: " << std::endl;
    std::cout << "scalpel - to make a cut," << std::endl;
    std::cout << "hemostat - to perfom the clamp," << std::endl;
    std::cout << "twerzers - so it the clamp," << std::endl;
    std::cout << "suture - for suturing" << std::endl;
    do {
        oder event;
        std::cout << "Enter the command: ";
        getline(std::cin, event.instruct);
        check(event.instruct);
        registr(event.instruct);
        if(command.empty() && event.instruct == "scalpel")
        {
            line(event.points);
            scalpel(event.points);
            command.push_back(event);
        }
        else if ((!command.empty()) && event.instruct == "hemostat")
        {
            point(event.points, command[0].points);
            location(event.points, command[0].points, event.instruct);
            command.push_back(event);
        }

        else if((!command.empty()) && event.instruct == "twerzers")
        {
            point(event.points, command[0].points);
            location(event.points, command[0].points, event.instruct);
            command.push_back(event);
        }

        else if((!command.empty()) && event.instruct == "suture")
        {
            int num;
            last(command, num);
            if(num == 0)
                new_line(event.points, command[num].points);
            else
                second_line(event.points, command[num].points, command[0].points);
            suture(event.points, command[0].points);
            command.push_back(event);
        }

        if (command.size() > 1 && ((command[0].points.first[0] == command[command.size()-1].points.first[0] &&
                                    command[0].points.first[1] == command[command.size()-1].points.first[1] &&
                                    command[0].points.second[0] == command[command.size()-1].points.second[0] &&
                                    command[0].points.second[1] == command[command.size()-1].points.second[1])||
                                   (command[0].points.first[0] == command[command.size()-1].points.first[1] &&
                                    command[0].points.first[1] == command[command.size()-1].points.first[0] &&
                                    command[0].points.second[0] == command[command.size()-1].points.second[1] &&
                                    command[0].points.second[1] == command[command.size()-1].points.second[0])))
            break;
    }while(true);

    return 0;
}
