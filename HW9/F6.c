int is_two_same(int size, int a[]) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] == a[j]) {
                //printf("YES\n");
                return 1;
            }
        }
    }
    //printf("NO\n");
    return 0;
}
