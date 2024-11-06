import heapq
import random
import time

class Paciente:
    def __init__(self, idade, id_paciente):
        self.idade = idade
        self.id_paciente = id_paciente

    def __lt__(self, other):
        return self.idade > other.idade  # Pacientes mais velhos têm prioridade

# Função para simulação de inserções e remoções em fila com prioridade
def simular_fila_prioridade(num_insercoes, num_remocoes):
    fila_prioridade = []
    heapq.heapify(fila_prioridade)
    
    # Simulação de inserção com prioridade (por idade)
    insercao_inicial = time.time()
    for i in range(num_insercoes):
        idade = random.randint(20, 90)  # Idade aleatória entre 20 e 90
        paciente = Paciente(idade, i)
        heapq.heappush(fila_prioridade, paciente)
    insercao_final = time.time()
    
    # Simulação de remoção com prioridade
    remocao_inicial = time.time()
    for _ in range(num_remocoes):
        if fila_prioridade:
            heapq.heappop(fila_prioridade)
    remocao_final = time.time()
    
    # Resultados de tempo
    tempo_insercao = insercao_final - insercao_inicial
    tempo_remocao = remocao_final - remocao_inicial
    print(f"Tempo médio de inserção na Fila com Prioridade: {tempo_insercao / num_insercoes:.10f} segundos")
    print(f"Tempo médio de remoção na Fila com Prioridade: {tempo_remocao / num_remocoes:.10f} segundos")

# Simulação de fila sem prioridade (lista encadeada simulada)
def simular_lista(num_insercoes, num_remocoes):
    lista = []
    
    # Simulação de inserção em lista simples
    insercao_inicial = time.time()
    for i in range(num_insercoes):
        idade = random.randint(20, 90)
        lista.append((idade, i))  # Inserção no final
    insercao_final = time.time()
    
    # Simulação de remoção (remoção no início da lista)
    remocao_inicial = time.time()
    for _ in range(num_remocoes):
        if lista:
            lista.pop(0)
    remocao_final = time.time()
    
    # Resultados de tempo
    tempo_insercao = insercao_final - insercao_inicial
    tempo_remocao = remocao_final - remocao_inicial
    print(f"Tempo médio de inserção na Lista: {tempo_insercao / num_insercoes:.10f} segundos")
    print(f"Tempo médio de remoção na Lista: {tempo_remocao / num_remocoes:.10f} segundos")

# Configurações da simulação
NUM_INSERCOES = 1000
NUM_REMOCOES = 400

print("Simulação na Fila com Prioridade:")
simular_fila_prioridade(NUM_INSERCOES, NUM_REMOCOES)

print("\nSimulação na Lista:")
simular_lista(NUM_INSERCOES, NUM_REMOCOES)
