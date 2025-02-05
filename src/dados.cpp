#include <iostream>
#include <string>

#include <dados.hpp>
#include <gerente.hpp>
#include <atendente.hpp>
#include <cliente.hpp>

void dados::visualizarRelatorioFinanceiro() {
}

void dados::listarClientes() {
    for(const auto& cliente: clientes) {
        std::cout << "id: " << cliente.getId() << "; Nome: " << cliente.getNome() << '\n';
    }
}

void dados::cadastrarCliente() {
    std::string nome, cpf, telefone, dataNascimento, dataCadastro;
    int duracao;
    std::cout << "Informe o nome completo do cliente: ";
    std::getline(std::cin, nome);
}

void dados::atualizarCliente() {
}

void dados::removerCliente() {
}

void dados::listarAtendentes() {
}

void dados::cadastrarAtendente() {
}

void dados::atualizarAtendente() {

}

void dados::removerAtendente() {
}

void dados::listarPersonalTrainers() {
}

void dados::cadastrarPersonalTrainer() {
}

void dados::atualizarPersonalTrainer() {

}

void dados::removerPersonalTrainer() {

}