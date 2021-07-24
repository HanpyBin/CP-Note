class Solution
{
public:
    string maximumTime(string time)
    {
        // 这什么题？？？
        // 避免出现非法时间即可。
        if (time[1] != '?')
        {
            if (time[0] == '?')
            {
                if (time[1] > '3' && time[1] <= '9')
                    time[0] = '1';
                else
                    time[0] = '2';
            }
        }     
        else
        {
            if (time[0] == '?')
            {
                time[0] = '2';
                time[1] = '3';
            }
            else if (time[0] == '2')
                time[1] = '3';
            else
                time[1] = '9';
        }

        // 下面处理分钟
        if (time[3] == '?')
            time[3] = '5';
        if (time[4] == '?')
            time[4] = '9';
        return time;
    }
};