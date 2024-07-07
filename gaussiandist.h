#ifndef GAUSSIANDIST_H
#define GAUSSIANDIST_H

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

void print_gaussian_dist(int expected_value, int std_deviation, int amount_of_values, FILE* output_stream) {
    std::srand(std::time(nullptr)); // Seed für Zufallszahlen-Generator initialisieren

    for (int i = 0; i < amount_of_values; ++i) {
        double u1 = std::rand() / (RAND_MAX + 1.0);
        double u2 = std::rand() / (RAND_MAX + 1.0);
        double rand_std_normal = std::sqrt(-2.0 * std::log(u1)) * std::cos(2.0 * M_PI * u2);
        double rand_normal = expected_value + std_deviation * rand_std_normal;

        fprintf(output_stream, "%.6f\n", rand_normal);
    }
}

#endif
