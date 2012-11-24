
public class Solution {
    public ArrayList<String> anagrams(String[] strs) {       
    
    Map<String,List<String>> anagramMap = new HashMap<String, List<String>>();
    ArrayList<String> opList = new ArrayList<String>();
    
    if(strs.length <= 1) return opList;
    
    for(String str:strs) {    
    	char[] tempArr = str.toCharArray();
    	Arrays.sort(tempArr);
    	String temp = "";
    	for (int i=0;i<tempArr.length;i++) {
    		temp += tempArr[i];
    	}
    	if(anagramMap.containsKey(temp)) {
    		List<String> tempList = anagramMap.get(temp);
    		tempList.add(str);
    	}else {
    		List<String> tempList = new ArrayList<String>();
    		tempList.add(str);
    		anagramMap.put(temp, tempList);
    	}     	
    }
    for (List<String> strList:anagramMap.values()) {
    	if(strList.size() <= 1) continue;
    	for(String str:strList)
    		opList.add(str);
    }
    
    return opList;

}