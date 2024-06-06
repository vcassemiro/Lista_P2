#include <iostream>
#include <string>
#include <vector>

class Veiculo {
protected:
    std::string marca;
    std::string modelo;
    int capacidade; // Capacidade de carga em toneladas

public:
    Veiculo(const std::string& marca, const std::string& modelo, int capacidade)
        : marca(marca), modelo(modelo), capacidade(capacidade) {}

    virtual void exibirDados() const {
        std::cout << "Marca: " << marca << ", Modelo: " << modelo << ", Capacidade: " << capacidade << " toneladas\n";
    }
};

class Caminhao : public Veiculo {
private:
    int eixos;

public:
    Caminhao(const std::string& marca, const std::string& modelo, int capacidade, int eixos)
        : Veiculo(marca, modelo, capacidade), eixos(eixos) {}

    void exibirDados() const override {
        std::cout << "Caminhao - ";
        Veiculo::exibirDados();
        std::cout << "Eixos: " << eixos << "\n";
    }
};

class Van : public Veiculo {
private:
    int passageiros;

public:
    Van(const std::string& marca, const std::string& modelo, int capacidade, int passageiros)
        : Veiculo(marca, modelo, capacidade), passageiros(passageiros) {}

    void exibirDados() const override {
        std::cout << "Van - ";
        Veiculo::exibirDados();
        std::cout << "Passageiros: " << passageiros << "\n";
    }
};

int main() {
    std::vector<Veiculo*> frota;

    Caminhao caminhao1("Scania", "V8", 20, 4);
    Van van1("Mercedes", "Sprinter", 2, 12);

    frota.push_back(&caminhao1);
    frota.push_back(&van1);

    for (const auto& veiculo : frota) {
        veiculo->exibirDados();
    }

    return 0;
}
