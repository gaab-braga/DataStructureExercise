void trocar_consecutivo(Lista* lista, int num) {
// se tiver no inicio
    if (lista->inicio->valor == num) {
        // criando um vetor auxiliar para eu não perder a referência 
        No* aux = lista->inicio; // criando um vetor auxiliar
        lista->inicio = lista->inicio->prox; // o início aponta para o próximo
        aux->prox = lista->inicio->prox; // o vetor auxiliar aponta para o próximo do início
        lista->inicio->prox = aux; // o início aponta para o vetor auxiliar
    }
//se tiver no fim
    if (lista->fim->valor == num) {
        // criando um vetor auxiliar para eu não perder a referência de troca
        No* aux = lista->inicio;
        // percorrendo a lista até o penultimo elemento
        while (aux->prox != lista->fim)
            aux = aux->prox; // avançando na lista
        aux->prox = lista->fim->prox; // o penultimo elemento aponta para o próximo do último
        lista->fim->prox = lista->inicio;  // o último elemento aponta para o início
        lista->inicio = lista->fim; // o início aponta para o último
        lista->fim = aux; // o último elemento é o penultimo
    }

//se tiver em posição genérica
    else {
        // criando o vetor auxiliar para percorrer a lista
        No* aux = lista->inicio;
        // percorrer a lista até o elemento anterior ao que eu quero trocar
        while (aux->prox->valor != num)
            aux = aux->prox; // avançando na lista
        // trocando o elemento escolhido pelo proximo dele
        No* trocar = aux->prox; // criando um vetor para trocar
        aux->prox = trocar->prox; // o anterior aponta para o próximo
        troca->prox = aux->prox->prox; // o vetor de troca aponta para o próximo do próximo
        aux->prox->prox = troca; // o próximo do anterior aponta para o vetor de troca
        }
}
