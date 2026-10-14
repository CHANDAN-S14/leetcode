int lengthOfLastWord(char* s) {
    int count=0;
    int len=0;
    for(int i=0;s[i]!='\0';i++ ){
        len++;
    }
    int i=len-1;
    while(i>=0 && s[i]==' '){
        i--;
    }
    while(i>=0 && s[i]!=' '){
        count++;
        i--;
    }

    if(count==0){
       count=1;
    }
    return count;

    
    
}