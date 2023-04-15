#include <iostream>
#include "my-coordinates.h"

void check_point(double point[])
{
    while (!(point[0]>=0) || !(point[1]>=0)) {
        if(!(point[0]>=0))
        {
            std::cout << "Enter the correct x coordinates: ";
            std::cin >> point[0];
        }
        if(!(point[1]>=0))
        {
            std::cout << "Enter the correct y coordinates: ";
            std::cin >> point[1];
        }
    }
}

void line(coordinates& points)
{
    do {
        std::cout << "Enter the first coordinates: ";
        std::cin >> points.first[0] >> points.first[1];
        check_point(points.first);

        std::cout << "Enter the second coordinates: ";
        std::cin >> points.second[0] >> points.second[1];
        check_point(points.second);

    } while (points.first[0] == points.second[0] && points.first[1] == points.second[1]);
    std::cin.get();
}

void point(coordinates& operation, coordinates& cut)
{
    std::cout << "Enter the cordinates: ";
    std::cin >> operation.first[0] >> operation.first[1];
    check_point(operation.first);
    std::cin.get();
}

void new_line(coordinates& sew, coordinates& cut)
{
    line(sew);

    if(cut.first[0] < cut.second[0] && cut.first[1] < cut.second[1])
        while((cut.first[0] != sew.first[0] || cut.first[1] != sew.first[1] ||
            cut.second[0] < sew.second[0] || cut.second[1] < sew.second[1]) &&
            (cut.second[0] != sew.first[0] || cut.second[1] != sew.first[1] ||
                cut.first[0] > sew.second[0] || cut.first[1] > sew.second[1]))
        {
            line(sew);
        }
    else
        while((cut.first[0] != sew.first[0] || cut.first[1] != sew.first[1] ||
                cut.first[0] < sew.second[0] || cut.first[1] < sew.second[1]) &&
               (cut.second[0] != sew.first[0] || cut.second[1] != sew.first[1] ||
                cut.second[0] > sew.second[0] || cut.second[1] > sew.second[1]))
        {
            line(sew);
        }

}

void second_line(coordinates& sew, coordinates& last_sew, coordinates& cut)
{
    line(sew);

    if(cut.first[0] == last_sew.first[0] && cut.first[1] == last_sew.first[1])
        while((last_sew.second[0] != sew.first[0] || last_sew.second[1] != sew.first[1]) ||
               (sew.second[0] < sew.first[0] || sew.second[1] < sew.first[1] ||
                sew.second[0] > cut.second[0] || sew.second[1] > cut.second[1]))
            line(sew);
    else if (cut.second[0] == last_sew.first[0] && cut.second[1] == last_sew.first[1])
        while((last_sew.second[0] != sew.first[0] || last_sew.second[1] != sew.first[1]) ||
               (sew.second[0] > sew.first[0] || sew.second[1] > sew.first[1] ||
                sew.second[0] < cut.first[0] || sew.second[1] < cut.first[1]))
        {
            line(sew);
        }


    sew.first[0] = last_sew.first[0];
    sew.first[1] = last_sew.first[1];
}
