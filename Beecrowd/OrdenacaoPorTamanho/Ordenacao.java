/******************************************************************************
 * 
 *  ORDENAÇÃO POR TAMANHO - BEECROWD
 *  
 *  Autor: Theo Diniz Viana
 *  Nota: 100/100
 *  Linguagem: JAVA 19
 *  Data: 21/03/2025
 ******************************************************************************/

 import java.util.*; 
public class Ordenacao {
    public static void main(String[] args) {
        Scanner rc = new Scanner(System.in);
        int qntConjuntos = 0;
        qntConjuntos = rc.nextInt();
        rc.nextLine();

        for(int i = 0; i < qntConjuntos; i++){
        Fila fila = new Fila(100);
        String linha = rc.nextLine();
        String linhasSplitadas[] = linha.split(" ");
        for(int j = 0; j < linhasSplitadas.length; j++){
            fila.inserirOrdenado(linhasSplitadas[j]); 
        }
        fila.printaFila();
        System.out.println();
        }
        

    }
}

class Fila{
    int n;
    int max;
    String[] linhas;

    public Fila(int max){
        this.max = max;
        n = 0;
        linhas = new String[max];
    }

    public int ondeInserir(String linha){
        int pos = 0;

        while(pos < n && linhas[pos].length() >= linha.length()){
            pos++;
        }
        return pos;
    }

    public void inserirOrdenado(String linha){
        if(n == max){
            System.out.println("Fila cheia no inserir");
        }
        int pos = ondeInserir(linha);
        for(int i = n; i > pos; i--){
            linhas[i] = linhas[i - 1];
        }
        linhas[pos] = linha;
        n++;
    }

    public void printaFila(){
        if(n == 0){
            System.out.println("Fila Vazia");
        }
        for(int i = 0; i < n; i++){
            System.out.print(" " + linhas[i]);
        }
    }
}

