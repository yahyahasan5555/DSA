package Sorting;

import java.util.Arrays;

public class Sorting {

    /* **
     * Homework:
     * Count sort for a range.
     */

    public static void countSort(int[] arr, int len) {
        if(len <= 1) return;

        // Get minVal:
        int minVal = arr[0];
        for(int i = 1; i < len; ++i)
            if(arr[i] < minVal)
                minVal = arr[i];

        // While maxVal - minVal <= 500,
        // there is no need to reserve all the range.
        int[] freq = new int[501];

        for(int val: arr)
            ++freq[val - minVal];

        int idx = 0;
        for(int i = 0; i < 501; ++i)
            for(int j = 0; j < freq[i]; ++j)
                arr[idx++] = (i + minVal);
    }

    static void test1() {
        int[] arr = {-500, -1, -55, -4, -7, -100};
        int len = 6;

        countSort(arr, len);

        for(int i = 0; i < len; ++i)
            System.out.print(arr[i] + " ");

        System.out.println("\n****************************");
    }

    public static void test2() {
        int[] arr = {-50000, -49999, -49998, -49997};
        int len = 4;

        countSort(arr, len);

        for (int i = 0; i < len; ++i)
            System.out.print(arr[i] + " ");

        System.out.println("\n***************************");
    }

    public static void test3() {
        int[] arr = {};
        countSort(arr, 0);

        int[] arr2 = {1, 2, 3, 4, 5, 6};
        int len = 6;

        for(int i = 0; i < len; ++i)
            System.out.print(arr2[i] + " ");

        System.out.println("\n**********************");
    }

    public static void main(String [] args) {
        test1();
        test2();
        test3();
    }
}
