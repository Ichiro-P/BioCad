#pragma once
#include <clienteDVO.hpp>
#include <vector>
#include <memory>

class ClienteDAO {
private:
    std::vector<std::shared_ptr<Cliente>> clientes;
public:
    ClienteDAO(const std::vector<std::shared_ptr<Cliente>>& vetorClientes);

    bool adicionar(std::shared_ptr<Cliente> cliente);
    bool atualizar(std::shared_ptr<Cliente> cliente);
    bool remover(int id);
    std::shared_ptr<Cliente> buscar(int id);
    std::vector<std::shared_ptr<Cliente>> listar();
};