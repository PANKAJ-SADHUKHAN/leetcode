class Solution {
    public int lengthOfLongestSubstring(String s) {
        int start=0;
        int end=0;
        int max=0;
        HashSet<Character> hash_set=new HashSet();
        while(end<s.length()){
            if(!hash_set.contains(s.charAt(end))){
                hash_set.add(s.charAt(end));
                end++;
                max=Math.max(hash_set.size(),max);
            }else{
                hash_set.remove(s.charAt(start));
                start++;
            }
        }
        return max;
    }
}
