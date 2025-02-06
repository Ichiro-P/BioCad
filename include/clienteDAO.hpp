#pragma once
#include <clienteDVO.hpp>
#include <vector>

class ClienteDAO {
private:
    std::vector<Cliente> clientes;
public:
    bool adicionar(const Cliente &cliente);
    bool atualizar(const Cliente &cliente);
    bool remover(int id);
    Cliente buscar(int id);
    std::vector<Cliente> listar();
};