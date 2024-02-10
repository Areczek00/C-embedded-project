#include <string.h>
#include <stdlib.h>



double power(double base, double exponent) {
    double result = 1.0;

    if (exponent >= 0) {
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
    } else {
        for (int i = 0; i > exponent; i--) {
            result /= base;
        }
    }
    return result;
}

//Nuta (Note) jest zdefiniowana jako zestawienie cz�stotliwo�ci i d�ugo�ci. Cz�stotliwos� przechowujemy w Hz, d�ugo�� odpowiada notacji muzycznej: 1 to ca�a nuta, 2 to p�nuta (1/2), 4 - �wier�nuta (1/4), 8 - �semka (1/8), 16 - szesnastka (1/16).
typedef struct {
    float freq;
    int duration;
} Note;

/*Ta funkcja parsuje ci�g 4 znak�w i przekszta�ca go w struktur� Note.
Ci�g definiuje si� nast�puj�co:
Pierwsza litera jest literow� nazw� d�wi�ku : C, D, E, F, G, A, B (lub H)
Druga litera jest znakiem chromatycznym: brak (0), # lub b (bemol)
Trzecia litera okre�la numer oktawy, gdzie 0 -> subkontra, 1 -> kontra, 2 -> wielka, 3 -> ma�a, 4 -> razkre�lna, 5-> dwukre�lna,
itd.
Czwarta litera okre�la d�ugo�� nuty tak jak w strukturze Note.
Cz�stotliwo�� jest obliczana przez uzycie odpowiednich zale�no�ci muzycznych mi�dzy poszczeg�lnymi d�wi�kami w r�nych oktawach.*/
Note getNote(char noteString[4]) {
    Note note;
    const char baseNote = noteString[0];
    const char accidental = noteString[1];
    const char octave = noteString[2];
    const char durationChar = noteString[3];
    const long coeff = strtol(&octave, NULL, 10);

    switch (baseNote) {
        case 'c':
            case 'C':
                switch (accidental) {
                    case 'b':
                        note.freq = 246.94 * power(2, coeff - 4);
                        break;
                    case '0':
                        note.freq = 261.63 * power(2, coeff - 4);
                        break;
                    case '#':
                        note.freq = 277.18 * power(2, coeff - 4);
                        break;
                }
                break;
        case 'd':
            case 'D':
                switch (accidental) {
                    case 'b':
                        note.freq = 277.18 * power(2, coeff - 4);
                        break;
                    case '0':
                        note.freq = 293.66 * power(2, coeff - 4);
                        break;
                    case '#':
                        note.freq = 311.13 * power(2, coeff - 4);
                        break;
                }
                break;
        case 'e':
            case 'E':
                switch (accidental) {
                    case 'b':
                        note.freq = 311.13 * power(2, coeff - 4);
                        break;
                    case '0':
                        note.freq = 329.63 * power(2, coeff - 4);
                        break;
                    case '#':
                        note.freq = 349.23 * power(2, coeff - 4);
                        break;
                }
                break;
        case 'f':
            case 'F':
                switch (accidental) {
                    case 'b':
                        note.freq = 329.63 * power(2, coeff - 4);
                        break;
                    case '0':
                        note.freq = 349.23 * power(2, coeff - 4);
                        break;
                    case '#':
                        note.freq = 369.99 * power(2, coeff - 4);
                        break;
                }
                break;
        case 'g':
            case 'G':
                switch (accidental) {
                    case 'b':
                        note.freq = 369.99 * power(2, coeff - 4);
                        break;
                    case '0':
                        note.freq = 392.0 * power(2, coeff - 4);
                        break;
                    case '#':
                        note.freq = 415.30 * power(2, coeff - 4);
                        break;
                }
                break;
        case 'a':
            case 'A':
                switch (accidental) {
                    case 'b':
                        note.freq = 415.30 * power(2, coeff - 4);
                        break;
                    case '0':
                        note.freq = 440.0 * power(2, coeff - 4);
                        break;
                    case '#':
                        note.freq = 466.16 * power(2, coeff - 4);
                        break;
                }
                break;
        case 'h':
        case 'H':
        case 'b':
            case 'B':
                switch (accidental) {
                    case 'b':
                        note.freq = 466.16 * power(2, coeff - 4);
                        break;
                    case '0':
                        note.freq = 493.88 * power(2, coeff - 4);
                        break;
                    case '#':
                        note.freq = 523.25 * power(2, coeff - 4);
                        break;
                }
                break;
        default:
            break;
    }

    switch (durationChar) {
        case '1':
            note.duration = 1;
            break;
        case '2':
            note.duration = 2;
            break;
        case '4':
            note.duration = 4;
            break;
        case '8':
            note.duration = 8;
            break;
        case '6':
            note.duration = 16;
            break;
        default:
            break;
    }

    return note;
}
