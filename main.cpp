#include "vehicle.hpp"

int main()
{
    vector<Vehicle*>todos;
    string placa;
    string descricao;
    float quilometragem_atual;

    ifstream arquivo("save.txt");
    if(!arquivo)
    {
        cout << endl << "Nao ha arquivos anteriores......" << endl << endl;
    }

    else{
        cout <<endl << "Abrindo arquivo......." << endl;
        string linha;
        string tipo;
        string placa, descricao, tipo_de_transporte, tipo_carga, cidade;
        int qtd_eixos=0;
        float quilometragem_atual=0, TabelaFipe=0, distancia=0, combustivel_gasto=0;

        while(getline(arquivo, linha))
        {
           
            istringstream iss(linha);
            iss>>tipo;
            if(tipo=="car")
            {
                getline(arquivo, placa);
                getline(arquivo, descricao);
                arquivo>>quilometragem_atual>>TabelaFipe;
                arquivo.ignore();
                todos.push_back(new Car(placa, descricao, quilometragem_atual, TabelaFipe));
            }
            else if(tipo=="bus"){
                getline(arquivo, placa);
                getline(arquivo, descricao);
                arquivo>>quilometragem_atual>>tipo_de_transporte;
                arquivo.ignore();
                todos.push_back(new Bus(placa, descricao, quilometragem_atual, tipo_de_transporte));
            }
            else if(tipo=="LightTruck"){
                getline(arquivo, placa);
                getline(arquivo, descricao);
                getline(arquivo, tipo_carga);
                arquivo>>quilometragem_atual;
                arquivo.ignore();
                todos.push_back(new LightTruck(placa, descricao, quilometragem_atual, tipo_carga));
            }
            else if(tipo=="HeavyTruck"){
                getline(arquivo, placa);
                getline(arquivo, descricao);
                arquivo>>quilometragem_atual>>qtd_eixos;
                arquivo.ignore();
                todos.push_back(new HeavyTruck(placa, descricao, quilometragem_atual, qtd_eixos));
            }
            else if(tipo=="travel"){
                getline(arquivo, cidade);
                arquivo>>distancia>>combustivel_gasto;
                arquivo.ignore();
                todos.back()->adicionar_viagem(cidade, distancia, combustivel_gasto);
            }
        }
        cout<<"Arquivo aberto com sucesso!!" << endl;
    }

    for(;;)
    {
        cout <<endl << "UFSC VEHICLE MANAGER SYSTEM (UVMS)" << endl;
        cout << "-----------------------------------" << endl;
        cout << "1. Cadastrar novo veiculo" << endl;
        cout << "2. Cadastrar viagem para um veiculo" << endl;
        cout << "3. Mostrar relatorios (geral)" << endl;
        cout << "4. Pesquisar veiculo" << endl;
        cout << "0. Quit" << endl;
        int selecionavel;
        int selecionavel2;
        cin >> selecionavel;

        if(selecionavel==1)
        {
            cout << "----------------------" << endl;
            cout << "1. Para cadastrar um carro" << endl;
            cout << "2. Para cadastrar um onibus" << endl;
            cout << "3. Para selecionar um caminhao leve" << endl;
            cout << "4. Para adicionar um caminhao pesado" << endl;
            cin >> selecionavel2;

            if(selecionavel2==1)
            {
                cout << endl << "Placa do veiculo: ";
                cin.ignore();
                cin >> placa;
                cout << "Descricao do veiculo: ";
                cin.ignore();
                getline(cin, descricao);
                cout << "Quilometragem atual: ";
                cin >> quilometragem_atual;
                cout << "Valor da tabela fipe: ";
                float valortTabFipe;
                cin >> valortTabFipe;

                todos.push_back(new Car(placa, descricao, quilometragem_atual, valortTabFipe));
                cout << "Carro adicionado com sucesso!" << endl;
            }

            if(selecionavel2==2)
            {
                cout << endl << "Placa do veiculo: ";
                cin.ignore();
                cin >> placa;
                cout << "Informacoes do veiculo: ";
                cin.ignore();
                getline(cin, descricao);
                cout << "Quilometragem atual: ";
                cin >> quilometragem_atual;
                cout << "Tipo de transporte: ";
                string tipo_de_transporte;
                cin.ignore();
                getline(cin, tipo_de_transporte);

                todos.push_back(new Bus(placa, descricao, quilometragem_atual, tipo_de_transporte));
                cout << "Onibus adicionado com sucesso!" << endl;
            }

            if(selecionavel2==3)
            {
                cout << endl << "Placa do veiculo: ";
                cin.ignore();
                cin >> placa;
                cout << "Informacoes do veiculo: ";
                cin.ignore();
                getline(cin, descricao);
                cout << "Quilometragem atual: ";
                cin >> quilometragem_atual;
                cout << "Tipo de carga transportada: ";
                string tipo_de_carga_tarnsportada;
                cin.ignore();
                getline(cin, tipo_de_carga_tarnsportada);

                todos.push_back(new LightTruck(placa, descricao, quilometragem_atual, tipo_de_carga_tarnsportada));
                cout << "Caminhao leve adicionado com sucesso!" << endl;
            }

            if(selecionavel2==4)
            {
                cout << endl << "Placa do veiculo: ";
                cin.ignore();
                cin >> placa;
                cout << "Informacoes do veiculo: ";
                cin.ignore();
                getline(cin, descricao);
                cout << "Quilometragem atual: ";
                cin >> quilometragem_atual;
                cout << "Quantidade de eixos: ";
                int qtd_eixos;
                cin >> qtd_eixos;

                todos.push_back(new HeavyTruck(placa, descricao, quilometragem_atual, qtd_eixos));
                cout << "Caminhao pesado adicionado com sucesso!" << endl;
            }
        }

        if(selecionavel==2)
        {
            cout<< endl << "Placa do veiculo adicionado: ";
            cin.ignore();
            cin >> placa;

            for(size_t i=0; i<todos.size(); i++)
            {
                if(placa==todos.at(i)->return_placa())
                {
                    cout << "Insira a cidade destino da viagem: ";
                    string cidade;
                    cin.ignore();
                    getline(cin, cidade);
                    cout << "Insira a distancia da viagem: ";
                    float distancia;
                    cin >> distancia;
                    cout << "Insira a quantidade de combustivel gasto: ";
                    float combustivel_gasto;
                    cin >> combustivel_gasto;

                    todos.at(i)->adicionar_viagem(cidade, distancia, combustivel_gasto);
                    cout << endl << "Viagem salva com sucesso!" << endl;
                }
            }
        }

        if(selecionavel==3)
        {
            cout << "Placa" << "        " << "Descricao" <<"        " <<"Odometro Inicial (km) " <<"        " <<"Km Atual (km)" <<"        "<<"Consumo Medio (km/l)"<<"        "<<"Informacao especifica do veiculo"<<endl;
            for(size_t i=0; i<todos.size(); i++)
            {
                cout << todos.at(i)->Tostring() << endl;
            }
        }

        if(selecionavel==4)
        {
            cout<< endl << "Placa do veiculo a ser pesquisado: ";
            cin.ignore();
            cin >> placa;
            cout << "Placa" << "        " << "Descricao" <<"        " <<"Odometro Inicial (km) " <<"        " <<"Km Atual (km)" <<"        "<<"Consumo Medio (km/l)"<<"        "<<"Informacao especifica do veiculo"<<endl;
            for(size_t i=0; i<todos.size(); i++)
            {
                if(placa==todos.at(i)->return_placa())
                {
                    cout << todos.at(i)->Tostring();
                    cout <<endl <<endl << "cidade" <<"      "<<"distancia" << endl;
                    cout << todos.at(i)->ToString_Viagem();
                }
            }
        }

        if(selecionavel==0)
        {
            ofstream arquivo("save.txt");

            for(size_t i=0; i<todos.size(); i++)
            {
                arquivo << todos.at(i)->salvar();
                arquivo << todos.at(i)->salvar_viagem();
            }
            arquivo.close();
            break;
        }
    }
    for(size_t i=0; i<todos.size(); i++)
    {
        delete todos.at(i);
    }

    return 0; 
}