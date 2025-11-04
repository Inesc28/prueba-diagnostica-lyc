/*1) Dado una cadena C, valide si C se encuentra en 
notación FEN (Forsyth-Edwards Notation), 
Forsyth–Edwards Notation. FEN (Wikipedia, 2025).*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include <cctype>

using namespace std;

vector<string> splitStringBySpaces(const string &str)
{
    vector<string> tokens;
    stringstream ss(str);
    string token;

    while (ss >> token)
    {
        tokens.push_back(token);
    }
    return tokens;
}

vector<string> splitRanks(const string &rankField)
{
    vector<string> ranks;
    stringstream ss(rankField);
    string rank;

    while (getline(ss, rank, '/'))
    {
        ranks.push_back(rank);
    }
    return ranks;
}

bool validateField(const string &field, const string &patternStr)
{
    try
    {
        regex pattern(patternStr);
        return regex_match(field, pattern);
    }
    catch (const regex_error &e)
    {
        cerr << "Error de Regex: " << e.what() << endl;
        return false;
    }
}

bool validatePieceRanks(const string &pieceField)
{
    vector<string> ranks = splitRanks(pieceField);

    if (ranks.size() != 8)
    {
        return false;
    }

    for (const string &rank : ranks)
    {
        int rowSum = 0;
        for (char c : rank)
        {
            if (isdigit(c))
            {
                rowSum += (c - '0');
            }
            else
            {
                rowSum += 1;
            }
        }

        if (rowSum != 8)
        {
            cout << "Error Logico: La fila '" << rank << "' no suma 8. Suma: " << rowSum << endl;
            return false;
        }
    }
    return true;
}

bool isValidFEN(const string &fen)
{
    vector<string> fields = splitStringBySpaces(fen);
    if (fields.size() != 6)
    {
        cout << "Error de Formato: La FEN no tiene 6 campos." << endl;
        return false;
    }

    if (!validateField(fields[0], "^([rnbqkpRNBQKP1-8]{1,8}(\\/[rnbqkpRNBQKP1-8]{1,8}){7})$"))
    {
        cout << "Error de Formato: Campo de piezas invalido." << endl;
        return false;
    }

    if (!validateField(fields[1], "^(w|b)$"))
    {
        cout << "Error de Formato: Campo de turno invalido." << endl;
        return false;
    }

    if (!validateField(fields[2], "^(-|[KQkq]{1,4})$"))
    {
        cout << "Error de Formato: Campo de enroque invalido." << endl;
        return false;
    }

    if (!validateField(fields[3], "^(-|[a-h][36])$"))
    {
        cout << "Error de Formato: Campo 'Al Paso' invalido." << endl;
        return false;
    }

    if (!validateField(fields[4], "^(\\d+)$"))
    {
        cout << "Error de Formato: Reloj de medio movimiento invalido." << endl;
        return false;
    }

    if (!validateField(fields[5], "^([1-9][0-9]*)$"))
    {
        cout << "Error de Formato: Numero de movimiento invalido." << endl;
        return false;
    }

    if (!validatePieceRanks(fields[0]))
    {
        return false;
    }

    return true;
}

int main()
{

    string fen_valida = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    string fen_valida_2 = "r1bqkbnr/pp1ppppp/2n5/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 2 2";
    string fen_invalida_formato = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0";
    string fen_invalida_logica = "rnbqkbnrp/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    string fen_invalida_logica_2 = "rnbqkbnr/pppppppp/1p7/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    cout << "Probando FEN valida (inicial):" << endl;
    cout << "Resultado: " << (isValidFEN(fen_valida) ? "VALIDA" : "INVALIDA") << endl;

    cout << "Probando FEN valida (otra):" << endl;
    cout << "Resultado: " << (isValidFEN(fen_valida_2) ? "VALIDA" : "INVALIDA") << endl;

    cout << "Probando FEN invalida (formato):" << endl;
    cout << "Resultado: " << (isValidFEN(fen_invalida_formato) ? "VALIDA" : "INVALIDA") << endl;

    cout << "Probando FEN invalida (logica fila 1):" << endl;
    cout << "Resultado: " << (isValidFEN(fen_invalida_logica) ? "VALIDA" : "INVALIDA") << endl;

    cout << "Probando FEN invalida (logica fila 3):" << endl;
    cout << "Resultado: " << (isValidFEN(fen_invalida_logica_2) ? "VALIDA" : "INVALIDA") << endl;

    return 0;
}