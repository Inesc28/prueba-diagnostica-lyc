#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <cctype>

using namespace std;

map<string, string> crearDiccionarioTraduccion()
{
    map<string, string> dict;

    dict["auto"] = "automatico";
    dict["break"] = "romper";
    dict["case"] = "caso";
    dict["char"] = "caracter";
    dict["const"] = "constante";
    dict["continue"] = "continuar";
    dict["default"] = "por_defecto";
    dict["do"] = "hacer";
    dict["double"] = "doble";
    dict["else"] = "sino";
    dict["enum"] = "enumeracion";
    dict["extern"] = "externo";
    dict["float"] = "flotante";
    dict["for"] = "para";
    dict["goto"] = "ir_a";
    dict["if"] = "si";
    dict["int"] = "entero";
    dict["long"] = "largo";
    dict["register"] = "registro";
    dict["return"] = "retornar";
    dict["short"] = "corto";
    dict["signed"] = "con_signo";
    dict["sizeof"] = "tamano_de";
    dict["static"] = "estatico";
    dict["struct"] = "estructura";
    dict["switch"] = "segun";
    dict["typedef"] = "definir_tipo";
    dict["union"] = "union";
    dict["unsigned"] = "sin_signo";
    dict["void"] = "vacio";
    dict["volatile"] = "volatil";
    dict["while"] = "mientras";

    return dict;
}

int main()
{
    map<string, string> traducciones = crearDiccionarioTraduccion();

    string linea;
    string codigoC;

    cout << "--- Analizador de Palabras Reservadas C ---\n";
    cout << "Pega tu código C aquí. \n";
    cout << "Presiona Ctrl+D (Linux/macOS) o Ctrl+Z y Enter (Windows) para finalizar.\n";
    cout << "--------------------------------------------------\n";

    while (getline(cin, linea))
    {
        codigoC += linea + "\n";
    }

    string codigoParseable = codigoC;
    for (char &c : codigoParseable)
    {
        if (!std::isalnum(static_cast<unsigned char>(c)) && c != '_')
        {
            c = ' ';
        }
    }

    stringstream ss(codigoParseable);
    string palabra;
    set<string> palabrasEncontradas;

    cout << "\n--- Traducciones Encontradas ---\n";

    while (ss >> palabra)
    {
        auto it = traducciones.find(palabra);

        if (it != traducciones.end())
        {

            if (palabrasEncontradas.find(it->first) == palabrasEncontradas.end())
            {
                cout << "  [C] " << it->first << "  =>  [Espanol] " << it->second << endl;
                palabrasEncontradas.insert(it->first);
            }
        }
    }

    if (palabrasEncontradas.empty())
    {
        cout << "No se encontraron palabras reservadas de C en el codigo proporcionado.\n";
    }

    cout << "----------------------------------\n";
    return 0;
}