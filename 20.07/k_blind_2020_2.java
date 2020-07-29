class Solution {

    public String _solve2(String u, String v)
    {
        String res = "(";
        res = res + _solve(v);
        res = res + ")";

        String tmp = u.substring(1, u.length()-1);
        for(int i=0; i<tmp.length(); i++)
        {
            if(tmp.charAt(i) == '(') res = res + ")";
            else res = res + "(";
        }
        
        return res;
    }

    public boolean _solve3(String s)
    {
        int idx = 0;
        if(s.charAt(0) == ')') return false;
        else
        {
            idx++;
            for(int i=1; i<s.length(); i++)
            {
                if(s.charAt(i) == '(') idx++;
                else idx--;

                if(idx < 0) return false;
            }
        }
        return true;
    }

    public String _solve(String s)
    {
        if(s.length() == 0) return "";

        int tnum = s.length();

        int idx = 0;
        if(s.charAt(0) == '(') idx++;
        else idx--;

        for(int i=1; i<tnum; i++)
        {
            if((s.charAt(i) == '(')) idx++;
            else idx--;

            if(idx == 0)
            {
                idx = i;
                break;
            }
        }

        String u = s.substring(0, idx+1);
        String v = s.substring(idx+1);
        
        System.out.println("u : " + u + "  v : " + v);
        
        int idx2 = 0;
        if(u.charAt(0) == ')')
        {
            return _solve2(u, v);
        }
        else
        {
            idx2 = 1;
            int i;
            for(i=1; i<u.length(); i++)
            {
                if(u.charAt(i) == '(') idx2++;
                else idx2++;

                if(idx2 < 0) break;
            }

            if(i != u.length())
            {
                return _solve2(u, v);
            }
            else
            {
                return u + _solve(v);
            }
        }
    }

    public String solution(String p) {
        String answer = "";

        if(_solve3(p)) answer = p;
        else answer = _solve(p);

        return answer;
    }
}