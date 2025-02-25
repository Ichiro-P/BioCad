#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <memory>
#include <chrono>
#include <enums.hpp>
#include <checkOut.hpp>

CheckOutDVO::CheckOutDVO(const std::string &cpfCliente) : cpfCliente(cpfCliente) {
    this->cpfCliente.resize(14);
    dataHora = [](std::time_t t) {
        std::tm tm;
    #if defined(_WIN32)
        localtime_s(&tm, &t);
    #else
        localtime_r(&t, &tm);
    #endif
        return tm;
    }(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
}

std::tm CheckOutDVO::getDataHora() const& {
    return dataHora;
}

void CheckOutDAO::create(const std::string &cpfCliente) {
    checkOuts.push_back(std::make_unique<CheckOutDVO>(std::move(CheckOutDVO(cpfCliente))));
}

std::vector<CheckOutDVO> CheckOutDAO::getCheckOutsDVO() const& {
    std::vector<CheckOutDVO> res;
    res.reserve(checkOuts.size());
    for(const auto &it: checkOuts) {
        res.push_back(*it);
    }
    return res;
}

std::vector<CheckOutDVO> CheckOutManager::getCheckOutsPeriodo(const std::tm &dataOuticio, const std::tm &dataFim) {
    std::tm inicioCopia = dataOuticio;
    std::tm fimCopia = dataFim;

    std::time_t tInicio = std::mktime(&inicioCopia);
    std::time_t tFim = std::mktime(&fimCopia);
    std::vector<CheckOutDVO> res;
    for(const auto &it: checkOutDAO->getCheckOutsDVO()) {
        std::tm checkData = it.getDataHora();
        std::time_t tCheck = std::mktime(&checkData);
        if (tCheck >= tInicio && tCheck <= tFim) {
            res.push_back(it);
        }
    }
    return res;
}