#include "vehicle.hpp"

Car::Car(string placa, string descricao_veiculo, float quilometragem_atual, float valor_tabela_fipe)
{
    m_placa=placa;
    m_descricao_veiculo=descricao_veiculo;
    m_quilometragem_atual=quilometragem_atual;
    m_quilometragem_inicial=quilometragem_atual;
    m_valor_tabela_fipe=valor_tabela_fipe;
}

Bus::Bus(string placa, string descricao_veiculo, float quilometragem_atual, string tipo_de_transporte)
{
    m_placa=placa;
    m_descricao_veiculo=descricao_veiculo;
    m_quilometragem_atual=quilometragem_atual;
    m_tipo_de_transporte=tipo_de_transporte;
    m_quilometragem_inicial=quilometragem_atual;
}

LightTruck::LightTruck(string placa, string descricao_veiculo, float quilometragem_atual, string tipo_de_carga_transportada)
{
    m_placa=placa;
    m_descricao_veiculo=descricao_veiculo;
    m_quilometragem_atual=quilometragem_atual;
    m_tipo_de_carga_transportada=tipo_de_carga_transportada;
    m_quilometragem_inicial=quilometragem_atual;
}

HeavyTruck::HeavyTruck(string placa, string descricao_veiculo, float quilometragem_atual, int quantida_de_eixos)
{
    m_placa=placa;
    m_descricao_veiculo=descricao_veiculo;
    m_quilometragem_atual=quilometragem_atual;
    m_quantidade_de_eixos=quantida_de_eixos;
    m_quilometragem_inicial=quilometragem_atual;
}

void Vehicle::adicionar_viagem(string cidade, float distancia_percorrida, float combustivo_gasto)
{
    m_viagens.push_back(make_tuple(cidade, distancia_percorrida, combustivo_gasto));
    m_km_apos_adicao+=distancia_percorrida;
    m_combustivel_gasto+=combustivo_gasto;
    m_quilometragem_atual+=distancia_percorrida;
}
string Vehicle::return_placa()
{
    return m_placa;
}

string Vehicle::ToString_Viagem()
{
    stringstream sst;
    for(size_t i =0; i < m_viagens.size(); i++)
    {
        sst << get<0>(m_viagens.at(i)) << "      " <<  get<1>(m_viagens.at(i)) << endl;
    }

    return sst.str();
}

string Vehicle::salvar_viagem()
{
    stringstream sst;
    if(!m_viagens.empty())
    {
    for(size_t i=0; i<m_viagens.size(); i++)
    {
        sst<<"travel"<<endl;
        sst<<get<0>(m_viagens.at(i)) << endl <<  get<1>(m_viagens.at(i))<< endl<< get<2>(m_viagens.at(i))<< endl; 
    }
    }
    return sst.str();
}