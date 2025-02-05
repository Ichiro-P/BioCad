#include <iostream>
#include <string>
#include <dados.hpp>

void visualizarRelatorioFinanceiro() {
}

void listarClientes() {
    for(const auto& cliente: clientes) {
        std::cout << "id: " << cliente.getId() << "; Nome: " << cliente.getNome() << '\n';
    }
}
