void reverseString(char* s, int sSize) {
    int left=0,rigth=sSize-1;
    char temp;
    while(left<rigth){
       temp=s[left];
       s[left]=s[rigth];
       s[rigth]=temp;
        left++;
        rigth--;
    }
}