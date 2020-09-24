## Motivações:
    Como a má gerencia de recursos na AWS pode gerar custos abrsurdos advindos da cobrança em dolar dos recursos neste trabalho será utilizado da gestão de usários do IAM (Identity and Access Management) para limitar o que o usuário disponibilizado poderá executar na conta da AWS
    Neste Caso, apenas leitura para a correta avaliação

    Buscando evitar o impacto dá má gerencia também será utilizado um template cloudformation para provisionamento de toda infraestrutura facilitando o provisionamento e desprovisonamento da mesma

## Dos Requisitos para correta execução:
    Umas grande vantagem da infraestrutura como codigo é facilitar a replicação de um ambinete todo
    Este repositório disponibiliza um template cloudformation completo para criação do ambiente necessário, mas para utiliza-lo faz-se necessário a instalação do AWS CLI (console line interface) e sua devida configuração
    A utilização com DOKER é a recomendada, visto que assim podemos abstrair alguns pontos como SO
    

## Para login ao console:<br>
    Vá até (https://console.aws.amazon.com/console/home)
        - Clique em "Fazer login no console"
        - Escolha a opção "Usuário IAM"
        - para o "ID da conta" utilize: 337687898324
        - para o "Usuario" utilize: trabalho_tt304
        -  para a "Senha" utilize:

## Deploy da Stack:
    com Docker:
        docker run --rm -it -v ~/.aws:/root/.aws  -v ~/git/tt304_unicamp:/root/tt_304_unicamp amazon/aws-cli cloudformation create-stack --stack-name tt_304_unicamp --template-body file:///root/tt_304_unicamp/infraestrutura/cloudformation.yaml
## Destruiçao da stack:
    com docker
        docker run --rm -it -v ~/.aws:/root/.aws  -v ~/git/tt304_unicamp:/root/tt_304_unicamp amazon/aws-cli cloudformation delete-stack --stack-name tt_304_unicamp


### Links Uteis:
    Docker:
    Console AWS:
    Documentação AWS: https://docs.aws.amazon.com/index.html
        Documentação Identity and Access Management (IAM): https://docs.aws.amazon.com/pt_br/IAM/latest/UserGuide/introduction.html 
        Documentação CloudFormation: https://docs.aws.amazon.com/pt_br/cloudformation/?id=docs_gateway
        Documentação AWS CLI:
            Como instalar: https://docs.aws.amazon.com/cli/latest/userguide/install-cliv2.html
