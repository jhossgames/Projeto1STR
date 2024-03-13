# Controle de Cruzamento Ferroviário

Este programa simula o comportamento de um cruzamento ferroviário controlado por semáforos para garantir a passagem segura dos trens. Os trens podem se aproximar do cruzamento pelas vias A1 ou B1 e seguir para as vias A2 ou B2. 

## Funcionalidades

- **Modelagem dos Trens:** Cada trem é representado por uma thread e pode ter uma das três prioridades: alta(3), média(2) ou baixa(1).
- **Controle de Acesso:** O acesso ao cruzamento é controlado por semáforos. Apenas um trem pode passar pelo cruzamento por vez.
- **Priorização:** Trens com prioridade mais alta têm preferência para cruzar o cruzamento.
- **Interface de Usuário:** O programa exibe mensagens indicando o estado atual dos trens e a situação do cruzamento.

## Como Usar

1. Compile o programa utilizando um compilador C.
2. Execute o programa.
3. Observe a saída para acompanhar o comportamento dos trens e do cruzamento.

## Requisitos

- Compilador C
- Sistema operacional Linux

## Exemplo de Saída

Trem 1 (Prioridade 2) está se aproximando do cruzamento vindo de A1 e indo para A2.
Trem 2 (Prioridade 1) está se aproximando do cruzamento vindo de B1 e indo para B2.
Trem 1 está cruzando o cruzamento.
Trem 1 cruzou o cruzamento.
Trem 2 está cruzando o cruzamento.
Trem 2 cruzou o cruzamento.

## Contribuindo

Contribuições são bem-vindas! Sinta-se à vontade para abrir uma issue ou enviar um pull request.

## Licença

Este projeto está licenciado sob a [MIT License](https://opensource.org/licenses/MIT).
