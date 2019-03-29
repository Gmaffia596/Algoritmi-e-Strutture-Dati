#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>
/**
GESTIONE DELLE ECCEZIONI IN BASE AGLI ERRORI CHE POSSONO VERIFICARSI
**/

struct NullNode : public std::invalid_argument //CAMPO DATO NON VALIDO
{
    NullNode() : invalid_argument(
        "Parametro nodo nullo.") {};
};

struct FullSize : public std::invalid_argument 
{
    FullSize() : invalid_argument(
        "Dimensione massima raggiunta.") {};
};

struct RootExists : public std::domain_error 
{
    RootExists() : domain_error(
        "Radice già presente.") {};
};

struct EmptyTree : public std::domain_error 
{
    EmptyTree() : domain_error(
        "Albero vuoto.") {};
};

struct NodeExists : public std::domain_error 
{
    NodeExists() : domain_error(
        "Nodo già presente.") {};
};


#endif
