class Solution {
public:
    int strongPasswordChecker(string s) {
        int n=s.size(), miss=3;
        bool a=0,b=0,c=0;

        for(char x:s)
            if(islower(x)) a=1;
            else if(isupper(x)) b=1;
            else if(isdigit(x)) c=1;

        miss=3-(a+b+c);

        int rep=0, one=0, two=0;
        for(int i=0;i<n;) {
            int j=i;
            while(j<n && s[j]==s[i]) j++;
            int len=j-i;

            if(len>=3) {
                rep+=len/3;
                if(len%3==0) one++;
                else if(len%3==1) two++;
            }
            i=j;
        }

        if(n<6) return max(miss,6-n);
        if(n<=20) return max(miss,rep);

        int del=n-20;
        int x=min(del,one);
        rep-=x; del-=x;

        x=min(del,two*2);
        rep-=x/2; del-=x;

        rep-=del/3;

        return n-20+max(miss,rep);
    }
};