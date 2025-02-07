#pragma once

#include <clienteDAO.hpp>
#include <clienteDVO.hpp>
#include <stdexcept>
#include <vector>


class ClienteManager {
private:
    std::shared_ptr<ClienteDAO> clienteDAO;
public:
    ClienteManager(std::shared_ptr<ClienteDAO> dao) : clienteDAO(dao) { }

    void cadastrarCliente(std::shared_ptr<Cliente> cliente) {
        if (cliente->getNome().empty())
            throw std::invalid_argument("Nome do cliente não pode ser vazio");
        if (!clienteDAO->adicionar(cliente))
            throw std::runtime_error("Falha ao cadastrar cliente");
    }
    
    std::shared_ptr<Cliente> obterCliente(int id) {
        std::shared_ptr<Cliente> c = clienteDAO->buscar(id);
        if (c->getId() == -1)
            throw std::runtime_error("Cliente não encontrado");
        return c;
    }
    
    void atualizarCliente(std::shared_ptr<Cliente> cliente) {
        if (!clienteDAO->atualizar(cliente))
            throw std::runtime_error("Falha ao atualizar cliente");
    }
    
    void removerCliente(int id) {
        if (!clienteDAO->remover(id))
            throw std::runtime_error("Falha ao remover cliente");
    }
    
    std::vector<std::shared_ptr<Cliente>> listarClientes() {
        return clienteDAO->listar();
    }
};