#include <stdio.h>
#include <locale.h>

#define TOTAL 100

struct Roupa {
	int id;
	char nome[40];
	char tipo[20];
	char cor[20];
	char tamanho[5];
	char estação[15];
	int guardada;
};

struct Roupa roupas[TOTAL];
int total=0;
int proximoId=1;


int buscar(int id) {
	for (int i=0; i<total; i++) {
		if (roupas[i].id==id) {
			return i;
		}
	}
	return -1;
}

void criar() {
	if (total>=TOTAL) {
		printf("Guarda-roupa cheio!\n");
		return;
	}
	struct Roupa r;
	r.id=proximoId;
	proximoId++;

	//aq mostra oq preencher e define a quantidade de caracteres
	printf("Nome: ");
	scanf(" %39[^\n]", r.nome);
	printf("Tipo: ");
	scanf(" %19[^\n]", r.tipo);
	printf("Cor: ");
	scanf(" %19[^\n]", r.cor);
	printf("Tamanho: ");
	scanf(" %4[^\n]", r.tamanho);
	printf("Estação: ");
	scanf("%s", r.estação);

	roupas[total]=r;
	total++;
	printf("Peça adicionada!\n");
}
//os "%"" são pra definir largura da coluna e não ficar tudo colado
void listar() {
	if (total==0) {
		printf("Guarda-roupa vazio.\n");
		return;
	}
	printf("\n%-4s %-25s %-12s %-10s %-15s %s\n", "ID", "Nome", "Tipo", "Cor", "Estação", "Tam");
	for (int i=0; i<total; i++) {
		printf("%-4d %-25s %-12s %-10s %-15s %s\n", roupas[i].id, roupas[i].nome,
		       roupas[i].tipo, roupas[i].cor, roupas[i].estação, roupas[i].tamanho);

	}
}

void editar() {
	int id;
	listar();
	printf("ID da peça para editar: ");
	scanf("%d", &id);

	int i=buscar(id);
	if (i<0) {
		printf("ID não encontrado.\n");
		return;
	}

	int campo;
	printf("O que quer editar?\n");
	printf("1)Nome\n 2)Tipo\n 3)Cor\n 4)Estação\n 5)Tamanho\n");
	printf("Escolha: ");
	scanf("%d", &campo);

	switch (campo) {

	case 1:

		printf("Novo nome: ");
		scanf(" %39[^\n]", roupas[i].nome);
		break;

	case 2:
		printf("Novo tipo: ");
		scanf(" %19[^\n]", roupas[i].tipo);
		break;

	case 3:
		printf("Nova cor: ");
		scanf(" %19[^\n]", roupas[i].cor);
		break;
	case 4:
		printf("Outra estação: ");
		scanf(" %14[^\n]", roupas[i].estação);
		break;
	case 5:
		printf("Novo tamanho: ");
		scanf("%s", roupas[i].tamanho);
		break;
		printf("Peça atualizada!\n");
	}
}

void deletar() {
	int id;
	listar();
	printf("ID da peça para apagar: ");
	scanf("%d", &id);

	int i =buscar(id);
	if (i<0) {
		printf("ID não encontrado.\n");
		return;
	}


	for (; i<total- 1; i++) {
		roupas[i]=roupas[i+ 1];
	}
	total--;
	printf("Peça apagada!\n");
}

int main() {
	setlocale(LC_ALL, "portuguese");
	int op;
	do {
		printf("\n=== GUARDA-ROUPA DIGITAL ===\n");
		printf("1) Adicionar\n2) Listar\n3) Editar\n4) Apagar\n0) Sair\n");
		printf("Escolha uma das opções: ");
		scanf("%d", &op);

		switch (op) {
		case 1:
			criar();
			break;
		case 2:
			listar();
			break;
		case 3:
			editar();
			break;
		case 4:
			deletar();
			break;
		}
	} while (op!= 0);
	return 0;
}
