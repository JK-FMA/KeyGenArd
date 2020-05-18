# KeyGenArd
Um gerador de senhas pessoal que combina 3 elemento (serviço, usuário, senha interna). No final o arduino escreve automaticamente o resultado ( de tamanho de 16 caracteres)

<hr>

A idéia desse projeto e trazer uma forma de gerar uma senha de forma que se seguido os mesmo passo se tenha o mesmo resultado todas as vezes, ele gera a senha se baseando no serviço de login, no usuário usado para o login, e em uma senha interna dentro do arduino, depois de pegar essas três informações ele as mistura e utiliza um dicionario alternativo para realizar junto a ele a cifra de César, por fim ele insere dentro do computador, evitando assim um intermediário.

<hr>

-->Coisas necessarias
 * arduino MicroPro (mas tambem pode funcionar no arduino Leonardo)
 * Tela OLED I2C 128×64 0.96
 * 4 resistores de 10 Ohms
 * 4 botões
 
--> Display
 * VCC -> VCC
 * GND -> GND
 * SCL -> 3
 * SDA -> 2
 
-->Botões
 * Button Back -> 4
 * Button Next -> 5
 * Button Select -> 6
 * Button Insert -> 7
 
<hr>

<h3>Não se esqueça de editar as linhas entre 30 a 35, e a linha 170 seguindo as intrusões na linha 150</h3>
<br>//Aqui vai a senha interna de 8 caracteres
<ul><li>char segredo[8] = "SenhaInt";</li></ul>
<br>//A quantidade de vezes que ele vai passar pela cifra de César
<ul><li>int cont_for_recripty = 1;</li></ul>
<br>//O valor para misturar o conteudo 
<ul><li>int cesar_chiper = 100;</li></ul>
<br>//O dicionario que se ira usar a cifra de César
<ul><li>char dicionario_cesar[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','!','@','#','$','%','&','*','(',')','-','+','=','<','>','/'};</li></ul>


