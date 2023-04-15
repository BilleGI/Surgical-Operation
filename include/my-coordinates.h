#pragma once

struct coordinates
{
    double first[2] = {-1};
    double second[2] = {-1};
};

void check_point(double point[]);

void line(coordinates& points);

void point(coordinates& operation, coordinates& cut);

void new_line(coordinates& sew, coordinates& cut);

void second_line(coordinates& sew, coordinates& last_sew, coordinates& cut);
