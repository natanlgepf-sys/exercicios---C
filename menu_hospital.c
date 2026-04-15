#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PACIENTES 50
#define MAX_CONSULTAS 100

#define MAX_NOME        51
#define MAX_CONTACTO    16
#define MAX_DATA        11
#define MAX_HORA         6
#define MAX_TIPO        31
#define MAX_ESTADO      20

typedef struct {
    int id;
    char nome[MAX_NOME];
    int idade;
    char contacto[MAX_CONTACTO];
} Paciente;

typedef struct {
    int id;
    int idPaciente;
    char data[MAX_DATA];
    char hora[MAX_HORA];
    char tipo[MAX_TIPO];
    char estado[MAX_ESTADO];
} Consulta;

Paciente pacientes[MAX_PACIENTES];
Consulta consultas[MAX_CONSULTAS];
int totalPacientes = 0;
int totalConsultas = 0;

/* ── utilidades ──────────────────────────────────────────────────────────── */

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int lerLinha(char *buf, int limit, const char *campo) {
    while (1) {
        if (fgets(buf, limit, stdin) == NULL) {
            buf[0] = '\0';
            return 0;
        }
        int len = (int)strcspn(buf, "\n");
        buf[len] = '\0';
        if (len == limit - 1 && getchar() != '\n') {
            limparBuffer();
        }
        if (len == 0) {
            printf("  [!] O campo \"%s\" nao pode ficar em branco."
                   " Por favor escreva algo (max %d caracteres): ",
                   campo, limit - 1);
        } else {
            return len;
        }
    }
}

int dataValida(const char *d) {
    if (strlen(d) != 10) return 0;
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) {
            if (d[i] != '/') return 0;
        } else {
            if (!isdigit((unsigned char)d[i])) return 0;
        }
    }
    int dd = (d[0]-'0')*10 + (d[1]-'0');
    int mm = (d[3]-'0')*10 + (d[4]-'0');
    if (dd < 1 || dd > 31) return 0;
    if (mm < 1 || mm > 12) return 0;
    return 1;
}

int horaValida(const char *h) {
    if (strlen(h) != 5) return 0;
    if (!isdigit((unsigned char)h[0]) || !isdigit((unsigned char)h[1])) return 0;
    if (h[2] != ':') return 0;
    if (!isdigit((unsigned char)h[3]) || !isdigit((unsigned char)h[4])) return 0;
    int hh = (h[0]-'0')*10 + (h[1]-'0');
    int min = (h[3]-'0')*10 + (h[4]-'0');
    if (hh > 23 || min > 59) return 0;
    return 1;
}

void lerData(char *buf, const char *campo) {
    while (1) {
        printf("  (Formato: dd/mm/aaaa, max %d caracteres)\n"
               "  %s: ", MAX_DATA - 1, campo);
        lerLinha(buf, MAX_DATA, campo);
        if (dataValida(buf)) break;
        printf("  [!] Data invalida. Use o formato dd/mm/aaaa"
               " (ex: 12/02/2000).\n");
    }
}

void lerHora(char *buf, const char *campo) {
    while (1) {
        printf("  (Formato: hh:mm, max %d caracteres)\n"
               "  %s: ", MAX_HORA - 1, campo);
        lerLinha(buf, MAX_HORA, campo);
        if (horaValida(buf)) break;
        printf("  [!] Hora invalida. Use o formato hh:mm"
               " (ex: 14:00).\n");
    }
}

/* ── lógica principal ────────────────────────────────────────────────────── */

int encontrarPaciente(int id) {
    for (int i = 0; i < totalPacientes; i++) {
        if (pacientes[i].id == id) return i;
    }
    return -1;
}

void cadastrarPaciente(void) {
    if (totalPacientes >= MAX_PACIENTES) {
        printf("Limite de pacientes atingido!\n");
        return;
    }
    printf("\n--- CADASTRAR PACIENTE ---\n");
    pacientes[totalPacientes].id = totalPacientes + 1;
    printf("  (max %d caracteres)\n  Nome: ", MAX_NOME - 1);
    limparBuffer();
    lerLinha(pacientes[totalPacientes].nome, MAX_NOME, "Nome");
    while (1) {
        printf("  Idade: ");
        if (scanf("%d", &pacientes[totalPacientes].idade) == 1
            && pacientes[totalPacientes].idade > 0
            && pacientes[totalPacientes].idade <= 150) {
            limparBuffer();
            break;
        }
        printf("  [!] Idade invalida. Insira um numero entre 1 e 150.\n");
        limparBuffer();
    }
    printf("  (max %d caracteres)\n  Contacto: ", MAX_CONTACTO - 1);
    lerLinha(pacientes[totalPacientes].contacto, MAX_CONTACTO, "Contacto");
    totalPacientes++;
    printf("Paciente cadastrado com sucesso! ID: %d\n", totalPacientes);
}

void listarPacientes(void) {
    printf("\n--- LISTA DE PACIENTES ---\n");
    if (totalPacientes == 0) {
        printf("Nenhum paciente cadastrado.\n");
        return;
    }
    printf("%-5s %-25s %-8s %-15s\n", "ID", "Nome", "Idade", "Contacto");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < totalPacientes; i++) {
        printf("%-5d %-25d %-8d %-15s\n",
            pacientes[i].id,
            pacientes[i].nome,
            pacientes[i].idade,
            pacientes[i].contacto);
    }
    printf("--------------------------------------------------------------\n");
    printf("Total de pacientes: %d\n", totalPacientes);
}

void marcarConsulta(void) {
    if (totalConsultas >= MAX_CONSULTAS) {
        printf("Limite de consultas atingido!\n");
        return;
    }
    if (totalPacientes == 0) {
        printf("Nenhum paciente cadastrado.\n");
        return;
    }
    printf("\n--- MARCAR CONSULTA ---\n");
    listarPacientes();
    int idPac;
    printf("ID do paciente: ");
    scanf("%d", &idPac);
    limparBuffer();
    int idx = encontrarPaciente(idPac);
    if (idx == -1) {
        printf("Paciente nao encontrado.\n");
        return;
    }
    consultas[totalConsultas].id = totalConsultas + 1;
    consultas[totalConsultas].idPaciente = idPac;
    lerData(consultas[totalConsultas].data, "Data");
    lerHora(consultas[totalConsultas].hora, "Hora");
    printf("  (max %d caracteres)\n"
           "  Tipo (ex: Geral, Cardiologia...): ", MAX_TIPO - 1);
    lerLinha(consultas[totalConsultas].tipo, MAX_TIPO, "Tipo");
    strcpy(consultas[totalConsultas].estado, "Agendada");
    totalConsultas++;
    printf("Consulta marcada com sucesso! ID: %d\n", totalConsultas);
}

void listarConsultas(void) {
    printf("\n--- LISTA DE CONSULTAS ---\n");
    if (totalConsultas == 0) {
        printf("Nenhuma consulta marcada.\n");
        return;
    }
    printf("%-5s %-5s %-25s %-12s %-8s %-15s %-12s\n",
        "ID", "Pac", "Nome Paciente", "Data", "Hora", "Tipo", "Estado");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < totalConsultas; i++) {
        int pidx = encontrarPaciente(consultas[i].idPaciente);
        char nomePac[25];
        if (pidx != -1)
            strncpy(nomePac, pacientes[pidx].nome, 24);
        else
            strcpy(nomePac, "Desconhecido");
        nomePac[24] = '\0';
        printf("%-5d %-5d %-25s %-12s %-8s %-15s %-12s\n",
            consultas[i].id,
            consultas[i].idPaciente,
            nomePac,
            consultas[i].data,
            consultas[i].hora,
            consultas[i].tipo,
            consultas[i].estado);
    }
    printf("--------------------------------------------------------------------------------\n");
    printf("Total de consultas: %d\n", totalConsultas);
}

void verConsultasPaciente(void) {
    if (totalPacientes == 0) {
        printf("Nenhum paciente cadastrado.\n");
        return;
    }
    printf("\n--- VER CONSULTAS DE UM PACIENTE ---\n");
    listarPacientes();
    int idPac;
    printf("ID do paciente: ");
    scanf("%d", &idPac);
    int idx = encontrarPaciente(idPac);
    if (idx == -1) {
        printf("Paciente nao encontrado.\n");
        return;
    }
    printf("\nConsultas de %s:\n", pacientes[idx].nome);
    printf("%-5s %-12s %-8s %-15s %-12s\n", "ID", "Data", "Hora", "Tipo", "Estado");
    printf("--------------------------------------------------------------\n");
    int encontrou = 0;
    for (int i = 0; i < totalConsultas; i++) {
        if (consultas[i].idPaciente == idPac) {
            printf("%-5d %-12s %-8s %-15s %-12s\n",
                consultas[i].id,
                consultas[i].data,
                consultas[i].hora,
                consultas[i].tipo,
                consultas[i].estado);
            encontrou = 1;
        }
    }
    printf("--------------------------------------------------------------\n");
    if (!encontrou) printf("Nenhuma consulta encontrada para este paciente.\n");
}

void verProximaConsulta(void) {
    if (totalPacientes == 0) {
        printf("Nenhum paciente cadastrado.\n");
        return;
    }
    printf("\n--- PROXIMA CONSULTA DE UM PACIENTE ---\n");
    listarPacientes();
    int idPac;
    printf("ID do paciente: ");
    scanf("%d", &idPac);
    int idx = encontrarPaciente(idPac);
    if (idx == -1) {
        printf("Paciente nao encontrado.\n");
        return;
    }
    int proxima = -1;
    for (int i = 0; i < totalConsultas; i++) {
        if (consultas[i].idPaciente == idPac &&
            strcmp(consultas[i].estado, "Agendada") == 0) {
            proxima = i;
            break;
        }
    }
    if (proxima == -1) {
        printf("Nenhuma consulta agendada para %s.\n", pacientes[idx].nome);
    } else {
        printf("\nProxima consulta de %s:\n", pacientes[idx].nome);
        printf("%-5s %-12s %-8s %-15s %-12s\n", "ID", "Data", "Hora", "Tipo", "Estado");
        printf("--------------------------------------------------------------\n");
        printf("%-5d %-12s %-8s %-15s %-12s\n",
            consultas[proxima].id,
            consultas[proxima].data,
            consultas[proxima].hora,
            consultas[proxima].tipo,
            consultas[proxima].estado);
        printf("--------------------------------------------------------------\n");
    }
}

void alterarEstadoConsulta(void) {
    if (totalConsultas == 0) {
        printf("Nenhuma consulta marcada.\n");
        return;
    }
    printf("\n--- ALTERAR ESTADO DA CONSULTA ---\n");
    listarConsultas();
    int idCon;
    printf("ID da consulta (0 para cancelar): ");
    scanf("%d", &idCon);
    if (idCon == 0) {
        printf("Operacao cancelada.\n");
        return;
    }
    int idx = -1;
    for (int i = 0; i < totalConsultas; i++) {
        if (consultas[i].id == idCon) { idx = i; break; }
    }
    if (idx == -1) {
        printf("Consulta nao encontrada.\n");
        return;
    }
    printf("Estado atual: %s\n", consultas[idx].estado);
    printf("Escolha novo estado:\n");
    printf("  1. Agendada\n");
    printf("  2. Realizada\n");
    printf("  3. Cancelada\n");
    printf("Opcao: ");
    int op;
    scanf("%d", &op);
    switch (op) {
        case 1: strcpy(consultas[idx].estado, "Agendada");  break;
        case 2: strcpy(consultas[idx].estado, "Realizada"); break;
        case 3: strcpy(consultas[idx].estado, "Cancelada"); break;
        default: printf("Opcao invalida.\n"); return;
    }
    printf("Estado alterado para: %s\n", consultas[idx].estado);
}

void eliminarPaciente(void) {
    if (totalPacientes == 0) {
        printf("Nenhum paciente cadastrado.\n");
        return;
    }
    printf("\n--- ELIMINAR PACIENTE ---\n");
    listarPacientes();
    int idPac;
    printf("ID do paciente (0 para cancelar): ");
    scanf("%d", &idPac);
    if (idPac == 0) {
        printf("Operacao cancelada.\n");
        return;
    }
    int idx = encontrarPaciente(idPac);
    if (idx == -1) {
        printf("Paciente nao encontrado.\n");
        return;
    }
    for (int i = 0; i < totalConsultas; i++) {
        if (consultas[i].idPaciente == idPac) {
            printf("Nao e possivel eliminar: paciente tem consultas associadas.\n");
            return;
        }
    }
    for (int i = idx; i < totalPacientes - 1; i++) {
        pacientes[i] = pacientes[i + 1];
    }
    totalPacientes--;
    printf("Paciente eliminado com sucesso.\n");
}

void mostrarMenu(void) {
    printf("\n================================\n");
    printf("   SISTEMA HOSPITALAR           \n");
    printf("================================\n");
    printf("1. Cadastrar paciente\n");
    printf("2. Listar pacientes\n");
    printf("3. Marcar consulta\n");
    printf("4. Listar consultas\n");
    printf("5. Ver consultas de um paciente\n");
    printf("6. Ver proxima consulta de um paciente\n");
    printf("7. Alterar estado da consulta\n");
    printf("8. Eliminar paciente\n");
    printf("9. Sair\n");
    printf("================================\n");
    printf("Opcao: ");
}

int main(void) {
    int opcao;
    do {
        mostrarMenu();
        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            opcao = 0;
        }
        switch (opcao) {
            case 1: cadastrarPaciente();       break;
            case 2: listarPacientes();         break;
            case 3: marcarConsulta();          break;
            case 4: listarConsultas();         break;
            case 5: verConsultasPaciente();    break;
            case 6: verProximaConsulta();      break;
            case 7: alterarEstadoConsulta();   break;
            case 8: eliminarPaciente();        break;
            case 9: printf("A sair... Ate logo!\n"); break;
            default: printf("Opcao invalida! Escolha entre 1 e 9.\n");
        }
    } while (opcao != 9);
    return 0;
}