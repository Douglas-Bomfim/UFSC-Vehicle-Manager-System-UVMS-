#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <tuple>
#include <fstream>

using namespace std;
class Vehicle
{
    protected:
        string m_placa;
        string m_descricao_veiculo;
        float m_quilometragem_atual;
        float m_combustivel_gasto;
        float m_quilometragem_inicial;
        float m_km_apos_adicao;
        vector<tuple<string, float, float>>m_viagens;
    public:
        virtual ~Vehicle() = default;
        Vehicle() : m_placa(""), m_descricao_veiculo(""), m_quilometragem_atual(0),m_combustivel_gasto(0), m_quilometragem_inicial(0), m_km_apos_adicao(0){};
        Vehicle(string placa, string descricao_veiculo, float quilometragem_atual);
        void adicionar_viagem(string cidade, float distancia_percorrida, float combustivo_gasto);
        virtual string Tostring() const=0;
        virtual string salvar() const=0;
        string return_placa();
        string ToString_Viagem();
        string salvar_viagem();
};

class Car : public Vehicle
{
    private:
        float m_valor_tabela_fipe;

    public:
        Car() : Vehicle() {};
        Car(string placa, string descricao_veiculo, float quilometragem_atual, float valor_tabela_fipe);
        string Tostring() const override{
            stringstream sst;
            sst << m_placa <<"            "<< m_descricao_veiculo <<"               " << m_quilometragem_inicial << "            "<< m_quilometragem_atual<<"            "<< m_km_apos_adicao/m_combustivel_gasto <<"            " <<m_valor_tabela_fipe;
            return sst.str();
        }
        string salvar() const override{
            stringstream sst;
            sst << "car" << endl <<m_placa<< endl <<m_descricao_veiculo<< endl <<m_quilometragem_inicial<< endl <<m_valor_tabela_fipe<<endl;
            return sst.str();
        }
};

class Bus : public Vehicle
{
    private:
        string m_tipo_de_transporte;

    public:
        Bus() : Vehicle() {};
        Bus(string placa, string descricao_veiculo, float quilometragem_atual, string tipo_de_transporte);
        string Tostring() const override{
            stringstream sst;
            sst << m_placa <<"            "<< m_descricao_veiculo <<"               " << m_quilometragem_inicial << "            "<< m_quilometragem_atual<<"            "<< m_km_apos_adicao/m_combustivel_gasto <<"            " <<m_tipo_de_transporte;
            return sst.str();
        }
        string salvar() const override{
            stringstream sst;
            sst << "bus" << endl <<m_placa<< endl <<m_descricao_veiculo<< endl <<m_quilometragem_inicial<< endl <<m_tipo_de_transporte<<endl;
            return sst.str();
        }
};

class LightTruck : public Vehicle
{
    private:
        string m_tipo_de_carga_transportada;

    public:
        LightTruck() : Vehicle() {};
        LightTruck(string placa, string descricao_veiculo, float quilometragem_atual, string tipo_de_carga);
        string Tostring() const override{
            stringstream sst;
            sst << m_placa <<"            "<< m_descricao_veiculo <<"              " << m_quilometragem_inicial << "            "<< m_quilometragem_atual<<"            "<< m_km_apos_adicao/m_combustivel_gasto <<"             " <<m_tipo_de_carga_transportada;
            return sst.str();
        }
        string salvar() const override{
            stringstream sst;
            sst << "LightTruck" << endl <<m_placa<< endl <<m_descricao_veiculo<< endl <<m_tipo_de_carga_transportada<< endl <<m_quilometragem_inicial<<endl;
            return sst.str();
        }
};

class HeavyTruck : public Vehicle
{
    private:
        int m_quantidade_de_eixos;

    public:
        HeavyTruck() : Vehicle() {};
        HeavyTruck(string placa, string descricao_veiculo, float quilometragem_atual, int quantidade_de_eixos);
        string Tostring() const override{
            stringstream sst;
            sst << m_placa <<"            "<< m_descricao_veiculo <<"             " << m_quilometragem_inicial << "            "<< m_quilometragem_atual<<"            "<< m_km_apos_adicao/m_combustivel_gasto <<"             " <<m_quantidade_de_eixos;
            return sst.str();
        }
        string salvar() const override{
            stringstream sst;
            sst << "HeavyTruck" << endl <<m_placa<< endl <<m_descricao_veiculo<< endl <<m_quilometragem_inicial<< endl <<m_quantidade_de_eixos<<endl;
            return sst.str();
        }
};