#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

vector<string> splitStringByChar(const string &s, char delimiter)
{
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

bool esNotacionCientifica(const string &s)
{
    string patron = "^[-+]?(\\d+(\\.\\d+)?|\\.\\d+)([eE][-+]?\\d+)$";
    return regex_match(s, regex(patron));
}

bool esIP(const string &s)
{

    // Parte A: Validación de Formato (Regex)
    string patronEstructura = "^(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})$";
    if (!regex_match(s, regex(patronEstructura)))
    {
        return false;
    }

    // Parte B: Validación de Lógica
    vector<string> octetos = splitStringByChar(s, '.');
    for (const string &octeto_str : octetos)
    {
        try
        {
            int numero = stoi(octeto_str);
            if (numero < 0 || numero > 255)
            {
                return false;
            }
        }
        catch (...)
        {
            return false;
        }
    }
    return true;
}

bool esCorreoElectronico(const string &s)
{
    string patron = "^[\\w\\.-]+@([\\w-]+\\.)+[\\w-]{2,4}$";
    return regex_match(s, std::regex(patron));
}

int main()
{

    cout << "--- Pruebas  ---" << endl;

    cout << "IP (192.168.1.1):    " << (esIP("192.168.1.1") ? "Valido" : "Invalido") << endl;
    cout << "IP (999.1.1.1):      " << (esIP("999.1.1.1") ? "Valido" : "Invalido") << endl;

    cout << "Correo (tooti@gmail.com):    " << (esCorreoElectronico("tooti@gmail.com") ? "Valido" : "Invalido") << endl;
    cout << "Correo (arroba.com): " << (esCorreoElectronico("arroba.com") ? "Valido" : "Invalido") << endl;

    cout << "Not. Cient. (1.5e-3): " << (esNotacionCientifica("1.5e-3") ? "Valido" : "Invalido") << endl;
    cout << "Not. Cient. (1.5e):   " << (esNotacionCientifica("1.5e") ? "Valido" : "Invalido") << endl;

    return 0;
}