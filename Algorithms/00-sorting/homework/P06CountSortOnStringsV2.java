package Sorting;
import java.util.ArrayList;

public class Sorting {

    /* **
     * Homework:
     * Count sort for strings V2.
     * Based on the first and second characters.
     * consists of lower case letters ONLY.
     */

    public static final int SIZE_LETTERS = 26;

    /* **
     * getId function, takes at least a string of 2 characters,
     * and returns a unique ID based only on the first 2 characters in the string.
    */
    public static int getId(String str) {
        if(str.length() < 2)
            throw new IllegalArgumentException("The string length should be at least 2 chars: " + str);

        int first = str.charAt(0) - 'a';
        int sec = str.charAt(1) - 'a';
        return first * SIZE_LETTERS + sec;
    }

    public static void countSortStringsV2(String[] arr) {
        int range = SIZE_LETTERS * SIZE_LETTERS; // all permutations.

        ArrayList<String>[] freqList = new ArrayList[range];
        for(String str: arr) {
            int id = getId(str);

            if(freqList[id] == null)
                freqList[id] = new ArrayList<>();

            freqList[id].add(str);
        }


        int idx = 0;
        for(ArrayList<String> list: freqList)
            if(list != null)
                for(String str: list)
                    arr[idx++] = str;
    }

    //-----------------------------------------Testing-------

    public static void print(String[] arr) {
        for(String str: arr)
            System.out.print(str + " ");

        System.out.println("\n********************************");
    }

    public static void test1() {
        String[] arr = {"yahya", "yara", "yaya", "yab", "ybya"};
        countSortStringsV2(arr);
        print(arr);
    }

    public static void test2() {
        String[] arr = {};
        countSortStringsV2(arr);
        print(arr);

        //-------------------
        String[] arr2 = {"yah", "yah", "yah", "yah"};
        countSortStringsV2(arr2);
        print(arr2);
    }

    public static void test3() {
        String[] arr = {"ahmed", "ali", "abeer", "alya", "alia"};
        countSortStringsV2(arr);
        print(arr);
    }

    public static void main(String [] args) {
        test1();
        test2();
        test3();
    }
}
