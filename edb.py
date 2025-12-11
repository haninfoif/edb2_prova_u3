import matplotlib.pyplot as plt
import io

dados_str = """
100 236 406
200 1437 1034
300 1862 2165
400 2786 1499
500 4697 1335
600 18760 3080
700 20337 3506
800 20727 10690
900 22520 5293
1000 30955 4478
1100 29383 4346
1200 38565 5473
1300 35615 7498
1400 43271 6509
1500 40206 5189
1600 35189 4582
1700 38079 5683
1800 40171 5132
1900 49636 5832
2000 51067 5917
2100 54057 6673
2200 57705 8164
2300 65267 6852
2400 67306 7962
2500 74653 7677
2600 110948 9570
2700 96655 7948
2800 114523 11341
2900 106872 10214
3000 157647 14260
3100 142637 9607
3200 147547 10809
3300 128717 10100
3400 137844 11475
3500 229185 13135
3600 157818 17860
3700 346715 24380
3800 502363 23509
3900 287271 15134
4000 357842 22026
4100 384626 25559
4200 278244 16493
4300 335534 14669
4400 295040 15268
4500 278701 13206
4600 259436 13878
4700 234514 13904
4800 246254 14324
4900 254025 14778
5000 267567 15090
"""

tamanhos = []
tempos_ineficiente = []
tempos_eficiente = []

# Processar os dados
for linha in dados_str.strip().split('\n'):
    partes = linha.split()
    if not partes[0].isdigit(): continue
    tamanhos.append(int(partes[0]))
    tempos_ineficiente.append(int(partes[1]))
    tempos_eficiente.append(int(partes[2]))

# Criar o gráfico
plt.figure(figsize=(10, 6))

plt.plot(tamanhos, tempos_ineficiente, label='Ineficiente (Busca Linear)', color='red', marker='o')
plt.plot(tamanhos, tempos_eficiente, label='Eficiente (STL Set/Map)', color='green', marker='x')

plt.title('Comparação de Performance: Ineficiente vs Eficiente')
plt.xlabel('Tamanho da Entrada (N)')
plt.ylabel('Tempo de Execução (microsegundos)')
plt.legend()
plt.grid(True)

# Salvar ou mostrar
plt.savefig("grafico_comparativo.png")
plt.show()
