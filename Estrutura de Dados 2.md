
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