/******************************************************************************
Solution to https://www.beecrowd.com.br/judge/en/problems/view/1133
*******************************************************************************/
import java.util.Scanner;
import java.util.HashMap;
public class Main
{
    public static class Value{
        public String type;
        public int number;
        public Value(String type, int number){
            this.type = type;
            this.number = number;
        }
        
        public String toString(){
            return type + ": " + number;
        }
        
        public void addNumber(){
            number++;
        }
    }
        
	public static void main(String[] args) {
	    HashMap<Integer, Value> map = new HashMap<Integer, Value>();
	    map.put(1,new Value("Alcool", 0));
	    map.put(2,new Value("Gasolina", 0));
	    map.put(3,new Value("Diesel", 0));

        Scanner scanner = new Scanner(System.in);
        int choice = -1;
        
        System.out.println("MUITO OBRIGADO");
        
        while(choice != 4) {
            choice = scanner.nextInt();
            while(map.get(choice) == null && choice != 4){
                choice = scanner.nextInt();
            }
            if(choice != 4){
                map.get(choice).addNumber();
            }
        }
        
        for(int i = 1; i <= 3; i++){
            System.out.println(map.get(i));
        }
    }
}
