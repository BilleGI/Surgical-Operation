#include <iostream>
#include "my-command.h"

bool check_coordinates(const coordinates& line, const double pos[])
{
    return ((pos[0] - line.first[0]) / (line.second[0] - line.first[0])) ==
           ((pos[1] - line.first[1]) / (line.second[1] - line.first[1]));
}

void scalpel(coordinates& action)
{
    std::cout << "section by coordinates: " << std::endl;
    std::cout << "x1 = " << action.first[0] << " y1 = " << action.first[1] << std::endl;
    std::cout << "x2 = " << action.second[0] << " y2 = " << action.second[1] << std::endl;
}

void location(coordinates& action, coordinates& check_action, std::string& command)
{
    std::cout << command << " - ";
    if(check_coordinates(check_action, action.first))
    {
        std::cout << "by coordinates:" << std::endl;
        std::cout << "x = " << action.first[0] << " y = " << action.first[1] << std::endl;
    }
    else
       std::cout << " cannot be performed."<< std::endl;
}

void suture(coordinates& action, coordinates& check_action)
{
    std::cout << "seam - ";
    if(check_coordinates(check_action, action.first) && check_coordinates(check_action, action.second))
    {
        std::cout << "by coordinates:" << std::endl;
        std::cout << "x1 = " << action.first[0] << " y1 = " << action.first[1] << std::endl;
        std::cout << "x2 = " << action.second[0] << " y2 = " << action.second[1] << std::endl;
    }
    else
        std::cout << "cannot be performed." <<std::endl;
}
