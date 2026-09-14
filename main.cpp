#include <iostream>
#include "Peaje.h"
using namespace std;

// 1. Paso por referencia constante
void reportarEstadoCaseta(const CasetaPeaje& caseta) {
    cout << "\n[REPORTE OFICIAL DE AUDITORÍA]" << endl;
    caseta.auditarCaseta();
    // caseta.procesarCobro(); // Error de compilación si se descomenta
}

// 2. Paso por referencia
void realizarCobroDirecto(CasetaPeaje& caseta) {
    cout << "\n[PROCESANDO PEAJE VEHICULAR]" << endl;
    caseta.procesarCobro();
}

// 3. Paso por valor (Tipo):
void simularCobroSimulado(CasetaPeaje casetaCopia) {
    cout << "\n[SIMULACIÓN AISLADA EN COPIA TEMPORAL]" << endl;
    casetaCopia.procesarCobro();
    cout << "Saldo en copia temporal tras simulación: $" << casetaCopia.obtenerSaldoTag() << endl;
}

int main() {
    cout << "==========================================================" << endl;
    cout << " SISTEMA DE CONTROL DE PEAJE AUTOMÁTICO (AUTOPISTAS) " << endl;
    cout << "==========================================================" << endl;

    // Instanciación del objeto compuesto
    CasetaPeaje casetaExpress(3, 80.0, "TAG-MEX-9876", "Automóvil", 250.0);

    // Auditoría inicial
    reportarEstadoCaseta(casetaExpress);

    // Cobro simulado por valor
    simularCobroSimulado(casetaExpress);
    cout << "Verificación en main(): Saldo real tras simulación = $" << casetaExpress.obtenerSaldoTag() << endl;

    // Cobro real por referencia
    realizarCobroDirecto(casetaExpress);

    // Auditoría final
    reportarEstadoCaseta(casetaExpress);

    return 0;
}