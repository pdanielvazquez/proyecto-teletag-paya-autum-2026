#ifndef __PEAJE_H__
#define __PEAJE_H__

#include <iostream>
#include <string>
using namespace std;
// ============================================================================
// CLASE COMPONENTE: Teletag
// ============================================================================
class Teletag {
private:
    string idTag;
    string categoriaVehiculo;
    double saldo;

public:
    // Constructores
    Teletag();
    Teletag(string id, string cat, double saldoInicial);

    // Métodos
    string obtenerID() const;
    string obtenerCategoria() const;
    double obtenerSaldo() const;
    bool descontarSaldo(double monto);
    void recargar(double monto);
};

// ============================================================================
// CLASE CONTENEDORA: CasetaPeaje
// ============================================================================
class CasetaPeaje {
private:
    int numeroCarril;
    double tarifaBase;
    Teletag tagProcesado; 

public:
    // Constructor
    CasetaPeaje(int carril, double tarifa, string idTag, string cat, double saldoTag);

    // Métodos 
    int obtenerCarril() const;
    double obtenerTarifa() const;
    double obtenerSaldoTag() const;
    void auditarCaseta() const;


    bool procesarCobro();
    const Teletag& obtenerTagConstante() const; 
    Teletag& obtenerTagModificable();           
};

#endif // __PEAJE_H__