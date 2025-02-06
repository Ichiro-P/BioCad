#pragma once

#include <clienteDAO.hpp>
#include <clienteDVO.hpp>
#include <stdexcept>
#include <vector>


class ClienteManager {
private:
    std::unique_ptr<ClienteDAO> clienteDAO;
public:
    ClienteManager(std::unique_ptr<ClienteDAO> dao) : clienteDAO(std::move(dao)) { }

    void cadastrarCliente(const Cliente &cliente) {
        if (cliente.getNome().empty())
            throw std::invalid_argument("Nome do cliente não pode ser vazio");
        if (!clienteDAO->adicionar(cliente))
            throw std::runtime_error("Falha ao cadastrar cliente");
    }
    
    Cliente obterCliente(int id) {
        Cliente c = clienteDAO->buscar(id);
        if (c.getId() == -1)
            throw std::runtime_error("Cliente não encontrado");
        return c;
    }
    
    void atualizarCliente(const Cliente &cliente) {
        if (!clienteDAO->atualizar(cliente))
            throw std::runtime_error("Falha ao atualizar cliente");
    }
    
    void removerCliente(int id) {
        if (!clienteDAO->remover(id))
            throw std::runtime_error("Falha ao remover cliente");
    }
    
    std::vector<Cliente> listarClientes() {
        return clienteDAO->listar();
    }
};