#ifndef QUEBRADOR_SENHA
#define QUEBRADOR_SENHA

// 1.Apenas letras minusculas (codigos da tabela ASCII do 97 ao 122 em decimal) 
// e numeros (codigos da tabela ASCII do 48 ao 57 em decimal) sao permitidos
// 2. A senha deve conter exatamente 6 caracteres
int quebrador_senha_exaustivo(void);

// 1.Apenas letras minusculas (codigos da tabela ASCII do 97 ao 122 em decimal) 
// e numeros (codigos da tabela ASCII do 48 ao 57 em decimal) sao permitidos
// 2. A senha deve conter exatamente 6 caracteres e pelo menos 2 letras e 2 numeros, sem repeticao
int quebrador_senha_poda(void);

#endif
