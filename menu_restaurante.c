#include <stdio.h>
#include <string.h>

#define MAX_RESTAURANTES 50
#define LIMITE_NOME 30
#define LIMITE_CATEGORIA 20

typedef struct {
    char nome[LIMITE_NOME];
    char categoria[LIMITE_CATEGORIA];
    int estado;
} Restaurante;

Restaurante restaurantes[MAX_RESTAURANTES];
int total = 0;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int lerInteiro() {
    char linha[10];
    int valor = -1;
    if (fgets(linha, sizeof(linha), stdin)) {
        if (strchr(linha, '\n') == NULL) {
            limparBuffer();
        }
        sscanf(linha, "%d", &valor);
    }
    return valor;
}

void cadastrarRestaurante() {
    if (total >= MAX_RESTAURANTES) {
        printf("Limite de restaurantes atingido!\n");
        return;
    }

    printf("\n--- CADASTRAR RESTAURANTE ---\n");

    do {
        printf("Nome (max %d): ", LIMITE_NOME - 1);
        fgets(restaurantes[total].nome, LIMITE_NOME, stdin);
        if (strchr(restaurantes[total].nome, '\n') == NULL) limparBuffer();
        restaurantes[total].nome[strcspn(restaurantes[total].nome, "\n")] = 0;
        if (strlen(restaurantes[total].nome) == 0) printf("Erro: O nome nao pode estar vazio.\n");
    } while (strlen(restaurantes[total].nome) == 0);

    do {
        printf("Categoria (max %d): ", LIMITE_CATEGORIA - 1);
        fgets(restaurantes[total].categoria, LIMITE_CATEGORIA, stdin);
        if (strchr(restaurantes[total].categoria, '\n') == NULL) limparBuffer();
        restaurantes[total].categoria[strcspn(restaurantes[total].categoria, "\n")] = 0;
        if (strlen(restaurantes[total].categoria) == 0) printf("Erro: A categoria nao pode estar vazia.\n");
    } while (strlen(restaurantes[total].categoria) == 0);

    restaurantes[total].estado = 0;
    total++;

    printf("Restaurante cadastrado com sucesso!\n");
}

void listarRestaurantes() {
    printf("\n--- LISTA DE RESTAURANTES ---\n");
    if (total == 0) {
        printf("Nenhum restaurante cadastrado.\n");
        return;
    }
    printf("%-5s %-25s %-20s %-10s\n", "Num", "Nome", "Categoria", "Estado");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        printf("%-5d %-25s %-20s %-10s\n",
            i + 1,
            restaurantes[i].nome,
            restaurantes[i].categoria,
            restaurantes[i].estado ? "Ativo" : "Inativo");
    }
    printf("--------------------------------------------------------------\n");
}

void ativarDesativar() {
    printf("\n--- ATIVAR / DESATIVAR RESTAURANTE ---\n");
    if (total == 0) {
        printf("Nenhum restaurante cadastrado.\n");
        return;
    }
    listarRestaurantes();
    printf("Escolha o numero (0 para cancelar): ");
    int escolha = lerInteiro();
    if (escolha == 0) return;
    if (escolha < 1 || escolha > total) {
        printf("Numero invalido.\n");
        return;
    }
    int i = escolha - 1;
    restaurantes[i].estado = !restaurantes[i].estado;
    printf("Restaurante \"%s\" agora esta: %s\n",
        restaurantes[i].nome,
        restaurantes[i].estado ? "Ativo" : "Inativo");
}

void pesquisarRestaurante() {
    printf("\n--- PESQUISAR RESTAURANTE ---\n");
    if (total == 0) {
        printf("Nenhum restaurante cadastrado.\n");
        return;
    }
    char nomePesquisa[LIMITE_NOME];
    
    do {
        printf("Nome a pesquisar: ");
        fgets(nomePesquisa, LIMITE_NOME, stdin);
        if (strchr(nomePesquisa, '\n') == NULL) limparBuffer();
        nomePesquisa[strcspn(nomePesquisa, "\n")] = 0;
    } while (strlen(nomePesquisa) == 0);

    int encontrou = 0;
    for (int i = 0; i < total; i++) {
        if (strcmp(restaurantes[i].nome, nomePesquisa) == 0) {
            printf("\n%-25s %-20s %-10s\n", "Nome", "Categoria", "Estado");
            printf("%-25s %-20s %-10s\n",
                restaurantes[i].nome,
                restaurantes[i].categoria,
                restaurantes[i].estado ? "Ativo" : "Inativo");
            encontrou = 1;
            break;
        }
    }
    if (!encontrou) printf("Restaurante nao encontrado.\n");
}

void mostrarAtivos() {
    printf("\n--- RESTAURANTES ATIVOS ---\n");
    int encontrou = 0;
    for (int i = 0; i < total; i++) {
        if (restaurantes[i].estado) {
            printf("%-5d %-25s %-20s\n", i + 1, restaurantes[i].nome, restaurantes[i].categoria);
            encontrou = 1;
        }
    }
    if (!encontrou) printf("Nenhum restaurante ativo.\n");
}

void mostrarMenu() {
    printf("\n=============================\n");
    printf("   SISTEMA DE RESTAURANTES   \n");
    printf("=============================\n");
    printf("1. Cadastrar restaurante\n");
    printf("2. Listar restaurantes\n");
    printf("3. Ativar/Desativar restaurante\n");
    printf("4. Pesquisar restaurante pelo nome\n");
    printf("5. Mostrar apenas restaurantes ativos\n");
    printf("6. Sair\n");
    printf("=============================\n");
    printf("Opcao: ");
}

int main() {
    int opcao;
    do {
        mostrarMenu();
        opcao = lerInteiro();
        switch (opcao) {
            case 1: cadastrarRestaurante(); break;
            case 2: listarRestaurantes(); break;
            case 3: ativarDesativar(); break;
            case 4: pesquisarRestaurante(); break;
            case 5: mostrarAtivos(); break;
            case 6: printf("A sair...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 6);
    return 0;
}