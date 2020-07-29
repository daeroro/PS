class Solution {
    public int solution(String s) {
        int answer = s.length();
        int slen = s.length();
        int hlen = slen / 2;
        int sidx = 0, lidx = 0;

        for(int i=1; i<=hlen; i++)
        {
            //if(slen % i == 0)
            {
                String ans = "";
                String fs = s.substring(0 ,i);
                int tnum = 1;
                lidx = i;
                while(lidx + i<=slen)
                {
                    //System.out.println(lidx);
                    String ss = s.substring(lidx, lidx + i);
                    lidx += i;
                    //System.out.println("fs " + fs);
                    //System.out.println("ss " + ss);
                    if(fs.equals(ss))
                    {
                        tnum++;
                    }
                    else
                    {
                        if(tnum != 1)
                        {
                            String stn = Integer.toString(tnum);
                            ans = ans.concat(stn);
                            //System.out.println("stn " + stn);
                        }
                        ans = ans.concat(fs);
                        //System.out.println("ans " + ans);
                        fs = ss.substring(0);
                        tnum = 1;
                    }
                }
                if(tnum != 1)
                {
                    String stn = Integer.toString(tnum);
                    ans = ans.concat(stn);
                    //System.out.println("stn " + stn);
                }
                ans = ans.concat(fs);
                
                if(lidx < slen) ans = ans.concat(s.substring(lidx));
                
                //System.out.println(ans);
                if(answer > ans.length()) answer = ans.length();
            }
        }

        return answer;
    }
}