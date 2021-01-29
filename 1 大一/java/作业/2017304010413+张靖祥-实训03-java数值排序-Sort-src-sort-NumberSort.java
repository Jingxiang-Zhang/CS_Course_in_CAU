package sort;

public class NumberSort {

    public void Number_Sort(int[] num) {    
        for (int i = 0; i < num.length - 1; i++) {
            for (int j = 0; j < num.length - 1; j++) {
                num[j] = num[j] > num[j + 1] ? num[j] : num[j + 1];
            }
        }
    }

    public void Number_Sort(double[] num) {
        for (int i = 0; i < num.length - 1; i++) {
            for (int j = 0; j < num.length - 1; j++) {
                num[j] = num[j] > num[j + 1] ? num[j] : num[j + 1];
            }
        }
    }

    public void Number_Sort(long[] num) {
        for (int i = 0; i < num.length - 1; i++) {
            for (int j = 0; j < num.length - 1; j++) {
                num[j] = num[j] > num[j + 1] ? num[j] : num[j + 1];
            }
        }
    }

    public void Number_Sort(char[] num) {
        for (int i = 0; i < num.length - 1; i++) {
            for (int j = 0; j < num.length - 1; j++) {
                num[j] = num[j] > num[j + 1] ? num[j] : num[j + 1];
            }
        }
    }

    public void Number_Sort(short[] num) {
        for (int i = 0; i < num.length - 1; i++) {
            for (int j = 0; j < num.length - 1; j++) {
                num[j] = num[j] > num[j + 1] ? num[j] : num[j + 1];
            }
        }
    }

    public void Number_Sort(float[] num) {
        for (int i = 0; i < num.length - 1; i++) {
            for (int j = 0; j < num.length - 1; j++) {
                num[j] = num[j] > num[j + 1] ? num[j] : num[j + 1];
            }
        }
    }

    public void Number_Sort(byte[] num) {
        for (int i = 0; i < num.length - 1; i++) {
            for (int j = 0; j < num.length - 1; j++) {
                num[j] = num[j] > num[j + 1] ? num[j] : num[j + 1];
            }
        }
    }
}
