class Solution
{
public:
    string reverseVowels(string s)
    {
        stack<char> st;
        for (const auto& ch: s)
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                st.push(ch);
        for (int i = 0; i < s.length(); i++)
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                char t = st.top();
                st.pop();
                s[i] = t;
            }
        return s;
    }
};