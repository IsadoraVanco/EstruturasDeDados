# Biblioteca de fila
from collections import deque
import Grafo

class Cidade:
    def __init__(self, nomePai=None):
        self.cor = "Branco"
        self.distancia = float('inf')
        self.pai = nomePai

def bfs(cidadeOrigem: str, cidadeDestino: str, mapa: dict):
    # Caminho até o destino
    caminho = []

    # Fila para os próximos a serem visitados
    fila = deque()

    # Dicionário para representar o grafo
    vertices = {}
    for cidade in mapa:
        vertices[cidade] = Cidade()

    # Inicializa a cidade de origem
    vertices[cidadeOrigem].cor = "Cinza"
    vertices[cidadeOrigem].distancia = 0
    vertices[cidadeOrigem].pai = None

    # Adiciona a cidade de origem na fila
    fila.append(cidadeOrigem)

    # Constrói os caminhos até o destino
    while fila:
        atual = fila.popleft()

        if atual == cidadeDestino:
            break

        for i in mapa[atual]:
            # Se é branco, não foi descoberto
            if vertices[i].cor == "Branco":
                vertices[i].cor = "Cinza"
                vertices[i].distancia = vertices[atual].distancia + 1
                vertices[i].pai = atual

                # Enfileira o nó adjacente
                fila.append(i)
            elif vertices[i].cor == "Cinza":
                if vertices[i].distancia > vertices[atual].distancia + 1:
                    vertices[i].distancia = vertices[atual].distancia + 1
                    vertices[i].pai = atual
                    fila.append(i)

        vertices[atual].cor = "Preto"

    # Reconstrói o caminho do destino à origem
    caminho = []
    atual = cidadeDestino
    while atual is not None:
        caminho.append(atual)
        atual = vertices[atual].pai

    # Inverter o caminho para obter da origem ao destino
    caminho.reverse()

    # print("Caminho encontrado:")
    # for cidade in caminho:
    #     print(cidade, end=" ")
    # print()

    return caminho

if __name__ == "__main__":

    mapa = {
        "Maringá": ["Santa Fé", "Marialva", "Astorga"],
        "Marialva": ["Maringá", "Mandaguari"],
        "Santa Fé": ["Jaguapitã", "Maringá", "Astorga"],
        "Mandaguari": ["Jandaia do Sul", "Arapongas", "Marialva"],
        "Jandaia do Sul":["Mandaguari", "Arapongas", "Guaravera", "Londrina"],
        "Guaravera": ["Jandaia do Sul", "Londrina", "Arapongas"],
        "Arapongas" : ["Cambé", "Astorga", "Jaguapitã", "Mandaguari", "Jandaia do Sul", "Guaravera", "Londrina"],
        "Londrina" : ["Guaravera", "Jandaia do Sul", "Arapongas", "Cambé", "Ibiporã", 
        "Bela Vista do Paraíso", "Sertanópolis"],
        "Cambé" : ["Londrina", "Arapongas", "Jaguapitã", "Sertanópolis",
        "Bela Vista do Paraíso", "Astorga",],
        "Astorga" : ["Santa Fé", "Jaguapitã", "Maringá", "Arapongas", "Cambé"],
        "Santa Fé": ["Maringá", "Astorga", "Jaguapitã"],
        "Jaguapitã" : ["Santa Fé", "Astorga", "Cambé", "Arapongas"],
        "Ibiporã" : ["Londrina", "Sertanópolis", "Uraí", "Cornélio Procópio", "Assaí", "São Sebastião da Amoreira"],
        "Sertanópolis" : ["Bela Vista do Paraíso", "Cambé", "Londrina", "Ibiporã"],
        "Bela Vista do Paraíso" : ["Sertanópolis", "Londrina", "Cambé"],
        "Uraí" : ["Ibiporã", "Cornélio Procópio", "Assaí", "São Sebastião da Amoreira"], 
        "Cornélio Procópio" : ["Ibiporã", "Uraí", "Assaí", "São Sebastião da Amoreira"],
        "Assaí" : ["Ibiporã", "Uraí", "Cornélio Procópio", "São Sebastião da Amoreira"],
        "São Sebastião da Amoreira" : ["Nova Santa Bárbara", "Assaí", "Uraí", "Cornélio Procópio", "Ibiporã"],
        "Nova Santa Bárbara" : ["São Sebastião da Amoreira"]
    }

    print("Partindo de Maringá, qual o caminho sugerido para chegar em Uraí?")
    bfs("Maringá", "Uraí", mapa)

    print("Partindo de Guaravera, qual o caminho sugerido para chegar em Santa Fé?")
    bfs("Guaravera", "Santa Fé", mapa)

    print("Partindo de Astorga, qual o caminho sugerido para Jandaia do Sul?")
    bfs("Astorga", "Jandaia do Sul", mapa)