# Sistema de Gerenciamento de Hotel
 
# Este é um sistema de gerenciamento de hotel baseado em terminal, desenvolvido em C++. O programa foi projetado para gerenciar a ocupação de um edifício de 20 andares, contendo 14 apartamentos por andar (totalizando 280 quartos). O controle de status e a visualização gráfica do hotel são feitos em tempo real através de uma matriz interativa no console.


# Funcionalidades Principais
 
# O sistema simula o fluxo completo de um hóspede no hotel, desde a reserva até a saída, contando com as seguintes operações:
 
# * Mapa de Ocupação Visual:** Exibe na tela a situação atual de todos os 280 apartamentos do hotel.
#     * `.` : Quarto Vazio / Disponível
#     * `R` : Quarto Reservado
#     * `O` : Quarto Ocupado (Hóspede realizou Check-in)
# * Fazer Reserva:** Permite reservar um quarto disponível informando o andar, o apartamento e o CPF do hóspede.
# * Fazer Check-in:** Realiza a entrada do hóspede no hotel. Possui três fluxos inteligentes:
#     1. Com Reserva: Valida se o CPF digitado bate com o CPF de quem reservou antes de liberar o quarto e coletar os dados completos.
#     2. Com Reserva Inválida/Errada: Se o CPF não bater, o sistema sugere direcionar o cliente para um quarto vazio.
#     3. Sem Reserva (Balcão): Permite cadastrar o hóspede diretamente em qualquer quarto que esteja totalmente vago.
# * Fazer Check-out:** Libera o quarto de volta para o status "vazio" (`.`), exigindo a confirmação do CPF do hóspede por segurança.
# * Cancelar Reserva:** Remove o status de reservado (`R`) de um quarto, exigindo também a validação do CPF atrelado à reserva.


# Estrutura de Dados do Hóspede
 
# Quando um hóspede realiza o check-in, o sistema armazena uma ficha cadastral completa dentro de uma estrutura (`struct`) vinculada à coordenada exata do quarto:
 
# * Dados Pessoais:** Nome, CPF, Telefone e E-mail.
# * Endereço Residencial:** Logradouro, Municipio, Estado (UF) e CEP.


# Como Compilar e Rodar o Código

# Como o código utiliza comandos específicos do sistema operacional Windows (como `system("cls")` e `system("pause")`), o ambiente ideal para execução é o Windows.
 

# Pré-requisitos

# Você precisará de um compilador de C++ instalado (como o GCC/MinGW) ou de uma IDE (como Dev-C++, Code::Blocks ou VS Code com extensões de C++).

 
# Passo a Passo pelo Terminal:

# 1. Abra o terminal (Prompt de Comando ou PowerShell) na pasta onde o arquivo `HOTEL.cpp` está salvo.
# 2. Compile o código executando o comando:
#    ```bash
#    g++ HOTEL.cpp -o hotel.exe
#    ```
# 3. Execute o programa:
#    ```bash
#    hotel.exe
#    ```


# Notas de Desenvolvimento

# > Funcionalidade Futura (Modo Administrador): O menu já possui a opção `[5] Modo administrador` mapeada na interface, pronta para receber as implementações planejadas da ATV5 (Cálculo de taxa de ocupação, taxa de reservas e busca de informações de hóspedes por quarto).
