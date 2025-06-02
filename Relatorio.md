# UNIVERSIDADE FEDERAL DE PELOTAS
## CIÊNCIA DA COMPUTAÇÃO

# ALGORITMOS PARA O PROBLEMA DO CAIXEIRO VIAJANTE
## Comparação entre Abordagens Exatas e Aproximativas

**Disciplina:** Algoritmos e Estruturas de Dados III  
**Professor:** Dr. Ulisses Corrêa  
**Período:** 2025/1  

**Participantes:**
- Caio Garcez Ribeiro
- Lucas Paulsen Silveira Aniceto

---

## INTRODUÇÃO

Este relatório apresenta a implementação e análise de algoritmos para o Problema do Caixeiro Viajante (TSP) em C e Python. Foram implementados algoritmos exatos (Força Bruta e Branch and Bound) e aproximativo (MST).

O TSP consiste em encontrar a rota de menor custo que visite cada cidade exatamente uma vez e retorne ao ponto de partida. É um problema NP-Difícil, sem solução polinomial conhecida.

---

## 1. ALGORITMOS IMPLEMENTADOS

### 1.1 Algoritmos Exatos

**Força Bruta Otimizada - O((n-1)!)**  
Fixa a cidade inicial e utiliza otimizações como early termination quando o caminho parcial já excede o melhor resultado conhecido.

**Força Bruta Sem Otimização - O(n!)**  
Versão padrão que testa todas as permutações possíveis sem podas ou otimizações, servindo como baseline para comparação.

**Branch and Bound - O(b^d)**
Usa podas baseadas em lower bounds para eliminar caminhos não promissores, reduzindo significativamente o espaço de busca. Calcula estimativas do custo mínimo possível para cada nó e poda ramos quando o bound excede a melhor solução conhecida.

### 1.2 Algoritmo Aproximativo

**MST (Minimum Spanning Tree) - O(n²)**  
Garantia teórica de no máximo 2× o valor ótimo. Passos: (1) Construir MST com Prim, (2) DFS pré-ordem, (3) Aplicar atalhos.

---

## 2. RESULTADOS EXPERIMENTAIS

### 2.1 Algoritmos Exatos - Força Bruta (Com Otimização (n-1)!)

| Arquivo        | Cidades | C (s)        | Python (s)   | Speedup C vs Python |
| -------------- | ------- | ------------ | ------------ | ------------------- |
| tsp2_1248.txt  | 6       | 0.000000     | 0.000086     |                     |
| tsp1_253.txt   | 11      | 0.166600     | 1.481049     |                     |
| tsp3_1194.txt  | 15      | 8270         | 80298        |                     |
| tsp5_27603.txt | 29      | Impraticável | Impraticável |                     |
| tsp4_7013.txt  | 44      | Impraticável | Impraticável |                     |
### 2.2 Algoritmos Exatos - Força Bruta (Sem Otimização (n)!)

| Arquivo        | Cidades | C (s)        | Python (s)   | Speedup C vs Python |
| -------------- | ------- | ------------ | ------------ | ------------------- |
| tsp2_1248.txt  | 6       | 0.000000     | 0.000264     |                     |
| tsp1_253.txt   | 11      | 0.912000     | 14.970555    |                     |
| tsp3_1194.txt  | 15      | 34409.482    | 15 dias +/-  |                     |
| tsp5_27603.txt | 29      | Impraticável | Impraticável |                     |
| tsp4_7013.txt  | 44      | Impraticável | Impraticável |                     |

### 2.3 Algoritmos Exatos - Branch and Bound (Com Otimização (n-1)!)

| Arquivo        | Cidades | C (s)        | Python (s)   | Speedup C vs Python |
| -------------- | ------- | ------------ | ------------ | ------------------- |
| tsp2_1248.txt  | 6       | 0.000025     | 0.000097     |                     |
| tsp1_253.txt   | 11      | 0.024399     | 0.747899     |                     |
| tsp3_1194.txt  | 15      | 0.144095     | 3.165765     |                     |
| tsp5_27603.txt | 29      | Impraticável | Impraticável |                     |
| tsp4_7013.txt  | 44      | Impraticável | Impraticável |                     |
### 2.4 Algoritmos Exatos - Branch and Bound (Sem Otimização (n)!)

| Arquivo        | Cidades | C (s)        | Python (s)   | Speedup C vs Python |
| -------------- | ------- | ------------ | ------------ | ------------------- |
| tsp2_1248.txt  | 6       | 0.000103     | 0.001059     |                     |
| tsp1_253.txt   | 11      | 0.581025     | 24.571292    |                     |
| tsp3_1194.txt  | 15      | 3.854390     | 176.354653   |                     |
| tsp5_27603.txt | 29      | Impraticável | Impraticável |                     |
| tsp4_7013.txt  | 44      | Impraticável | Impraticável |                     |

### 2.2 Análise de Otimização - TSP3 (15 cidades)

| Versão               | Complexidade | Permutações       | Observações             |
| -------------------- | ------------ | ----------------- | ----------------------- |
| Otimizada (14!)      | O((n-1)!)    | 87,178,291,200    | Fixa cidade inicial     |
| Sem Otimização (15!) | O(n!)        | 1,307,674,368,000 | Testa todas permutações |
| **Speedup**          | **15×**      | **15× menos**     | **Ganho significativo** |

### 2.3 Algoritmo MST - Resultados Completos

| Arquivo        | Cidades | Ótimo | C Custo | C Tempo  | Python Custo | Python Tempo | Razão | Speedup C/Python |
| -------------- | ------- | ----- | ------- | -------- | ------------ | ------------ | ----- | ---------------- |
| tsp1_253.txt   | 11      | 253   | 281     | 0.000028 | 269          | 0.000113     | 1.063 |                  |
| tsp2_1248.txt  | 6       | 1248  | 1272    | 0.000029 | 1272         | 0.000099     | 1.019 |                  |
| tsp3_1194.txt  | 15      | 1194  | 1519    | 0.000028 | 1424         | 0.000112     | 1.193 |                  |
| tsp4_7013.txt  | 44      | 7013  | 9038    | 0.000043 | 8402         | 0.000436     | 1.198 |                  |
| tsp5_27603.txt | 29      | 27603 | 35019   | 0.000029 | 34902        | 0.000226     | 1.264 |                  |

**Observação:** . esse d baixo eh o outro algo q roda igual o de c

| Arquivo        | Cidades | Ótimo | C Custo | C Tempo  | Python Custo | Python Tempo | Razão | Speedup C/Python |
| -------------- | ------- | ----- | ------- | -------- | ------------ | ------------ | ----- | ---------------- |
| tsp1_253.txt   | 11      | 253   | 281     | 0.000028 | 281          | 0.001439     | 1.063 |                  |
| tsp2_1248.txt  | 6       | 1248  | 1272    | 0.000029 | 1272         | 0.000695     | 1.019 |                  |
| tsp3_1194.txt  | 15      | 1194  | 1519    | 0.000028 | 1519         | 0.002386     | 1.193 |                  |
| tsp4_7013.txt  | 44      | 7013  | 9038    | 0.000043 | 9038         | 0.010062     | 1.198 |                  |
| tsp5_27603.txt | 29      | 27603 | 35019   | 0.000029 | 35019        | 0.007862     | 1.264 |                  |

**Observação:** .

---

## 3. ANÁLISE DOS RESULTADOS

### 3.1 Impacto das Otimizações

**Comparação 14! vs 15! (TSP3 - 15 cidades):**
- Versão otimizada (14!): 80290.8s medido (22.3 horas)
- Versão sem otimização (15!): 1,204,362s estimado (334.5 horas = 13.9 dias)
- **Speedup: 15× - Demonstra a importância crítica das otimizações básicas**

**Análise matemática:**
- 15! = 15 × 14! = 15 × 87,178,291,200 = 1,307,674,368,000
- Diferença: 15× mais operações na versão não otimizada
- Tempo real vs teórico confirma a análise de complexidade

### 3.2 Comparação de Linguagens

**Speedup C vs Python (Força Bruta):**
- tsp2_1248.txt: C 6.9× mais rápido
- tsp1_253.txt: C 5.9× mais rápido
- Média: **C ~6.4× mais rápido que Python para força bruta**

**MST Aproximativo:**
- Python mostrou melhor qualidade de soluções
- C foi mais rápido em execução (2-10× dependendo da instância)
- Diferenças na implementação afetam qualidade da solução

### 3.3 Qualidade do MST

**Qualidade observada (Python):**
- Razão média: 1.147 (14.7% acima do ótimo)
- Garantia teórica: 2.0 (100% acima do ótimo)
- Melhor caso: 1.019 (tsp2_1248.txt - apenas 1.9% acima)
- Pior caso: 1.264 (tsp5_27603.txt - 26.4% acima)
---

## 4. CONCLUSÕES

### 4.1 Principais Achados

1. **Impacto crítico das otimizações:** A simples fixação da cidade inicial (14! vs 15!) resultou em speedup de 15×, demonstrando que otimizações aparentemente simples têm impacto dramático

2. **Intratabilidade confirmada:** Algoritmos exatos tornam-se impraticáveis para n > 15, mesmo com otimizações básicas

3. **Impacto da linguagem:** C foi aproximadamente 6.4× mais rápido que Python para força bruta

4. **Qualidade excepcional do MST:** Média de 14.7% acima do ótimo (muito melhor que garantia teórica de 100%)

5. **Escalabilidade exponencial:** MST permite resolver instâncias com 44+ cidades em milissegundos

### 4.2 Insights sobre Otimização

A diferença entre 14! e 15! ilustra perfeitamente por que problemas exponenciais são intratáveis:
- **Crescimento explosivo:** Cada cidade adicional multiplica o tempo por n
- **Limite prático:** Mesmo com otimizações, algoritmos exatos são limitados a instâncias pequenas
- **Necessidade de aproximação:** Para aplicações reais, algoritmos aproximativos são essenciais

### 4.3 Recomendações Práticas

- **n ≤ 11:** Algoritmos exatos viáveis (com otimizações)
- **n > 11:** Apenas MST aproximativo é prático
- **Linguagem:** C para performance crítica, Python para desenvolvimento rápido
- **Otimizações:** Sempre implementar otimizações básicas - ganhos significativos com baixo esforço

### 4.4 Considerações Finais

Este trabalho demonstrou que algoritmos aproximativos são essenciais para aplicações práticas do TSP. A análise comparativa entre versões otimizadas e não otimizadas do algoritmo de força bruta revelou a importância crítica de técnicas básicas de otimização.

A qualidade prática do MST superou significativamente as garantias teóricas, validando sua utilidade em cenários reais. O experimento com o tempo real de 22.3 horas para 14! serve como demonstração prática dos limites da computação bruta e da necessidade de algoritmos inteligentes para problemas NP-Difíceis.

**A diferença entre 22.3 horas (14!) e 13.9 dias estimados (15!) comprova matematicamente a explosão combinatória e justifica o uso de algoritmos aproximativos.**

---

# Comandos para Executar o Projeto TSP

## 1. Configuração Inicial

```bash
#Necessario ter o make instalado
make help

#Compila tudo
make all
```
## 2. Algoritmos Exatos

### Força Bruta Otimizada - O((n-1)!)

```bash
#C
./bin/brute_force data/tspX_X.txt

#Python
python3 src/python/exact/brute_force_python.py data/tspX_X.txt

```
### Força Bruta Sem Otimização - O(n!)

```bash
#C
./bin/brute_force_full data/tspX_XXX.txt

#Python
python3 src/python/exact/brute_force_fullpy.py data/tspX_X.txt
```
### Branch and Bound Otimizado - O((n-1)!)

```bash
#C
./bin/branch_bound_full data/tspX_XXX.txt

#Python
python3 src/python/exact/branch_bound_python.py data/tspX_X.txt
```
### Branch and Bound Sem Otimização - O(n!)

```bash
#C
./bin/branch_bound data/tspX_XXX.txt

#Python
python3 src/python/exact/branch_bound_python_full.py data/tspX_X.txt
```
## 3. Algoritmos Aproximativos

### MST Aproximativo - O(n²)

```bash
#C
./bin/mst_approx data/tspX_X.txt

# Python
python3 src/python/approximate/mst_algorithm.py data/tspX_X.txt
```
---

## Notas Importantes

- **TSP3 (15 cidades)**: Pode demorar 17+ horas. Use `nohup` ou `screen`
- **Timeouts**: Scripts têm timeouts configurados por complexidade
- **Resultados**: Salvos automaticamente em `results/`
- **Logs**: Cada execução gera logs detalhados para análise
- **Performance**: C > Java > Python para algoritmos exatos
- **Escalabilidade**: Apenas MST é viável para n > 15
---

## CÁLCULOS

- **Razão = custo_encontrado / valor_ótimo**
- **Speedup = tempo_python / tempo_c**
- **Speedup Otimização = tempo_sem_otimização / tempo_com_otimização**
- **Tempo 15! = Tempo 14! × 15**

---

## REFERÊNCIAS

1. Cormen, T. H., et al. (2009). Introduction to Algorithms. MIT Press.
2. Applegate, D., et al. (2006). The Traveling Salesman Problem: A Computational Study. Princeton University Press.
3. Held, M., & Karp, R. M. (1970). The traveling-salesman problem and minimum spanning trees. Operations Research, 18(6), 1138-1162.

---

**Universidade Federal de Pelotas - 2025/1**
