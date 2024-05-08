class KthLargest {
    
public:
    priority_queue<int , vector<int> , greater<int>> q ; int k ;
    KthLargest(int c, vector<int>& nums) {
        k = c ;
        for(int i=0 ; i<nums.size() ; i++){
            q.push(nums[i]) ;
        }
    }
    
    int add(int val) {
      q.push(val) ;
       // cout<<k<<endl;
        while(q.size()-k>0){
            q.pop() ;
        }
        return q.top() ;
    }
};