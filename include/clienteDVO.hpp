#pragma once
#include <string>

class Cliente {
private:
    int id;
    std::string nome;
    std::string cpf;
    std::string endereco;
    std::string telefone;
public:
    Cliente() : id(INT_MIN), nome(""), cpf(""), endereco(""), telefone("") {}
    Cliente(int id, const std::string &nome, const std::string &cpf, const std::string &endereco, const std::string &telefone) : id(id), nome(nome), cpf(cpf), telefone(telefone), endereco(endereco) { }
    

    int getId() const { return id; }
    std::string getNome() const { return nome; }
    std::string getCpf() const { return cpf; }
    std::string getEndereco() const { return endereco; }
    std::string getTelefone() const { return telefone; }


    void setId(int id) { this->id = id; }
    void setNome(const std::string &nome) { this->nome = nome; }
    void setCpf(const std::string &cpf) { this->cpf = cpf; }
    void setEndereco(const std::string &endereco) { this->endereco = endereco; }
    void setTelefone(const std::string &telefone) { this->telefone = telefone; }

};