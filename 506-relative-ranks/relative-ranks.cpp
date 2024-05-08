class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> answer;
        vector<Athlete> list;
        int i=0;
        while(i<score.size()){
            list.push_back(Athlete(score[i],"",i));
            i++;
        }
        sort(list.begin(), list.end(), compareScore);
        i=0;
        while(i<3 && i< score.size()){
            if(i==0)list[i].rank="Gold Medal";
            else if(i==1)list[i].rank="Silver Medal";
            else list[i].rank="Bronze Medal";
            i++;
        }
        while(i<score.size()){
            list[i].rank=to_string(i+1);
            i++;
        }
        sort(list.begin(),list.end(), compareIndex);
        for(i=0;i<list.size();i++){
            answer.push_back(list[i].rank);
        }
        return answer;
    }
    struct Athlete{
        int score;
        string rank;
        int index;
    };
    
    static bool compareScore(Athlete one, Athlete two){
        return one.score>two.score?true:false;
    }
    
    static bool compareIndex(Athlete one, Athlete two){
        return one.index<two.index?true:false;
    }
};