class Solution
{
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders)
    {
        map<pair<string, string>, int> m;
        set<string> dish_set;
        set<int> table_set;
        for (const auto & order: orders)
        {
            dish_set.insert(order[2]);
            table_set.insert(stoi(order[1]));
            m[make_pair(order[1], order[2])]++;
        }
        // for (set<string>::iterator it = table_set.begin(); it != table_set.end(); it++)
        //     cout << *it << endl;
        vector<vector<string>> res;
        vector<string> first_row;
        first_row.push_back("Table");
        for (set<string>::iterator it = dish_set.begin(); it != dish_set.end(); it++)
            first_row.push_back(*it);
        res.push_back(first_row);
        for (set<int>::iterator it = table_set.begin(); it != table_set.end(); it++)
        {
            vector<string> temp;
            temp.push_back(to_string(*it));
            for (set<string>::iterator it1 = dish_set.begin(); it1 != dish_set.end(); it1++)
            {
                pair<string, string> t = make_pair(to_string(*it), *it1);
                temp.push_back(to_string(m[t]));
            }
            res.push_back(temp);
        }
        return res;
    }
};