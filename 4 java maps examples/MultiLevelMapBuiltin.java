// Solution for https://www.beecrowd.com.br/judge/en/problems/view/1049
import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main (String[]args) {
        Scanner scanner = new Scanner(System.in);
        String word1 = new String(scanner.nextLine());
        String word2 = new String(scanner.nextLine());
        String word3 = new String(scanner.nextLine());
        
        Map<String, Map<String, Map<String, String>>> dict = Map.of(
            "vertebrado",
                Map.of(
                    "ave",
                        Map.of(
                            "carnivoro", "aguia",
                            "onivoro", "pomba"
                        ),
                    "mamifero",
                        Map.of("onivoro","homem",
                                "herbivoro","vaca"
                        )
                ),
            "invertebrado",
                Map.of(
                    "inseto",
                        Map.of(
                            "hematofago", "pulga",
                            "herbivoro", "lagarta"
                        ),
                    "anelideo",
                        Map.of(
                            "hematofago","sanguessuga",
                            "onivoro","minhoca"
                        )
                )
        );
        
        String word = dict.get(word1).get(word2).get(word3);
        
        System.out.println(word);
    }
}
