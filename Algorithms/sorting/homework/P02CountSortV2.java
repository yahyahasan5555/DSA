package Sorting;

public class Sorting {

    /* **
     * Homework:
     * Count sort.
     * Min range = -50000, Max range = 50000.
     * ascending order.
     * MAx array length = 50000.
     */

    public static void countSort(int[] arr, int len) {
        int minVal = -50000;
        int maxVal = 50000;

        // min value always at index 0 (either +ve or -ve).
        int range = maxVal - minVal + 1;
        int[] freq = new int[range];

        for(int val: arr)
            ++freq[val - minVal];

        int idx = 0;
        for(int i = 0; i < range; ++i)
            for(int j = 0; j < freq[i]; ++j)
                arr[idx++] = (i + minVal);
    }

    static void test1() {
        int[] arr = {-5, 2, -3, 1, 1234, -2453};
        int len = 6;

        countSort(arr, len);

        for(int i = 0; i < len; ++i)
            System.out.print(arr[i] + " ");

        System.out.println("\n****************************");
    }

    public static void test2() {
        int[] arr = {-50000, -5000, -49999, -49998, -49997};
        int len = 5;

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
