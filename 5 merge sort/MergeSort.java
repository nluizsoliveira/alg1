import java.lang.Math;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Main
{
	public static void main(String[] args) {
	    ArrayList<Integer> oddList = new ArrayList<Integer>(List.of(1, -2, 3, 8, 5));
	    ArrayList<Integer> evenList = new ArrayList<Integer>(List.of(1, -2, 3, 8));
        
        oddList = mergeSort(oddList);
        evenList = mergeSort(evenList);
        
        System.out.println(oddList);
        System.out.println(evenList);
	}
	
	public static ArrayList<Integer> mergeSort(ArrayList<Integer> list){
	   // Base case: List of or zero elements being sorted is already sorted. 
	   if(list.size() <=1){
	       return list;
	   }
	   
	   ArrayList<Integer> left = new ArrayList<Integer>();
	   ArrayList<Integer> right = new ArrayList<Integer>();
	   

	   for(int pos = 0; pos < list.size(); pos++){
	       if(pos < list.size() / 2){
	           left.add(list.get(pos));
	       } else {
	           right.add(list.get(pos));
	       }
	   }
	   
	   left = mergeSort(left);
	   right = mergeSort(right);
	   
	   return merge(left, right);
	}
	
	public static ArrayList<Integer> merge(ArrayList<Integer> right, ArrayList<Integer> left){
	    ArrayList<Integer> result = new ArrayList<Integer>();
	    
	    while(left.size() > 0 && right.size() > 0){
	        if(left.get(0) <= right.get(0)){
	            result.add(left.get(0));
	            left.remove(0);
	        }
	        else{
	            result.add(right.get(0));
	            right.remove(0);
	        }
	    }
	    
	    // left and right may not have the same size. 
	    // following code consumes remaining elements of the bigger list.
	    while(left.size() > 0){
	        result.add(left.get(0));
	        left.remove(0);
	    }
	    
	    while(right.size() > 0){
	        result.add(right.get(0));
	        right.remove(0);
	    }
	    
	    return result;
	}
}
