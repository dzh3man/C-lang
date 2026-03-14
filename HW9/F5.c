int find_max_array(int size, int a[]) {
    int t = a[0];  
    for (int i = 1; i < size; i++) {
        if (a[i] > t) {
            t = a[i];  
        }
    }
    return t;  
}
