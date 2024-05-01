class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index=-1;
        for(int i=0; word[i]!= '\0';i++){
            if(ch== word[i]){
                index =i;
                break;
            }
        }
        string answer="";
        for(int i=0;i<word.size();i++){
            if(i<=index){
                answer+= word[index-i];
            }
            else{
                answer+=word[i];
            }
        } 
        return answer;
    }
};