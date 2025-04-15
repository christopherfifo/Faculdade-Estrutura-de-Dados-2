
# Calculo de nível de complexidade


``` C
for( int k = 0; k < 10; k++){
	s = 1;
};
```

nível de complexidade

1. inicialização 

- ***k = 0*** é 1
- ***k < 10*** equivale a ***1*** na primeira vez para inicializar

1. percorrer

- ***k < 10*** equivale a  ***N*** nas demais vezes
- ***k++*** equivale a ***N***
- ***s = 1*** equivale a ***N*** já que depende de quantas vezes o for vai rodar

então o loop é ***3n + 2***

``` C
for( int j = 0; j < 10; j++){
	for( int k = 0; k < 10; k++){
		s = 1;
	};
};
```

nível de complexidade do for de cima

1. inicialização 

- ***j = 0*** é 1
- ***j < 10*** equivale a ***1*** na primeira vez para inicializar

1. percorrer

- ***j < 10*** equivale a  ***N*** nas demais vezes
- ***j++*** equivale a ***N***

então o loop de fora é ***2 n+ 2*** , porém temos que calcular a complexidade total da somas dos dois for, e como a quantidade de vezes que o for interno rodara depende do loop acima temos que multiplicar a complexidade do for interno por ***n***


Mas temos que saber a complexidade total

2n + 2 + n(3n + 2)
2n + 2 + 3n² + 2n
3n² + 4n + 2

ou seja a complexidade total é ***3n² + 4n + 2***

``` C
for( int i = 0; i < 10; i++){
	for( int j = 0; j < 10; j++){
		for( int k = 0; k < 10; k++){
			s = 1;
		};
	};
};
```

nível de complexidade do for de cima

1. inicialização 

- ***i = 0*** é 1
- ***i < 10*** equivale a ***1*** na primeira vez para inicializar

1. percorrer

- ***i < 10*** equivale a  ***N*** nas demais vezes
- ***i++*** equivale a ***N***

então o loop de fora é ***2 n+ 2*** , porém temos que calcular a complexidade total da soma dos complexidade total dos dois for internos mais a desse for, e como a quantidade de vezes que o for interno rodara depende do loop acima temos que multiplicar a complexidade do for interno por ***n***

Logo a complexidade total desse trecho é

2 + 2n + n(3n² + 4n + 2)
2 + 2n + 3n³ + 4n² + 2n
3n³ + 4n² + 4n + 2

Quando tratamos o big O(n), todas as constantes são tratadas como nula (1), então fica ***n x n x n = n³***
# modelos de busca e ordenação

# modelos de busca

vetor desordenado: busca linear que tem baixa eficiência

vetor ordenado: busca linear, busca ordenada e busca binaria (superior a ordenada) 

### busca linear

melhor caso: testara apenas 1 elemento
pior caso: testara n elementos
### busca ordenada

sendo igual a busca linear, se difere apenas que para cada interação é feita uma verificação se o elemento verificado no vetor é maior do que o elemento procurado, pois como o vetor é ordenado significa que tal elemento não existe, então o mesmo é encerrado

### Busca Binaria 

nesse modelo a cada repetição ele verifica se o meio do vetor é maior ou menor do que o elemento a ser encontrado, caso seja igual o programa é encerrado, mas caso seja o menor o vetor ira procurar na metade esquerda do código, caso o contrario (for maior) ira procurar pela par te direita