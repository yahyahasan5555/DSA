package Sorting;

import java.util.ArrayList;
import java.util.Arrays;

public class Sorting {

    /* **
     * Homework:
     * Count sort for strings V1.
     * Based on the first character ONLY.
     * consists of lower case letters ONLY.
     */

    public static void countSortStrings(String[] arr) {
        // While the algo based on the first char,
        // then we don't need to reserve more than 26 index
        // for each english letter char.

        int range = 26;
        ArrayList<String> [] freqList = new ArrayList[range];

        for(String str: arr) {
            int idx = str.charAt(0) - 'a';

            if(freqList[idx] == null)
                freqList[idx] = new ArrayList<>();

            freqList[idx].add(str);
        }


        int idx = 0;
        for(int i = 0; i < range; ++i)
            for(int j = 0; freqList[i] != null && j < freqList[i].size(); ++j)
                arr[idx++] = freqList[i].get(j);
    }

    //==========================
    public static void print(String[] arr) {
        for(String str: arr)
            System.out.print(str + " ");

        System.out.println("\n****************************");
    }

    public static void test1() {
        String[] arr = {"yahya", "adham", "anything", "hi", "yaya"};
        countSortStrings(arr);

        print(arr);
    }

    public static void test2() {
        String[] arr = {};
        countSortStrings(arr);
        print(arr);
        //--------------

        String[] arr2 = {"tah", "tah", "tah", "tah", "tah"};
        countSortStrings(arr2);
        print(arr2);
    }

    public static void test3() {
        String[] arr = {"ahmed", "ali", "alaa", "alya"};
        countSortStrings(arr);
        print(arr);
    }

    public static void main(String [] args) {
        test1();
        test2();
        test3();
    }
}
