class Solution {
public:
    string intToRoman(int num) {
        const pair<int,string> mpp[]={{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};
        string ans="";
        int ptr=12;
        for(int i=12;~i;--i){
            if(num==0){break;}
            if(num>=mpp[i].first){
                int cnt=num/mpp[i].first;
                num%=(mpp[i].first);
                string roman=mpp[i].second;
                while(cnt--){
                    ans+=roman;
                }
            }
        }
        return ans;
    }
};