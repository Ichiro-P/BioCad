#pragma once

#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <memory>
#include <chrono>
#include <enums.hpp>

class CheckOutDVO {
    std::string cpfCliente = "";
    std::tm dataHora;
    public:
    CheckOutDVO() =  default;
    CheckOutDVO(const std::string &cpfCliente);
    std::string getCpfCliente() { return cpfCliente; };
    std::tm getDataHora() const&;
};

class CheckOutDAO {
    std::vector<std::unique_ptr<CheckOutDVO>> checkOuts;
    public:
    CheckOutDAO() = default;
    void create(const std::string &cpfCliente);
    std::vector<CheckOutDVO> getCheckOutsDVO() const&;
};

class CheckOutManager {
    std::unique_ptr<CheckOutDAO> checkOutDAO = nullptr;
    public:
    CheckOutManager() = default;
    CheckOutManager(CheckOutDAO &&checkOut) : checkOutDAO(std::make_unique<CheckOutDAO>(std::move(checkOut))) {};
    void adicionarCheckOut(const std::string &cpfCliente) { if(!cpfCliente.empty()) checkOutDAO->create(cpfCliente); };
    std::vector<CheckOutDVO> getCheckOutsPeriodo(const std::tm &dataInicio, const std::tm &dataFim);
};