#include <loginManager.hpp>
#include <clienteManager.hpp>
#include <usuarioManager.hpp>
#include <clienteDAO.hpp>
#include <usuarioDAO.hpp>
#include <clienteDVO.hpp>
#include <usuarioDVO.hpp>
#include <sistemaManager.hpp>

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <limits>

/*
colinha de cadastros para debug (tipo, login, senha, nome):
Atendente eduardo(1, "eduardo", "maromba", "Eduardo");
PersonalTrainer suteam(2, "suteam", "mateus", "Matheus Vinicius");
Gerente root(3, "root", "root", "Administrador");

*/

int main() {
    iniciarSistema();
    
    return 0;
}