# 🏨 Hotel — Sistema de Gerenciamento

Repositório dedicado ao desenvolvimento de um sistema de gerenciamento hoteleiro em C++ para terminal, projetado para administrar a ocupação e o controle de reservas de um hotel estruturado com 20 andares e 14 apartamentos por andar.

---

## 📌 Visão Geral

- 🏢 **Estrutura:** Mapeamento em matriz para 280 apartamentos (20 andares x 14 quartos).
- ⌨️ **Interação:** Sistema interativo via linha de comando (CLI).
- 🛡️ **Estabilidade:** Tratamento rigoroso de buffer para validação de dados de entrada.
- 👥 **Autores:** Victoria Spina Tavares, Hellen Araujo da Silva e Samira Soares Carvalho

---

## 🛠️ Tecnologias e Ferramentas

- **C++**
- **GCC / G++** (Compilação)
- **Git & GitHub** (Versionamento e controle de versões)

---

## 📁 Estrutura do Repositório

```text
├── HOTEL.cpp                   # main(): Ponto de entrada, fluxos de menus e lógica do sistema
└── README.md                   # Documentação do projeto
```

## 🚀 Como Compilar e Executar
Certifique-se de ter um compilador C++ instalado no sistema (ex.: g++).

Clone o repositório:

```bash
git clone https://github.com/victoriatvrs/Hotel.git
cd Hotel
```

Compile o arquivo principal do projeto:
```bash
g++ HOTEL.cpp -o hotel
```

Execute o sistema:
- No Linux / macOS:
```bash
./hotel
```

- No Windows:
```bash
hotel.exe
