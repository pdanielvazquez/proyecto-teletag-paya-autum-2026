#include "Peaje.h"
#include <iomanip>
#include <iostream>
using namespace std;
// ============================================================================
// IMPLEMENTACIÓN DE LA CLASE Teletag
// ============================================================================
Teletag::Teletag() 
    : idTag("0000-DEFAULT"), categoriaVehiculo("Automóvil"), saldo(0.0) {}

Teletag::Teletag(std::string id, std::string cat, double saldoInicial)
    : idTag(id), categoriaVehiculo(cat), saldo(saldoInicial) {}

std::string Teletag::obtenerID() const {
    return idTag;
}

std::string Teletag::obtenerCategoria() const {
    return categoriaVehiculo;
}

double Teletag::obtenerSaldo() const {
    return saldo;
}

bool Teletag::descontarSaldo(double monto) {
    if (saldo >= monto) {
        saldo -= monto;
        return true;
    }
    return false;
}

void Teletag::recargar(double monto) {
    if (monto > 0.0) {
        saldo += monto;
    }
}

// ============================================================================
// IMPLEMENTACIÓN DE LA CLASE CasetaPeaje
// ============================================================================
CasetaPeaje::CasetaPeaje(int carril, double tarifa, std::string idTag, std::string cat, double saldoTag)
    : numeroCarril(carril), tarifaBase(tarifa), tagProcesado(idTag, cat, saldoTag) {}

int CasetaPeaje::obtenerCarril() const {
    return numeroCarril;
}

double CasetaPeaje::obtenerTarifa() const {
    return tarifaBase;
}

double CasetaPeaje::obtenerSaldoTag() const {
    return tagProcesado.obtenerSaldo();
}

void CasetaPeaje::auditarCaseta() const {
    cout << " [Caseta Carril #" << numeroCarril << "] Tarifa: $" << tarifaBase 
              << " | ID Tag: " << tagProcesado.obtenerID() 
              << " | Categoría: " << tagProcesado.obtenerCategoria()
              << " | Saldo Tag: $" << tagProcesado.obtenerSaldo() << endl;
}

bool CasetaPeaje::procesarCobro() {
    double montoFinal = tarifaBase;
    
    if (tagProcesado.obtenerCategoria() == "Camión") {
        montoFinal *= 1.5; 
    } else if (tagProcesado.obtenerCategoria() == "Motocicleta") {
        montoFinal *= 0.5; 
    }

    if (tagProcesado.descontarSaldo(montoFinal)) {
        cout << " -> Cobro de $" << montoFinal << " APROBADO en carril #" << numeroCarril << "." << endl;
        return true;
    } else {
        cout << " -> ERROR: Saldo insuficiente ($" << tagProcesado.obtenerSaldo() 
                  << ") para cubrir tarifa de $" << montoFinal << " en carril #" << numeroCarril << "." << endl;
        return false;
    }
}

const Teletag& CasetaPeaje::obtenerTagConstante() const {
    return tagProcesado;
}

Teletag& CasetaPeaje::obtenerTagModificable() {
    return tagProcesado;
}