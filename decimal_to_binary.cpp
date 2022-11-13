#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    //? Dichiara il numero decimale e la base
    int decimalnumber;
    const int base = 2;

    //? Legge il numero da convertire
    cout << "--- CONVERSIONE DA DECIMALE A BINARIO ---" << endl;

    cout << "Inserisci il numero da convertire: ";
    cin >> decimalnumber;

    string result;
    int number = decimalnumber;
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

    //? Stampa il numero
    cout << "Il numero " << decimalnumber << ", in codice binario e': " << result << endl;

    //? Finisce il programma
    cout << "Premi un tasto per uscire dal programma ";
    system("PAUSE > Nul");
    return 0;
}