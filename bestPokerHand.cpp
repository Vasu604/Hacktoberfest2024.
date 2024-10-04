class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        // check for flush: all suits must same
        bool isFlush = true;
        for(int i = 1; i < suits.size(); i++)
        {
            if(suits[i] != suits[0])
            {
                isFlush = false;
                break;
            }
        }
        if(isFlush)
        {
            return "Flush";
        }
        // count frequency of each rank
        int rank_count[14] = {0}; // there're 13 possible ranks(1to13)
        for(int i = 0; i < ranks.size(); i++)
        {
            rank_count[ranks[i]]++;
        }
        // Determine max frequency of any rank
        int max_count = 0;
        for(int i = 1; i <= 13; i++)
        {
            if(rank_count[i] > max_count)
            {
                max_count = rank_count[i];
            }
        }
        // return based on the max frequency
        if(max_count >= 3)
        {
            return "Three of a Kind";
        }
        else if(max_count == 2)
        {
            return "Pair";
        }
        else
        {
            return "High Card";
        }

    }
};
