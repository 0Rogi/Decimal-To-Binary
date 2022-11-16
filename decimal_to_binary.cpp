#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    //? Dichiara il numero decimale e la base
    float decimalnumber;
    const int base = 2;

    //? Legge il numero da convertire
    cout << "--- CONVERSIONE DA DECIMALE A BINARIO ---" << endl;

    cout << "Inserisci il numero da convertire: ";
    cin >> decimalnumber;

    string result;
    float number = decimalnumber;
    int divisionremainder;
    int i = 0;

    //? Trasforma il numero da base 10 a base 2
    while (true)
    {
        divisionremainder = remainder(number, base);
        if (divisionremainder < 0)
        {
            divisionremainder = divisionremainder * -1;
        }

        result = result + to_string(divisionremainder)[0];

        number = floor(number / 2);

        // //cout << number << "\t" << divisionremainder << endl;

        if (number == 0)
        {
            break;
        }
    }

    //? Inverte la stringa
    reverse(result.begin(), result.end());

    //? Controlla se c'è una parte decimale
    int wholepart = floor(decimalnumber);
    float decimalpart = decimalnumber - wholepart;

    if (decimalpart != 0) //? Se c'è una parte decimale
    {
        //? Legge quante volte la parte decimale deve essere calcolata
        int iteration;
        cout << "Inserisci il numero di volte che la parte decimale deve essere calcolata (2 di default): ";
        cin >> iteration;
        //? Se il numero di volte è minore di 0 o inesistente, mette 2 di defaul
        if (!iteration || iteration < 1)
        {
            iteration = 2;
        }

        //? Trasforma la parte decimale in binario
        string decimalresult = ".";

        for (i = 0; i < iteration; i++)
        {
            wholepart = floor(decimalpart * 2);
            decimalpart = decimalpart * 2 - wholepart;

            decimalresult = decimalresult + to_string(wholepart)[0];
        }

        result = result + decimalresult;
    }

    //? Stampa il numero
    cout << "Il numero " << decimalnumber << " in codice binario e': " << result << endl;

    //? Finisce il programma
    cout << "Premi un tasto per uscire dal programma ";
    system("PAUSE > Nul");
    return 0;
}