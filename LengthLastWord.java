
/**
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
**/

int lengthLastWord(String input) {
    
    //convert it into char array / traverse char by char 
    int len = input.length();
    int lastLen = 0;
    int pastLen = 0;
    for (int index = 0;index < len;index++) {
        lastLen ++;
        if(input.charAt(index) == ' ') {
            pastLen = lastLen;
            lastLen = 0;
            
        }
    }
    
    return pastLen;
            
}
