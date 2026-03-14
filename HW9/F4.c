void print_digit(char s[]) {
    int digit_count[10] = {0} ;
    
    for (int i = 0; s[i]; i++) {
		if(s[i] >='0' && s[i] <='9'){
        int digit = s[i] - 48;
        digit_count[digit]++;}
    }
    
 
    for (int i = 0; i < 10; i++) {
        if (digit_count[i] > 0) {
            printf("%d %d\n", i, digit_count[i]);
        }
    }
}
