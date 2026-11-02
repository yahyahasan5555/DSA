package Sorting;

public class Sorting {

    /* **
     * Homework:
     * Updating the insertion sort code's lecture.
     * Descending order.
     * Utilize sort function.
     * Maximum three lines of code.
     */

    // Lecture's code:
    public static void insertionSort(int[] arr, int len) {
        for(int i = 1; i < len; ++i) {
            int curKey = arr[i];
            int j = i - 1;

            while(j >= 0 && arr[j] > curKey) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = curKey;
        }
    }

    // Homework ans:
    public static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    public static void insertionSortDesc(int[] arr, int len) {
        for(int i = 1; i < len; ++i)
            for(int j = i; (j - 1 >= 0 && arr[j] > arr[j - 1]); --j)
                swap(arr, j, j-1);
    }

    public static void test1() {
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8};
        int len = 8;

        insertionSortDesc(arr, len);

        for(int i = 0; i < len; ++i)
            System.out.print(arr[i] + " ");

        System.out.println("\n***********************");
    }

    public static void test2() {
        int[] arr = {};
        insertionSortDesc(arr, 0);

        int[] arr2 = {5};
        insertionSortDesc(arr2, 1);
        for(int i = 0; i < 1; ++i)
            System.out.print(arr2[i] + " ");

        System.out.println("\n*****************");
    }

    public static void test3() {
        int[] arr = {9, 7, 5, 4, 3, 2, 0};
        int len = 7;

        insertionSortDesc(arr, len);

        for(int i = 0; i < len; ++i)
            System.out.print(arr[i] + " ");

        System.out.println("\n********************");
    }

    public static void main(String [] args) {
        test1();
        test2();
        test3();
    }
}
