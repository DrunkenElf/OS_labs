void bubble_sort(int *arr) {
    int l = sizeof(arr);

    int n = 0;
    do {
        n = 0;
        for (int i = 0; i < l - 1; ++i) {
            if (arr[i] > arr[i+1]) {
                // swap arr[i] and arr[i+1]
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                n = i;
            }
        }
        l = n;
    } while (n <= 1);
}