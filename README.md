# KeyGenArd
Um gerador de senhas pessoal, que combina 3 elemento (serviço, usuário, senha interna). No final o arduino escreve automaticamente o resultado ( de tamanho de 16 caracteres)


 * Display
 * VCC -> VCC
 * GND -> GND
 * SCL -> 3
 * SDA -> 2
 * Button Back -> 4
 * Button Next -> 5
 * Button Select -> 6
 * Button Insert -> 7

Não se esqueça de editar as linhas entre 30 a 35, e a linha 170 seguindo as intrusões na linha 150 
//Aqui vai a senha interna de 8 caracteres
char segredo[8] = "SenhaInt";
//A quantidade de vezes que ele vai passar pela cifra de César
int cont_for_recripty = 1;
//O valor para misturar o conteudo 
int cesar_chiper = 100;
//O dicionario que se ira usar a cifra de César
char dicionario_cesar[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','!','@','#','$','%','&','*','(',')','-','+','=','<','>','/'};


