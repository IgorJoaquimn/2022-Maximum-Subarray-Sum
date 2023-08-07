# 2022-Maximum-Subarray-Sum

# Trabalho Prático 2

```
DCC215 - Algoritmos 1
Igor Joaquim da Silva Costa
```
## 1. Introdução

Oproblemapropostofoidescobrirqualseriaointervalodeshowsconsecutivosque
mais agradariaum grupode amigosaoir aofestival Rock InRio.Mais precisamente,é
apresentadaumasequênciadeshowseanotadecadapessoadogrupoparacadaumdeles.O
intervalodeshowsquemaisagradaumgrupoéaqueleondeasomadasnotasdosshowsno
intervalo é a maior possível.
Pararesolveroproblemacitado,cadashowfoitratadocomoumnúmeroemumvetor,
onde,apartirdele,devia-secalcularosubarrayconsecutivocomsomamáxima,issoé,opar
(x,y) onde x é pelomenos ye asoma dointervalo(x,y)é amáxima.Nessesentido,o
problemaapresentadoéreduzidoàumainstânciadoMaximumSubarraySum.Diantedisso,
foiimplementadoumalgoritmopolinomialdotipoDividirparaConquistarcapazderesolver
o problema.
Diantedoexposto,adocumentaçãopresentepossuicomoobjetivodetalharcomoo
sistemafoimodelado(Seção2),oquãoeficienteelepodeser(Seção3).Porfim,oprojetoé
sumarizado junto com os aprendizados gerados durante a produção do trabalho(Seção 4).

## 2. Modelagem

Estaseçãotemcomoobjetivodiscutirasdecisõesquelevaramàatualmodelagemdo
programa.

# 2.1 Maximum Subarray Sum

Comoelucidadonaseção1,oproblemaapresentadopodeserreduzidoaoproblema
MaximumSubarraySum,ondedeseja-seencontrarqualéopar(x,y),comxpelomenosy,
que possuiamaiorsoma, dentretodosospares (x,y)possíveisnainstância.Nocontexto
apresentado,cadaposiçãoxdoarraydeentradadoproblemaMaximumSubarraySuméa
somadetodasasnotasquecadapessoadogrupodeuparaoshowx.Dessaforma,oproblema
pode ser transformado em uma instância de Maximum Subarray Sum.


# 2.2 Resolver Maximum Subarray Sum

A fimde resolvero problema Maximum Subarray Sum (MSS),foi utilizadoum
algoritmodedividirparaconquistar.Oproblemaapresentadopodeserquebradoem 3 partes,
sendo N o tamanho do vetor da entrada.
OMSSdovetorquecomeçaem 1 eterminaemNpodeserde 3 formas,aprimeira

formadizqueMSS estáentre 1 e 𝑁 2 − 1 .Asegunda formadizque oMSS estáentre
𝑁 2 + 1 eN.Aterceiraformadizque,seoMSSnãoestánemcompletamentenametade

esquerda, nem completamente na metade direita, ele obrigatoriamente deve possuir o
elemento que parte o vetor ao meio.
Nessesentido,oMSSde[1,N]éoSubarraymáximoentreametadedaesquerda,a
metade da direita e o maior array que o elemento que divide o vetor ao meio.
Alémdisso,devidoànaturezadoproblema,semprequedoisSubarraystêmamesma
soma máxima, o desempate pelo critério maior número de elementos presentes no Subarray.

# 2.3 Encontrar Subarrays das metades e meio

OMSSdasmetades direitaeesquerdaécalculadorecursivamente.Paracalcularo
Subarray quecontémomeio,foiusadaumaestratégiaiterativa.OSubarrayquecontémo
valoraomeioouéosubarraymáximoqueterminanomeio,ouéosubarraymáximoque
começaaomeioouéauniãodosdoisúltimos.Paracalculartaissubarrays,bastaiterarsobre
(início,meio),paraosubarrayqueterminanomeio,e(meio,fim)paraosubarrayquecomeça
aomeio,alterandoasomamáximasemprequeumanovasomamáximamaiorqueaanterior
tenha sido encontrada.
Dessaforma,éfactívelqueoMaximumSubarraySumpossaserresolvidoemtempo
polinomial,jáquenãoexistesobreposiçãodeproblemasnahoraderesolverasdependências
de um intervalo em específico.

# 2.4 Estrutura de Dados

Pararepresentaroarraydeentrada,foiusadootipopadrãovectordoc++,alémdisso,
foi implementado um vetor de somacumulativa, parafacilitarocálculoda somade um
intervalo.


## 3. Análise de complexidade

# 3.1 Espaço

SejaNonúmerodeshowseMonúmerodeamigos.Inicialmente,sãocriadosdois
vetoresdeNposiçõespararepresentarosdadosdaentradaeasomacumulativa.Assim,a
complexidade de espaço se torna𝑂(𝑁)na quantidadede shows.

# 3.2 Tempo

```
Para análise de tempo, considere N o número de shows e M o número de amigos.
```
## 3.2.1 Função de recorrência

```
ParaseresolveroMaximumSubarraySum,sãofeitasduaschamadasrecursivas,cada
```
umacomtamanho 𝑁 2 ,alémdeiterarsobretodososelementosdainstânciapassada.Tomando

a equação de recorrência:

#### 𝐹(𝑁)= 2 *𝐹(𝑁 2 ) + 𝑂(𝑁)

```
Oteoremamestredizquetalfunçãopossuicomplexidade𝑂(𝑁𝑙𝑜𝑔 2 (𝑁)).Logo,oalgoritmo
```
para resolver o problema cresce linear-lognalmente no número de shows.

## 4. Conclusões

Comointuitodeencontraromaiorintervalodeshowsqueagradeamaiorpartedeum
grupo de amigos, foi implementado um programa que utiliza algoritmos de dividirpara
conquistar para resolver o problema.
Duranteoprojetodosistemaforamlevadasemconsideraçãonãosóaspectospráticos
da implementaçãode umamodelagemcomputacional,mastambémcomoalinguagemde
programaçãoescolhidapoderia serumaferramentaútilparachegarno objetivoesperado.
Todaaquestãodemapearummini-mundodeinteresseemummodelocomputacionalrobusto
semostroubastanteprodutiva,levandooalunoapensaremformascriativasde seresolver e
entender oproblema,tendocomoresultadoum extensoaprendizadosobrecomo pensar,
questionareimplementarumalgoritmodedividirparaconquistarnaprática.Porfim,otempo


extrausadoparaprojetarosistematrouxeváriasrecompensasnosentidodaimplementação,
sendo um aspecto a ser levado para trabalhos futuros.
Nessesentido,todoofluxodetrabalhofoiessencialparaaconsolidaçãodeconteúdos
aprendidos emsala, além de apresentar,de formaprática,comosoftwaresmaiores, mais
consistentes, robustos e inteligentes são projetados e implementados.

## 5. Instruções para compilação e execução:

## 5.1 Compilação

Existempartesdoprogramaquesãocompatíveisapenasàsversõesmaisrecentesda
linguagem c++, dito isso, deve-se seguir as seguintes configurações para a compilação:

```
Linguagem: C++
Compilador: Gnu g++
Flags de compilação:-std=c++11 -g
Versão da linguagem: standard C++1 1
Sistema operacional (preferência): distribuições baseadas no kernel Linux 5.15.
```
Ocomandoparacompilaroprogramaautomaticamenteestápresentenoarquivo **“Makefile”**
esuaexecuçãoéchamadapelocomando **“makeall”** .Destemodo,oexecutável“tp02”estará
compilado e pronto para ser utilizado.

### 5.2 Execução

```
Seguem as instruções para a execução manual:
```
1. Certifique-se que o compilável foigeradode maneiracorreta,sealgum problema
    ocorrer, execute o comando “make all” presente no “Makefile”.
2. Uma vez que os passos anteriores foram cumpridos, executeo programa com o
    comando: ./tp02 < Teste01.txt )
3. A saída será impressa no terminal.


