#include <iostream>
#include <string>

class Funcionario {
public:
    std::string nome;
    int id;    
    double salarioBase; 


    Funcionario(const std::string& nome, int id, double salarioBase)
        :nome(nome), id(id), salarioBase(salarioBase) {}
};

class FuncionarioRegular : public Funcionario 
{
    public:
    FuncionarioRegular(const std::string& nome, int id, double salarioBase )
        :Funcionario(nome,id,salarioBase){}
    double calcularSalarioTotal(double salarioBase){
        return (salarioBase*1);
    }
};


class Gerente : public Funcionario
{
    public:
    double lucroFilial;
    Gerente(const std::string& nome, int id, double salarioBase, double lucroFilial )
        :Funcionario(nome,id,salarioBase), lucroFilial(lucroFilial){}

    double calcularSalarioTotal(double salarioBase,double lucroFilial){
        return (salarioBase+ 0.1*lucroFilial);
    };

    double bonusAnual(double lucroFilial){
        return (0.1*lucroFilial);
    }
};


class Estagiario : public Funcionario
{
    public:
    Estagiario(const std::string& nome, int id, double salarioBase )
        :Funcionario(nome,id,salarioBase){}
      

    double calcularSalarioTotal(double salarioBase){
        return (salarioBase);
    };

};


int main() {
    Estagiario estagiario0("joao", 001, 1000.0);
    Estagiario estagiario1("Maria", 002, 1000.0);
    Estagiario estagiario2("jose", 003, 1000.0);
    Estagiario estagiario3("julia", 004, 1000.0);

    Gerente gerente0("bruna", 005, 5000.0, 50000.0);
    Gerente gerente1("beto", 006, 5000.0, 50000.0);
    Gerente gerente2("leo", 007, 5000.0, 50000.0);
    Gerente gerente3("camila",010, 5000.0, 50000.0);


    FuncionarioRegular FuncionarioRegular0("steve", 011, 2000.0);
    FuncionarioRegular FuncionarioRegular1("bob", 012, 2000.0);
    FuncionarioRegular FuncionarioRegular2("leticia", 013, 2000.0);
    FuncionarioRegular FuncionarioRegular3("fernanda", 014, 2000.0);

    std::cout << "Salario total do gerente " << gerente0.nome << ": R$" << gerente0.calcularSalarioTotal(gerente0.salarioBase, gerente0.lucroFilial) << std::endl;
    std::cout << "Salario total do gerente " << gerente2.nome << ": R$" << gerente2.calcularSalarioTotal(gerente2.salarioBase, gerente3.lucroFilial) << std::endl;
    std::cout << "Salario total do gerente " << gerente3.nome << ": R$" << gerente3.calcularSalarioTotal(gerente3.salarioBase, gerente2.lucroFilial) << std::endl;

    std::cout << "Salario total do Estagiario " << estagiario0.nome << ": R$" << estagiario0.calcularSalarioTotal(estagiario0.salarioBase) << std::endl;
    std::cout << "Salario total do Estagiario " << estagiario2.nome << ": R$" << estagiario2.calcularSalarioTotal(estagiario2.salarioBase) << std::endl;
    std::cout << "Salario total do Estagiario " << estagiario1.nome << ": R$" << estagiario1.calcularSalarioTotal(estagiario1.salarioBase) << std::endl;

    std::cout << "Salario total do FuncionarioRegular " << FuncionarioRegular0.nome << ": R$" << FuncionarioRegular0.calcularSalarioTotal(FuncionarioRegular0.salarioBase) << std::endl;
    std::cout << "Salario total do FuncionarioRegular " << FuncionarioRegular2.nome << ": R$" << FuncionarioRegular2.calcularSalarioTotal(FuncionarioRegular2.salarioBase) << std::endl;
    std::cout << "Salario total do FuncionarioRegular " << FuncionarioRegular3.nome << ": R$" << FuncionarioRegular3.calcularSalarioTotal(FuncionarioRegular3.salarioBase) << std::endl;
    return 0;
}