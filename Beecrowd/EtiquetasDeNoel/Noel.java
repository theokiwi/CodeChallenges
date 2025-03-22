/******************************************************************************
 * 
 *  ETIQUETAS DE NOEL - BEECROWD
 *  
 *  Autor: Theo Diniz Viana
 *  Nota: 100/100
 *  Linguagem: JAVA 19
 *  Data: 22/03/2025
 ******************************************************************************/
import java.util.*;
public class Noel{
    public static void compara(Destinatarios[] destinos, Carta[] cartas){
        for(int i = 0; i < destinos.length; i++){
            String lingua = destinos[i].idioma;
            for(int j = 0; j < cartas.length; j++){
                if(lingua.equals(cartas[j].idioma)){
                    System.out.println(destinos[i].nome + "\n" + cartas[j].mensagem + "\n");
                }
            }
        }
    }
    public static void main(String[] args) {
        Scanner rc = new Scanner(System.in);
        int qntCartas = rc.nextInt();
        rc.nextLine();
        Carta[] cartas = new Carta[qntCartas];

        for(int i = 0; i < qntCartas; i++){
            String idioma = rc.nextLine();
            String mensagem = rc.nextLine();
            cartas[i] = new Carta(idioma, mensagem);
        }
        int qntDestinatarios = rc.nextInt();
        rc.nextLine();

        Destinatarios[] destinos = new Destinatarios[qntDestinatarios];

        
        for(int j = 0; j < qntDestinatarios; j++){
            String nome = rc.nextLine();
            String idioma = rc.nextLine();
            destinos[j] = new Destinatarios(idioma, nome);
        }

        compara(destinos, cartas);

    }
}

class Carta{
    String idioma;
    String mensagem;

    public Carta(String idioma, String mensagem){
        this.idioma = idioma;
        this.mensagem = mensagem;
    }
}

class Destinatarios{
    String idioma;
    String nome;
    
    public Destinatarios(String idioma, String nome){
        this.idioma = idioma;
        this.nome = nome;
    }
}