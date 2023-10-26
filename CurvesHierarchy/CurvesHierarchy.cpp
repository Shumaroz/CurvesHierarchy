#include <iostream>
#include <vector>
#include <algorithm>
#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

double round_to(double value, double precision = 1.0)
{
    return std::round(value / precision) * precision;
}

int main()
{
    srand(time(NULL));

    // Populating a container with objects of random types with random parameters.

    vector<Curve*> curves_vec;
    int curves_rand, x_rand, y_rand, x_r_rand, y_r_rand, step_rand;
    int curves_count_rand = rand() % 10 + 10;

    for (int i = 0; i < curves_count_rand; i++)
    {
        curves_rand = rand() % 3;
        x_rand = rand() % 20;
        y_rand = rand() % 20;
        x_r_rand = rand() % 20 + 1;
        y_r_rand = rand() % 20 + 1;
        step_rand = rand() % 20 + 1;

        switch (curves_rand)
        {
        case 0:
            curves_vec.push_back(new Circle(x_rand, y_rand, x_r_rand));
            break;
        case 1:
            curves_vec.push_back(new Ellipse(x_rand, y_rand, x_r_rand, y_r_rand));
            break;
        case 2:
            curves_vec.push_back(new Helix(x_rand, y_rand, x_r_rand, step_rand));
            break;
        }
    }
    
    // Printing results in the separate container and displaying them on the screen.

    vector<pair<array<double, 3>, array<double, 3>>> results_vec;

    array<double, 3> point;
    array<double, 3> der;
    for (int i = 0; i < curves_count_rand; i++)
    {
        point = curves_vec[i]->point(M_PI / 4);
        der = curves_vec[i]->derivative(M_PI / 4);

        for (int i = 0; i < 3; i++)
        {
            point[i] = round_to(point[i], 0.01);
            der[i] = round_to(der[i], 0.01);
        }

        results_vec.push_back(make_pair(point, der));
    }

    cout << "\n\n=== Coordinates of points and derivatives at t = PI/4 ===\n\n";
    for (int i = 0; i < curves_count_rand; i++)
    {
        cout << "Curve " << i << " - " << typeid(*curves_vec[i]).name() << ":\n";
        cout << results_vec[i].first[0] << ", " << results_vec[i].first[1] << ", " << results_vec[i].first[2] << "\n";
        cout << results_vec[i].second[0] << ", " << results_vec[i].second[1] << ", " << results_vec[i].second[2] << "\n\n";
    }

    // Populating a second container with circles from the first container.

    vector<Curve*> circles_vec;

    for (int i = 0; i < curves_count_rand; i++)
    {
        if (typeid(*curves_vec[i]) == typeid(Circle))
            circles_vec.push_back(curves_vec[i]);
    }  

    // Sorting the second container in the ascending order of circles’ radii and displaying it on the screen.

    sort(circles_vec.begin(), circles_vec.end(), [](Curve* a, Curve* b) { return a->getRadius() < b->getRadius(); });

    cout << "\n\n=== Sorted container with circles ===\n\n";
    for (int i = 0; i < circles_vec.size(); i++)
    {
        cout << typeid(*circles_vec[i]).name() << " " << i << ":\n";
        cout << "Radius = " << setprecision(4) << circles_vec[i]->getRadius() << "\n\n";
    }
    
    // Computing the total sum of radii.
    double radii_sum = 0;

    for (int i = 0; i < circles_vec.size(); i++)
        radii_sum += circles_vec[i]->getRadius();

    cout << "\n\nTotal sum of radii of all curves in the second container = " << radii_sum << "\n\n";

    // Cleaning.

    for (int i = 0; i < curves_vec.size(); i++)
    {
        delete curves_vec[i];
    }


    return 0;
}