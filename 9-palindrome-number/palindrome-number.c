bool isPalindrome(int x) {
    if(x<0){
        return false;
    }
   
    int digit,original=x,reverse=0;
    while(x>0){
        digit=x%10;
         if (reverse > (INT_MAX - digit) / 10) {
            return false;
        }
        reverse=reverse*10+digit;
        x=x/10;
    }
    if(original==reverse){
        return true;
    }
    else{
        return false;
    }
}