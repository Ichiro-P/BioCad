#pragma once
#include <string>

class Cliente {
private:
    int id;
    std::string nome;
    std::string email;
public:
    Cliente() : id(0), nome(""), email("") { }
    Cliente(int id, const std::string &nome, const std::string &email) : id(id), nome(nome), email(email) { }
    

    int getId() const { return id; }
    void setId(int id) { this->id = id; }

    std::string getNome() const { return nome; }
    void setNome(const std::string &nome) { this->nome = nome; }

    std::string getEmail() const { return email; }
    void setEmail(const std::string &email) { this->email = email; }
};