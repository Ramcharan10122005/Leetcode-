class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(auto c:chalk){
            sum+=c;
        }
        while(k>=sum){
            k-=sum;
        }
        for(int i=0;i<chalk.size();i++){
            if(chalk[i]>k)
            return i;
            else
            k-=chalk[i];
        }
        return -1;
    }
};