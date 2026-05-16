void sort_even_odd(int n, int a[]) {
    int temp[n];
    int even_index = 0;
    int odd_index = 0;
    int even_count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            even_count++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            temp[even_index++] = a[i];
        } else {
            temp[even_count + odd_index++] = a[i];
        }
    }
    
    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }
}
