#include <cstdio>
#include <cstdlib>
#include <unistd.h> // für getopt
#include "gaussiandist.h"

int main(int argc, char* argv[]) {
    int expected_value = 0;
    int std_deviation = 1;
    int amount_of_values = 100;
    const char* output_filename = nullptr;

    // Verarbeitung der Kommandozeilenoptionen
    int opt;
    while ((opt = getopt(argc, argv, "he:s:n:o:")) != -1) {
        switch (opt) {
            case 'h':
                // Hilfetext ausgeben oder Hilfe-Funktion aufrufen
                printf("Hilfetext:\n");
                printf(" -e <expected value>: Erwartungswert (Standard: 0)\n");
                printf(" -s <std deviation>: Standardabweichung (Standard: 1)\n");
                printf(" -n <amount of values>: Anzahl der Werte (Standard: 100)\n");
                printf(" -o <output file>: Ausgabedatei\n");
                return 0;
            case 'e':
                expected_value = atoi(optarg);
                break;
            case 's':
                std_deviation = atoi(optarg);
                break;
            case 'n':
                amount_of_values = atoi(optarg);
                break;
            case 'o':
                output_filename = optarg;
                break;
            default:
                fprintf(stderr, "Usage: %s [-e expected value] [-s std deviation] [-n amount of values] [-o output file]\n", argv[0]);
                return 1;
        }
    }

    // Überprüfen, ob eine Ausgabedatei angegeben wurde
    if (output_filename == nullptr) {
        fprintf(stderr, "Error: Ausgabedatei nicht angegeben.\n");
        return 1;
    }

    // Ausgabedatei öffnen
    FILE* output_stream = fopen(output_filename, "w");
    if (output_stream == nullptr) {
        perror("Fehler beim Öffnen der Ausgabedatei");
        return 1;
    }

    // Gaußverteilung berechnen und in die Ausgabedatei schreiben
    print_gaussian_dist(expected_value, std_deviation, amount_of_values, output_stream);

    // Ausgabedatei schließen
    fclose(output_stream);

    printf("Gaußverteilung mit Erwartungswert %d, Standardabweichung %d und %d Werten wurde in %s geschrieben.\n",
           expected_value, std_deviation, amount_of_values, output_filename);

    return 0;
}
