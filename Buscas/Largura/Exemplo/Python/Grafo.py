class Grafo:

    # Construtor do grafo
    def __init__(self, dicionarioGrafo=None):
        # Cria um dicionário vazio para guardar o grafo
        if dicionarioGrafo is None:
            dicionarioGrafo = {}

        self.arestas = dicionarioGrafo
    
    # Retorna os vértices do grafo
    def getVertices(self):
        return list(self.arestas.keys())

    # Retorna as arestas do grafo
    def getArestas(self):
        # Cria uma lista vazia
        listaArestas = []
        # Percorre o grafo procurando as arestas
        for v1 in self.arestas:
            for v2 in self.arestas[v1]:
                if {v2, v1} in listaArestas:
                    listaArestas.append({v1, v2})
        
        return listaArestas
    
    # Retorna o número de vértices
    def getNumeroVertices(self):
        return self.arestas.keys().__len__
